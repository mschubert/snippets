#include <iostream>
using namespace std;

inline long factorial (int n) {
	long result;
	n==0 ? result = 1 : result = n * factorial(n-1);
	return result;
}

int main() {
	int digits = 10;
	int search = 999999;

	for(int i=digits-1;i>0;i--) {
		int j, pos, cur_per=0;
		for(j=0;j<digits;j++) {
			pos = factorial(i+1) - j*factorial(i);
			if (pos <= search)
				break;
		}
		
		cur_per = (digits--) - j;
		search -= pos;
		cout << cur_per << " ";
	}
}
//2662512110 -> bei 0123456789 immer von links nach rechts zählen und streichen
