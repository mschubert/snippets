#include <iostream>
using namespace std;

int main() {
	unsigned int sum=0, n1, n2=0;
//	int p[] = { 0, 1, 16, 81, 256, 625, 1296, 2401, 4096, 6561 };
	int p[] = { 0, 1, 32, 243, 1024, 3125, 7776, 16807, 32768, 59049 };
	for(int i=0;i<3;i++)
		for(int j=0;j<10;j++)
			for(int k=0;k<10;k++)
				for(int l=0;l<10;l++)
					for(int m=0;m<10;m++)
						for(int n=0;n<10;n++) {
							n1 = p[i]+p[j]+p[k]+p[l]+p[m]+p[n];
							if (n1==n2++ && n1>2) {
								sum+=n1;
							//	cout << n1 << endl;
							}
						}
	cout << sum;
}
