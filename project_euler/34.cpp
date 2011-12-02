#include <iostream>
using namespace std;

int main() {
	unsigned int sum=0, n1, n2=0;
	int p[] = { 1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880 };
	for(int i=0;i<3;i++)
		for(int j=0;j<3;j++)
			for(int k=0;k<10;k++)
				for(int l=0;l<10;l++)
					for(int m=0;m<10;m++)
						for(int n=0;n<10;n++) {
							for(int o=0;o<10;o++) {
								if (i>0) n1 = p[i]+p[j]+p[k]+p[l]+p[m]+p[n]+p[o];
								else if (j>0) n1 = p[j]+p[k]+p[l]+p[m]+p[n]+p[o];
								else if (k>0) n1 = p[k]+p[l]+p[m]+p[n]+p[o];
								else if (l>0) n1 = p[l]+p[m]+p[n]+p[o];
								else if (m>0) n1 = p[m]+p[n]+p[o];
								else if (n>0) n1 = p[n]+p[o];
								else if (o>0) n1 = p[o];
								
								if (n1==n2++ && n1>2) {
									sum+=n1;
									cout << n1 << endl;
								}
							}
						}
	cout << endl << sum;
}
