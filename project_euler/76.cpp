#include <iostream>
using namespace std;

const int nmax=2;

int calc(int num, int cur, int psb) {
	if (cur==nmax)
		return psb+1;
	
	if (num<nmax) {
		for(int i=0;i<=nmax;i+=num)
			calc(num+1, cur+i*num);
	}
	else {
		for(int i=0;i<=nmax;i+=num)
			calc(num+1);
	}
	
	return psb+1;
}

int main() {
	cout << calc(1,0);
}
