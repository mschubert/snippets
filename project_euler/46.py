#!/usr/bin/python

max=10000
pnum=[x for x in range(0,max)]
prime=[1]
for i in range(2,max):
	if pnum[i]!=0:
		prime.append(i)
		for j in range(2*i,max,i): pnum[j]=0

square=[2*x*x for x in range(1,int(max**0.5))]
test=[2*x+1 for x in range(0,max/2)]

for p in prime:
	for s in square:
		query=p+s
		if query<max: test[(query-1)/2]=0

for n in test:
	if n!=0 and n not in prime:
		print n
		break

#! /usr/bin/python
#n = 3
#primes = set()
#while True :
#	if all( n % p for p in primes ) :
#		primes.add( n )
#	else :
#		if not any( (n-2*i*i) in primes for i in xrange( 1, n ) ) :
#			break
#	n += 2
#print n
