#!/usr/bin/python

for den in range(11,100):
	for num in range(11,den):
		for div in range(2,20):
			liste=[num/10,num%10,den/10,den%10]
			numdiv=num/div
			dendiv=den/div
			if dendiv!=0 and float(num)/float(den)==float(numdiv)/float(dendiv) and liste[1]!=0 and ( \
			(liste[0]==liste[2] and liste[1]==numdiv and liste[3]==dendiv) or \
			(liste[0]==liste[3] and liste[1]==numdiv and liste[2]==dendiv) or \
			(liste[1]==liste[2] and liste[0]==numdiv and liste[3]==dendiv) or \
			(liste[1]==liste[3] and liste[0]==numdiv and liste[2]==dendiv)):
				print num,"/",den,":",numdiv,"/",dendiv, " = ",float(num)/float(den),float(num/div)/float(den/div)

#optimierbar: keine casts, statt a/b=c/d -> a*d=c*b
#gleiche ziffern zuerst testen, dann wegstreichen statt mit dem divisor alle durchprobieren

#oder:
#[[(den, num) for num in range(10, den) if (num / 10) * den == (den % 10) * num and num % 10 == den /10] for den in range (10,100)]