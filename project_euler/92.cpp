#include <iostream>
#include <vector>
using namespace std;

int main() {
	unsigned int max = 10000000; // nur 1eX
	unsigned char *steps = new unsigned char[max+1];
	unsigned int end89=0, end1=1;
	vector<unsigned int> chain;
	steps[1] = 1;
	
	for(unsigned int i=2;i<=max;i++) {
		unsigned int n=i;
		do {
			if (steps[n] == 0)
				chain.push_back(n);
			else {
				n = steps[n];
				break;
			}
			unsigned int temp=0, tempn=n, ndiv;
			for(unsigned int div=max;div>0;div/=10) { // n=square of digits
				ndiv = tempn/div;
				temp += ndiv*ndiv;
				tempn -= ndiv*div;
			}
			n = temp;
		} while (n != 89 && n != 1);

		unsigned int value;
		while (!chain.empty()) {
			value = chain.back();
			steps[value] = n; // 89 oder 1
			if (n==1) end1++;
			if (n==89) end89++;
			chain.pop_back();
		}
	}
	cout << "1:  " << end1 << "\n89: " << end89;
}
