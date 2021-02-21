import matplotlib.pyplot as pyplot
import numpy as np
import os

data = np.genfromtxt("SvET.txt", delimiter=",", names=["x", "y"])

pyplot.xlabel("Size")
pyplot.ylabel("Execution Time (s)")
pyplot.plot(data['x'], data['y'])
pyplot.savefig('svet.png',bbox_inches='tight')


data1 = np.genfromtxt("SvNoC.txt", delimiter=",", names=["X", "Y"])

pyplot.xlabel("Size")
pyplot.ylabel("Number of Comparisons")
pyplot.plot(data1['X'], data1['Y'])
pyplot.savefig('svnoc.png',bbox_inches='tight')
