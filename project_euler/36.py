#!/usr/bin/python

summe=0

for i in range(1,1000000,2):
	s10=str(i)

	if s10==s10[::-1]:	
		b=i
		bdigits=0
		while b!=0:
			b/=2
			bdigits+=1
		
		s2="".join([str((i >> shift) & 1) for shift in range(bdigits-1, -1, -1)])
		if s2==s2[::-1]:
			summe+=i

print summe