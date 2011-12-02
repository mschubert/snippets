#include <iostream>
#include <iomanip>
using namespace std;

int main() {
	const int prc=1000;
	int max=0,idx=0;

	for(int divisor=3;divisor<1000;divisor++) {
		int *array = new int[prc];
		int dividend=10, neu;
		for(int j=0;j<prc;j++) {
			while((neu=dividend/divisor)==0)
				dividend*=10;
			dividend-=neu*divisor;
			if (dividend==0)
				break;
			array[j]=neu;
		}
		if (dividend==0)
			continue;
		
	/*	cout << setw(3) << divisor << ": ";
		for(int j=0;j<prc;j++)
			cout << array[j];
		cout << endl;
	*/	
		int s=5;
		int a=array[s++], b=array[s++], c=array[s++], d=array[s++], e=array[s];
		for(int i=6;i<prc;i++)
			if (a==array[i])
				if (b==array[i+1])
					if (c==array[i+2])
						if (d==array[i+3])
							if (e==array[i+4]) {
								if (i-5>max) {
									max=i-5;
									idx=divisor;
								}
								cout << divisor << ": " << i-5 << endl;
								break;
							}
	}
	cout << idx << " (" << max << ")";
}
