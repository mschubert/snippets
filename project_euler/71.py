#!/usr/bin/python

class Fraction:
	def __init__(self, num, den):
		self.n=num
		self.d=den
		self.v=float(num)/den
	def fcomp(x, y):
		if x.v>y.v: return 1
		elif x.v<y.v: return -1
		else: return 0

flist=[Fraction(3,7)]
for d in range(999990, 1000001):
	for n in range(427000,429000):
		diff=3./7-float(n)/d
		if diff<0.0000004 and diff>0: flist.append(Fraction(n,d))

flist.sort(Fraction.fcomp)
for f in flist:
	print f.n,"/",f.d,"=",f.v


