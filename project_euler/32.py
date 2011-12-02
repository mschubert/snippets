#!/usr/bin/python

def pandigital(s): # besser: return len(nstr)==9 and set(nstr)==set("123456789")
	if len(s)!=9: return False
	
	schalter=[0,0,0,0,0,0,0,0,0,0]
	
	for c in s:
		i=ord(c)-ord('0')-1
		schalter[i]=1
	
	if schalter[0]==1 and schalter[1]==1 and schalter[2]==1 and schalter[3]==1 and schalter[4]==1 and schalter[5]==1 and schalter[6]==1 and schalter[7]==1 and schalter[8]==1:
		print s
		return True
	else:
		return False
	
	#	for i in range(0,8):
	#		if schalter[i]!=1: return False

erg=set()
for i in range(1,1000):
	for j in range(i,1000):
		e=i*j
		s=str(i)+str(j)+str(e)
		if pandigital(s): # if "".join(sorted(s))=="123456789":
			erg.add(e)
		j+=1
	i+=1

print sum(erg)
