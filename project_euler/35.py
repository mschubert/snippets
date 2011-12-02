#!/usr/bin/python

from sets import Set

def rotate(seq):
	if len(seq)==1: return [seq]
	new=[seq]
	for i in range(1,len(seq)):
		old=new[-1]
		new.append(old[1:]+[old[0]])
	return new

max=1000000
pnum=[x for x in range(0,max)]
prime=[]
for i in range(2,max):
	if pnum[i]!=0:
		prime.append(i)
		for j in range(2*i,max,i): pnum[j]=0

#print prime

s=Set()
for p in prime:
	st=str(p)
	clist=[]
	for c in st: clist.append(c)
	clist=rotate(clist)
	allprimes=True
	for pc in clist:
		num=""
		for digit in pc:
			num+=digit
		if pnum[int(num)]==0:
			allprimes=False
			continue
	if allprimes:
	#	print num,
		s.add(num)
	
print "\n", len(s)