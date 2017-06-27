"""
A very short code comparing the output of fmath and cmath exp() functions.
"""
import numpy as np
import ctypes
import matplotlib.pyplot as plt
plt.rc("text", usetex=True)
plt.rc("font", size=20)

lib = ctypes.cdll.LoadLibrary("comp.so")
fexpf = lib.fexpf
cexpf = lib.cexpf
fexpf.argtypes = (ctypes.c_float,)
cexpf.argtypes = (ctypes.c_float,)
fexpf.restype  = (ctypes.c_float)
cexpf.restype  = (ctypes.c_float)

fexpd = lib.fexpd
cexpd = lib.cexpd
fexpd.argtypes = (ctypes.c_double,)
cexpd.argtypes = (ctypes.c_double,)
fexpd.restype  = (ctypes.c_float)
cexpd.restype  = (ctypes.c_float)


x = np.logspace(-5,1.8,1000)
f = []
c = []
fd = []
cd = []
for xi in x:
    fi = fexpf(xi)
    ci = cexpf(xi)  
    fdi = fexpd(xi)
    cdi = cexpd(xi)  
    f.append(fi)
    c.append(ci)
    fd.append(fdi)
    cd.append(cdi)
    print xi, fi, ci, fdi, cdi

f = np.array(f)
c = np.array(c)
fd = np.array(fd)
cd = np.array(cd)

plt.loglog(x, np.fabs(f-c)/c, label="float")
#plt.loglog(x, np.fabs(fd-cd)/cd, label="double")
#plt.xscale('log')
plt.xlabel(r"$x$")
plt.ylabel(r"$\%\ {\rm Diff}$")
plt.subplots_adjust(bottom=0.15, left=0.15)
plt.legend()
plt.show()
