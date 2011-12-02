#include <iostream>
using namespace std;

int main() {
	int start = 20;
	for(long i=start;true;i+=start) {
		bool is_div = true;
		for(long j=2;j<=start;j++) {
			if (i%j != 0) {
				is_div = false;
				break;
			}
		}
		if (is_div) {
			cout << i;
			return 0;
		}
	}
}
