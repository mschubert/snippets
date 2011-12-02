#include <iostream>
using namespace std;

int main() {
	int num[500];
	num[0] = 1;
	for(int i=1;i<500;i++)
		num[i] = 0;
	int size = 1;
	int multiplicator = 1;

	for(int i=0;i<100;i++) {
		int remainder = 0;
		for(int pos=0;pos<size;pos++) {
			int erg = num[pos]*multiplicator + remainder;
			num[pos] = erg%10;
			remainder = (erg-num[pos])/10;
		}
		while (remainder) {
			num[size++] += remainder%10;
			remainder/=10;
		}
		multiplicator++;
	}

	int sum=0;
	for(int j=0;j<size;j++)
		sum+=num[j];
	cout << sum << endl;
}
