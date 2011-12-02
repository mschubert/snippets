#!/usr/bin/python

count=0
for i in range(100,10000):
	test=str(i)
	lychrel=True
	for j in range(1,50):
		step=str(int(test)+int(test[::-1]))
		if step==step[::-1]: # no lychrel number
			lychrel=False
			break
		else: test=step
	if lychrel==True: count+=1

print count

#def isLychrel(n):
#	for i in range(0,50):
#		n = n+int(str(n)[::-1])
#		if str(n)==str(n)[::-1]: return 0
#	return 1
#print sum(isLychrel(n) for n in range(100,10000))