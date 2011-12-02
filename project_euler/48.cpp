#include <iostream>
using namespace std;

int main() {
	unsigned long long int sum=0, max=1, cur;
	for(int i=0;i<10;i++)
		max*=10;
	
	for(int i=1;i<=1000;i++) {
		cur = i;
		for(int j=1;j<i;j++) {
			cur*=i;
			while (cur > max) cur-=max;
		}
		sum+=cur;
		while (sum > max) sum-=max;
	}
	cout << sum;
}
