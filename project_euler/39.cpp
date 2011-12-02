#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int maxcount=0, maxidx=0;
	for(int i=0;i<1000;i++) {
		int max=i/2, count=0;
		for(int a=20;a<max;a++)
			for(int b=a;b<max;b++) {
				float c=sqrtf(a*a+b*b);
				if (a+b+c==i)
					count++;
			}

		if (count > maxcount) {
			maxcount = count;
			maxidx=i;
		}
	}
	cout << maxidx;
}
