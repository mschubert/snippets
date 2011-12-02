#include <iostream>
using namespace std;

int main() {
	const unsigned int limit = 120000;
	unsigned int numbers[limit];
	for(unsigned int i=0;i<limit;i++)
		numbers[i] = i+1;
	
	for(unsigned int i=2;i<=limit;i++)
		if (numbers[i-1] != 0)
			for(unsigned int j=2*i;j<=limit;j+=i)
				numbers[j-1] = 0;
	
	int nmax=0, idxa, idxb;
	for(int a=-999;a<1000;a++)
		for(int b=-999;b<1000;b++) {
			int n=0;
			while(numbers[n*n+a*n+b-1] != 0)
				n++;
			
			if (n>nmax) {
				nmax=n;
				idxa=a;
				idxb=b;
			}
		}
		
	cout << "n^2 + n*" << idxa << " + " << idxb << " => " << nmax << " primes (a*b=" << idxa*idxb << ")";
}
