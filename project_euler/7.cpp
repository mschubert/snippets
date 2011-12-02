#include <iostream>
using namespace std;

bool is_prime(int p) {
	for(int i=2;i<p;i++)
		if (p%i == 0)
			return false;
	return true;
}

int main() {
	int nprimes = 0;
	for(int i=2;;i++) {
		if (is_prime(i)) {
			if (++nprimes == 10001) {
				cout << ++nprimes << ": "<< i << endl;
				return 0;
			}
		}
	}
}
