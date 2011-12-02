#include <iostream>
using namespace std;

int main() {
	int sum=0,maxit=1,digits=9;
	int num[] = {0,1,0,0,0,0,0,0,0};
	int it=0;
	
	while(1) {
		if (num[it]!=9) {
			num[it]++;
			it=0;
		}
		else {
			num[it]=0;
			if (++it==digits) break;
			if (it>maxit) maxit=it;
			continue;
		}
		
		if (num[0]==0) continue;
		
		int rem=0,rev=1;
		for(int i=0;i<=maxit;i++) {
			int cur=num[i]+num[maxit-i]+rem;
			if ((cur&1)==0) {
				rev=0;
				break;
			}
			rem=0;
			if (cur>9) rem++;
		}
		if (rev) { sum++; }
	}
	cout << sum;
}
