#!/usr/bin/python

n,nbouncy=100,0

while True:
	inc,dec=False,False
	st=str(n)
	for i in range(1,len(st)):
		if st[i-1]<st[i]:
			inc=True
			if dec==True: break
		if st[i-1]>st[i]: 
			dec=True
			if inc==True: break
	if inc and dec:
		nbouncy+=1
#		print n,
	if nbouncy*100==n*99: break
	n+=1

print n,"(",nbouncy,")"