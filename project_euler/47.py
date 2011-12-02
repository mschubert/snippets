#!/usr/bin/python

from math import *

def merge(seq):
	merged = []
	for s in seq:
		for x in s:
			merged.append(x)
	return merged

max=200000
pnum=[x for x in range(0,max)]
prime=[]
for i in range(2,max):
	if pnum[i]!=0:
		prime.append(i)
		for j in range(2*i,max,i): pnum[j]=0

pnum=[[] for x in range(0,max)]
for p in prime:
	for it in range(p,max,p):
		pnum[it].append(p)
	for pot in range(2,int(log(max)/log(p))+1):
		ppot=p**pot
		for it in range(ppot,max,ppot):
			pnum[it][-1]=ppot

pm3=pnum[0]
pm2=pnum[1]
pm1=pnum[2]
for i in range(3,max):
	p=pnum[i]
	if 4==len(p)==len(pm3)==len(pm2)==len(pm1):
		if len(set(merge([p,pm3,pm2,pm1])))==16:
			print pm3,pm2,pm1,p,"bei iterator",i-3
			break
	pm3,pm2,pm1=pm2,pm1,p


#max=1000000
#n_factor = [0]*max
#for i in range(2,max): 
#	if n_factor[i] == 0 :
#		for j in range(2*i,max,i):
#		n_factor[j] += 1
#goal = [4]*4
#for i in range(2,max):
#	if n_factor[i:i+4] == goal:
#		print i
#		break