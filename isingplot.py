import matplotlib.pyplot as plt
import numpy as np
import os
result=[]
if os.path.exists('dataIsing'):
    fileOb=open('dataIsing')
    for line in fileOb:
        result.append(list(map(float,line.split(' '))))
    length=len(result)
    T = np.zeros(length)
    M = np.zeros(length)
    for i in range(length):
        T[i]=result[i][0];
        M[i]=(result[i][1]);
    plt.plot(T,(M))
    plt.axis([0,80,-0.7,1.2])  
    result=[]
if os.path.exists('dataMagnet'):
    plt.figure()
    fileOb=open('dataMagnet')
    for line in fileOb:
        result.append(list(map(float,line.split(' '))))
    length=len(result)
    H = np.zeros(length)
    M = np.zeros(length)
    for i in range(length):
        H[i]=result[i][0];
        M[i]=(result[i][1]);
    plt.plot(H,M)
    plt.axis([-1.8e-22,1.8e-22,-1.2,1.2])
plt.show()

