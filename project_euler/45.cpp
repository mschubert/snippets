#include <iostream>
#include <cmath>
using namespace std;
typedef unsigned long long int ulongint;

int main() {
	for(ulongint hex=144;;hex++) {
		ulongint n=hex*(2*hex-1);
		ulongint pen=static_cast<ulongint>(round(sqrt(48*hex*hex-24*hex+1)+1)/6);
		if (n==pen*(3*pen-1)/2) {
			cout <<pen<<" " << hex <<":" <<n;
			break;
		}
	}
}

/*

int main() {
	for(ulongint hex=144;;hex++) {
		ulongint n=hex*(2*hex-1);
		ulongint pen=static_cast<ulongint>(round(sqrt(48*hex*hex-24*hex+1)+1)/6);
		ulongint tri=static_cast<ulongint>(round(sqrt(8*hex*(2*hex-1)+1)-1)/2);
		if (n==pen*(3*pen-1)/2 && pen*(3*pen-1)/2 == tri*(tri+1)/2) {
			cout << tri << " "<<pen<<" " << hex <<":" <<n;
			break;
		}
	}
}


even better:
No multiplications, divisions or square roots needed, just take the smallest of the
three numbers and take the next one of its sequence. Continue until all are equal. 

long p=5, pi=7;
long h=6, hi=9;
int amountFound = 0;
while(amountFound <=1){
	if(p<=h){
		p+=pi; pi+=3;
	}else {
		h+=hi; hi+=4;
	}
	if(p==h)
		amountFound++;
}

*/
