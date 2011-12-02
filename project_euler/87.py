#!/usr/bin/python

max=50000000

pmax=int(max**0.5)
pnum=[x for x in range(0,pmax)]
primes=[]
for i in range(2,pmax):
	if pnum[i]!=0:
		primes.append(i)
		for j in range(2*i,pmax,i): pnum[j]=0

e2=[e**2 for e in primes if e**2<max]
e3=[e**3 for e in primes if e**3<max]
e4=[e**2 for e in e2 if e**2<max]

query=[False for x in range(0,max)]
for i in e4:
	for j in e3:
		if i+j>max: break
		for k in e2: # e2 innen: effizientere abbruchbedingung
			t=i+j+k
			if t>=max: break
			query[t]=True # besser: liste

print sum(query)