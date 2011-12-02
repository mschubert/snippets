#include <iostream>
using namespace std;

int main() {
	unsigned long long int p[10000];
	bool *b=new bool[1000000000];
	for(int i=1;i<1000000000;i++) {
		p[i]=i*(3*i-1)/2;
		b[p[i]]=true;
	}

	unsigned long long int min=0xffffffff;
	for(int i=1;i<10000;i++)
		for(int j=1;j<i;j++) {
			unsigned long long int diff=p[i]-p[j];
			unsigned long long int sum=p[i]+p[j];
			if (b[diff] && b[sum] && diff<min)
				min=diff;
		}

	cout << min;
}
