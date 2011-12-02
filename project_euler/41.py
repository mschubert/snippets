#!/usr/bin/python

import string

def permutate(seq):
	if not seq:
		return [seq]
	else:
		temp = []
		for k in range(len(seq)):
			part = seq[:k] + seq[k+1:]
			for m in permutate(part):
				temp.append(seq[k:k+1] + m)
		return temp

def isprime(n):
	n = abs(int(n))
	if not n & 1: 
		return False
	for x in range(3, int(n**0.5)+1, 2):
		if n % x == 0:
			return False
	return True

max=0
for ndigits in range(8,4,-1): # max 1-7 weil 1..8,9%3==0
	digits=[x for x in range(1,ndigits)]
	pnum=permutate(digits)
	for ele in pnum:
		num=0
		for p in range(0,len(ele)):
			num+=ele[p]*10**p
		if isprime(num) and num>max:
			max=num

print max

#def permutate(s):
#	if len(s) == 1: yield s
#	for d in sorted(s, reverse=True):
#		for p in permutate(s.replace(d, '')):
#			yield d + p