from mpl_toolkits.mplot3d import Axes3D
import matplotlib.pyplot as plt
from matplotlib import cm
from matplotlib.ticker import LinearLocator, FormatStrFormatter
import numpy as np
prenombre="frontera_fija"
f=open("pde_datosA.dat","r")
n=int(f.readline().strip())
for k in range(1,6):
    fig = plt.figure()
    ax = fig.gca(projection='3d')
    x=[]
    y=[]
    T=[]
    for i in range(n):
        x.append([])
        for j in range(n):
            x[-1].append(float(f.readline().strip()))
    for i in range(n):
        y.append([])
        for j in range(n):
            y[-1].append(float(f.readline().strip()))
    for i in range(n):
        T.append([])
        for j in range(n):
            T[-1].append(float(f.readline().strip()))
    T=np.array(T)
    y=np.array(y)
    x=np.array(x)
    surf = ax.plot_surface(x, y, T, cmap=cm.jet,linewidth=0, antialiased=False)
    ax.zaxis.set_major_locator(LinearLocator(10))
    ax.zaxis.set_major_formatter(FormatStrFormatter('%.02f'))
    fig.colorbar(surf, shrink=0.5, aspect=10)
    if k==5:
        plt.savefig(prenombre+"_promedio"+".pdf")
    else:
        plt.savefig(prenombre+str(k)+".pdf")
prenombre="frontera_abierta"
f=open("pde_datosB.dat","r")
n=int(f.readline().strip())
for k in range(1,6):
    fig = plt.figure()
    ax = fig.gca(projection='3d')
    x=[]
    y=[]
    T=[]
    for i in range(n):
        x.append([])
        for j in range(n):
            x[-1].append(float(f.readline().strip()))
    for i in range(n):
        y.append([])
        for j in range(n):
            y[-1].append(float(f.readline().strip()))
    for i in range(n):
        T.append([])
        for j in range(n):
            T[-1].append(float(f.readline().strip()))
    T=np.array(T)
    y=np.array(y)
    x=np.array(x)
    surf = ax.plot_surface(x, y, T, cmap=cm.jet,linewidth=0, antialiased=False)
    ax.zaxis.set_major_locator(LinearLocator(10))
    ax.zaxis.set_major_formatter(FormatStrFormatter('%.02f'))
    fig.colorbar(surf, shrink=0.5, aspect=10)
    if k==5:
        plt.savefig(prenombre+"_promedio"+".pdf")
    else:
        plt.savefig(prenombre+str(k)+".pdf")
prenombre="frontera_periodica"
f=open("pde_datosC.dat","r")
n=int(f.readline().strip())
for k in range(1,6):
    fig = plt.figure()
    ax = fig.gca(projection='3d')
    x=[]
    y=[]
    T=[]
    for i in range(n):
        x.append([])
        for j in range(n):
            x[-1].append(float(f.readline().strip()))
    for i in range(n):
        y.append([])
        for j in range(n):
            y[-1].append(float(f.readline().strip()))
    for i in range(n):
        T.append([])
        for j in range(n):
            T[-1].append(float(f.readline().strip()))
    T=np.array(T)
    y=np.array(y)
    x=np.array(x)
    surf = ax.plot_surface(x, y, T, cmap=cm.jet,linewidth=0, antialiased=False)
    ax.zaxis.set_major_locator(LinearLocator(10))
    ax.zaxis.set_major_formatter(FormatStrFormatter('%.02f'))
    fig.colorbar(surf, shrink=0.5, aspect=10)
    if k==5:
        plt.savefig(prenombre+"_promedio"+".pdf")
    else:
        plt.savefig(prenombre+str(k)+".pdf")
