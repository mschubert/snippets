#include <iostream>
#include <math.h>
using namespace std;

int main() {
	for(int c=415;c<1000;c++) {
		float erg =  (1000 - c + sqrt(c*c+2000*c-1000000))/2;
		int b = static_cast<int>(floorf(erg));
		if (b == erg) {
			int a = 1000 - b - c;
			if (c > b && a != 0) {
				cout << "abc = " << a*b*c;
				return 0;
			}
		}
	}
}
