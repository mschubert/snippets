#!/usr/bin/python

max=100

n=[-1 for i in range(1,max)]
for i in range(1,max):
	queue=[]
	while n[i]==-1:
		n[i]=0
		n=sum([ord(c)-ord('0') for c in str(n)]!)
		queue.append(n)
	queue=queue[::-1]
	for q in queue:
		n[q]=index(q)

erg=0
for n in num:
	if n==60: erg++
print erg
