#!/usr/bin/python

mult3=[str('%(#)03d'%{"#":3*x}) for x in range(3,334) if len(set(str('%(#)03d'%{"#":3*x})))==3]
mult5=[str('%(#)03d'%{"#":5*x}) for x in range(2,200) if len(set(str('%(#)03d'%{"#":5*x})))==3]
mult11=[str('%(#)03d'%{"#":11*x}) for x in range(1,91) if len(set(str('%(#)03d'%{"#":11*x})))==3]
mult13=[str('%(#)03d'%{"#":13*x}) for x in range(1,77) if len(set(str('%(#)03d'%{"#":13*x})))==3]

sum=0
for d890 in [17*x for x in range(6,59)]:
	s890=str(d890)
	if len(set(s890))==3:
		for d567 in [7*x for x in range(15,143)]:
			s567890=str(d567)+s890
			if len(set(s567890))==6 and s567890[2:5] in mult13 and s567890[1:4] in mult11:
				for d234 in [2*x for x in range(51,500)]:
					s234567890=str(d234)+s567890
					if len(set(s234567890))==9 and s234567890[2:5] in mult5 and s234567890[1:4] in mult3:
						schalter=[0,1,2,3,4,5,6,7,8,9]
						for char in s234567890:
							schalter[int(char)]=0
						x=0
						for n in schalter: x+=n
						sum+=int(str(x)+s234567890)

print sum

