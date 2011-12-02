#!/usr/bin/python

def pandigital(nstr):
	return len(nstr)==9 and set(nstr)==set("123456789")

kand=[0]
for i in range(9213,9487): # euler-hp: 4+5digits weil>918..; selbst: 1...10k
	cctd=i
	test=i
	for mult in range(2,1000):
		add=mult*test
		length=len(str(add))
		cctd*=10**length
		cctd+=add
		if cctd>=1000000000: break
		if cctd>=100000000 and pandigital(str(cctd)): kand.append(cctd)

sort=sorted(kand)
print len(sort)-1, "kandidaten"
print sort[len(kand)-1]

#def sort(l): l.sort(); return l
#filter( lambda z: sort([z[c] for c in xrange(9)]) == [str(i) for i in xrange(1,10)],[(str(j)+str(2*j)) for j in xrange(9876,9234,-1)])[0]