#!/usr/bin/python

max=10000
pnum=[x for x in range(0,max)]
prime=[]
for i in range(2,max):
	if pnum[i]!=0:
		if i>1000: prime.append(i)
		for j in range(2*i,max,i): pnum[j]=0

length=len(prime)
found=0
for i in range(0,length):
	spi=set(str(prime[i]))
	for j in range(i+1,length):
		diff=prime[j]-prime[i]
		if i+2*diff>max: break
		spj=set(str(prime[j]))
		if spi==spj and prime[i]+2*diff in prime and spi==set(str(prime[i]+2*diff)):
			print prime[i], prime[j], prime[i]+2*diff
			found+=1
			if found==2: exit()