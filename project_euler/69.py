#!/usr/bin/python

max=1000000
pnum=[x for x in range(0,max)]
prime=[]
for i in range(2,max):
	if pnum[i]!=0:
		prime.append(i)
		for j in range(2*i,max,i): pnum[j]=0

pnum=[[] for x in range(0,max)]
for p in prime:
	for j in range(p, max, p):
		pnum[j].append(p)

for x in range(2,len(pnum)):
	list=pnum[x]
	prod=1
	for p in [1-1./list[i] for i in range(0,len(list))]: prod*=p
	pnum[x]=1/prod

max=0
maxi=0
for x in range(2,len(pnum)):
	if pnum[x]>max: max,maxi=pnum[x],x
print maxi

#2*3*5*7*11*13*17 = 510510
