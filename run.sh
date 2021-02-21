# gcc -std=gnu++11 *.c
CFLAGS+=-Wl,--stack,10485760 gcc *.c 
# ./a.out > outputs/out.txt 
./a.out
