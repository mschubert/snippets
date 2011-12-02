#!/usr/bin/python

from math import log10

min,max=345,10000
cubes=[x**3 for x in range(min,max)]
sets=[sorted(str(x)) for x in cubes]
lens=[int(log10(x)) for x in cubes] # not len(sets) because digits may occur twice

for i in range(0,max-min):
	curlen, j, found=lens[i], i+1, 1
	while j<max-min and lens[j]==curlen:
		if sets[i]==sets[j]:
		#	print "checking", cubes[i],"found",cubes[j], "(",j+min,"^3)"
			found+=1
		if found==5:
			print cubes[i], "(",i+min,"^3)"
			exit()
		j+=1

#cubes = [sorted(str(x**3)) for x in range(10000)]
#counts = [cubes.count(x) for x in cubes]
#print counts.index(5)**3

#cubes = {}
#for i in xrange(1,n):
#	k = i**3
#	key = ''.join(sorted(str(k)))
#	cubes[key] = cubes.get(key,[]) + [k]
#print min([x[0] for x in cubes.values() if len(x) == 5])