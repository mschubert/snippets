#!/usr/bin/python

cnt,num,den=0,2,3
for i in range(1,1000):
	den,num=num+den, 2*den+num
	if len(str(num))>len(str(den)): cnt+=1

print cnt