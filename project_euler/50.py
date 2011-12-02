#!/usr/bin/python

max=1000000
pnum=[x for x in range(0,max)]
prime=[]
for i in range(2,max):
	if pnum[i]!=0:
		prime.append(i)
		for j in range(2*i,max,i): pnum[j]=0

nsummax=1
theprime=2

for start in range(0,len(prime)):
	sum=0
	nsum=0
	for add in range(start,len(prime)):
		sum+=prime[add]
		nsum+=1
		if sum<max and pnum[sum]!=0 and nsum>nsummax: #is prime
			nsummax=nsum
			theprime=sum

print nsummax, theprime