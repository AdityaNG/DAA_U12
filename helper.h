#include <ctype.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Change these typedefs for your local flavor of 128-bit integer types */
typedef __int128_t i128;
typedef __uint128_t u128;

static int strdigit__(char c) {
    /* This is ASCII / UTF-8 specific, would not work for EBCDIC */
    return (c >= '0' && c <= '9') ? c - '0'
        :  (c >= 'a' && c <= 'z') ? c - 'a' + 10
        :  (c >= 'A' && c <= 'Z') ? c - 'A' + 10
        :  255;
}

static u128 strtou128__(const char *p, char **endp, int base) {
    u128 v = 0;
    int digit;

    if (base == 0) {    /* handle octal and hexadecimal syntax */
        base = 10;
        if (*p == '0') {
            base = 8;
            if ((p[1] == 'x' || p[1] == 'X') && strdigit__(p[2]) < 16) {
                p += 2;
                base = 16;
            }
        }
    }
    if (base < 2 || base > 36) {
        errno = EINVAL;
    } else
    if ((digit = strdigit__(*p)) < base) {
        v = digit;
        /* convert to unsigned 128 bit with overflow control */
        while ((digit = strdigit__(*++p)) < base) {
            u128 v0 = v;
            v = v * base + digit;
            if (v < v0) {
                v = ~(u128)0;
                errno = ERANGE;
            }
        }
        if (endp) {
            *endp = (char *)p;
        }
    }
    return v;
}

u128 strtou128(const char *p, char **endp, int base) {
    if (endp) {
        *endp = (char *)p;
    }
    while (isspace((unsigned char)*p)) {
        p++;
    }
    if (*p == '-') {
        p++;
        return -strtou128__(p, endp, base);
    } else {
        if (*p == '+')
            p++;
        return strtou128__(p, endp, base);
    }
}

i128 strtoi128(const char *p, char **endp, int base) {
    u128 v;

    if (endp) {
        *endp = (char *)p;
    }
    while (isspace((unsigned char)*p)) {
        p++;
    }
    if (*p == '-') {
        p++;
        v = strtou128__(p, endp, base);
        if (v >= (u128)1 << 127) {
            if (v > (u128)1 << 127)
                errno = ERANGE;
            return -(i128)(((u128)1 << 127) - 1) - 1;
        }
        return -(i128)v;
    } else {
        if (*p == '+')
            p++;
        v = strtou128__(p, endp, base);
        if (v >= (u128)1 << 127) {
            errno = ERANGE;
            return (i128)(((u128)1 << 127) - 1);
        }
        return (i128)v;
    }
}

i128 atoi128(const char *p) {
    return strtoi128(p, (char**)NULL, 10);
}

char *utoa128(char *dest, u128 v, int base) {
    char buf[129];
    char *p = buf + 128;
    const char *digits = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    *p = '\0';
    if (base >= 2 && base <= 36) {
        while (v > (unsigned)base - 1) {
            *--p = digits[v % base];
            v /= base;
        }
        *--p = digits[v];
    }
    return strcpy(dest, p);
}

char *itoa128(char *buf, i128 v, int base) {
    char *p = buf;
    u128 uv = (u128)v;
    if (v < 0) {
        *p++ = '-';
        uv = -uv;
    }
    if (base == 10)
        utoa128(p, uv, 10);
    else
    if (base == 16)
        utoa128(p, uv, 16);
    else
        utoa128(p, uv, base);
    return buf;
}

static char *perrno(char *buf, int err) {
    switch (err) {
    case EINVAL:
        return strcpy(buf, "EINVAL");
    case ERANGE:
        return strcpy(buf, "ERANGE");
    default:
        sprintf(buf, "%d", err);
        return buf;
    }
}


/* Function to print an array */
void printArray(__uint128_t arr[], __uint128_t size) 
{ 
    __uint128_t i; 
    char buf[64];
    for (i=0; i < size; i++) { 
	itoa128(buf, arr[i], 10);
        printf("%s ", buf);
    }
    printf("\n"); 
}
