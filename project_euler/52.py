#!/usr/bin/python

o6=ord('6')
for i in range(125874,10000000):
	si=str(i)
	if si[0]!='1' or ord(si[1])>o6:
		print si[0]
		continue
	i2=i*2
	if set(str(i2))!=set(si): continue
	i3=i+i2
	if set(str(i3))!=set(si): continue
	i4=i2<<1
	if set(str(i4))!=set(si): continue
	i5=i2+i3
	if set(str(i5))!=set(si): continue
	i6=i3<<1
	if set(str(i6))!=set(si): continue
	print i
	break

#def f(n): return sorted([int(n) for n in str(n)])
#[n for n in range(1,1000000) if f(n)==f(n*2)==f(n*3)==f(n*4)==f(n*5)==f(n*6)]
