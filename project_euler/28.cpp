#include <iostream>
using namespace std;

int main() {
	int sum=1,n=1;
	for(int size=2;size<1001;size+=2)
		for(int i=0;i<4;i++) {
			n+=size;
			sum+=n;
		}

	cout << sum;
}
