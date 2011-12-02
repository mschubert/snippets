#include <iostream>
using namespace std;

int main() {
	unsigned long long int number=0;
	unsigned long long int max = 300000000;
	
	for(unsigned long long int i=1;number<max;i++) {
		number += i;
		int pfactors=0;
		
		unsigned long long int pnum = number;
		for(unsigned int p=2;p<=pnum;p++) {
			if (pnum%p == 0) {
				pnum /= p;
				pfactors++;
				p--;
			}
		}
		
		if(pfactors>=9) {
			int ndiv=0;
			for(unsigned long long int i=1;i<=number;i++)
				if (number%i==0)
					ndiv++;
			
			if (ndiv > 500) {
				cout << number;
				break;
			}
		}
	}
}
