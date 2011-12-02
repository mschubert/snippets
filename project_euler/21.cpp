#include <iostream>
using namespace std;

int main() {
	int *sumd = new int[10000];
	
	for(int i=0;i<10000;i++) {
		int cursumd = 1;
		for(int j=2;j<i;j++) {
			if (i%j==0)
				cursumd+=j;
		}
		sumd[i] = cursumd;
	}
	
	int sum=0;
	for(int i=2;i<10000;i++)
		if (sumd[sumd[i]] == i && sumd[i] != i)
			sum+=i;
	
	cout << sum << endl;
	delete[] sumd;
}
