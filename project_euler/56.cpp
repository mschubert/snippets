#include <iostream>
using namespace std;

int main() {
	long maxsum=0;
	
	for(int a=1;a<100;a++) {
		for(int b=1;b<100;b++) {
			int num[500];
			num[0] = 1;
			for(int i=1;i<500;i++)
				num[i] = 0;
			int size = 1;
			for(int i=0;i<b;i++) {
				int remainder = 0;
				for(int pos=0;pos<size;pos++) {
					int erg = num[pos]*a + remainder;
					num[pos] = erg%10;
					remainder = (erg-num[pos])/10;
				}
				while (remainder) {
					num[size++] += remainder%10;
					remainder/=10;
				}
			}
			
			int sum=0;
			for(int j=0;j<size;j++)
				sum+=num[j];
			if (sum>maxsum)
				maxsum=sum;
		}
	}
	
	cout << endl << maxsum;
}
