#!/usr/bin/python

sum=0
for i in range(1,25):#1,25
	n=0
	e=n**i
	digits=len(str(e))
	while digits<=i:
		n+=1
		e=n**i
		digits=len(str(e))
		if digits==i:
			sum+=1

print sum