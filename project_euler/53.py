#!/usr/bin/python

cnt=0
alt=[1]
for i in range(1,101):
	neu=[1]
	for j in range(1,len(alt)):
		neu.append(alt[j-1]+alt[j])
		if neu[-1]>1000000: cnt+=1
	neu.append(1)
	alt=neu

print cnt