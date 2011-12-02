#include <iostream>
#include <vector>
using namespace std;

int main() {
	const unsigned int max = 1000000;
	unsigned int steps[max+1], maxsteps=0, maxidx=0;
	steps[1] = 1;
	for(unsigned int i=2;i<=max;i++)
		steps[i] = 0;
	vector<unsigned int> chain;

	for(unsigned int i=2;i<=max;i++) {
		unsigned int n=i, cursteps=1;
		do {
			if (n>max || steps[n] == 0)
				chain.push_back(n);
			else {
				cursteps += steps[n];
				break;
			}
			n&1 ? n=3*n+1 : n=n>>1;
		} while (n != 1);
		
		unsigned int value;
		while (!chain.empty()) {
			value = chain.back();
			if (value <= max)
				steps[value] = cursteps;
			cursteps++;
			chain.pop_back();
		}
		
		if (cursteps > maxsteps) {
			maxsteps = cursteps;
			maxidx = value;
		}
	}
	
	cout << maxidx;
}
