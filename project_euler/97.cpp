#include <iostream>
using namespace std;

int main() {
	unsigned long long int sum=1, max=1;
	for(int i=0;i<10;i++)
		max*=10;
	for(int i=0;i<7830457;i++) {
		sum*=2;
		while (sum > max) sum-=max;
	}
	cout << sum*28433+1;
}
