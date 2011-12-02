#include <iostream>
using namespace std

int main() {
	const unsigned int limit = 1000000;
	unsigned int numbers[limit];
	for(unsigned int i=0;i<limit;i++)
		numbers[i] = i+1;
	
	for(unsigned int i=2;i<=limit;i++)
		if (numbers[i-1] != 0)
			for(unsigned int j=2*i;j<=limit;j+=i)
				numbers[j-1] = 0;
			
	int count=0;
	for(unsigned int i=1;i<limit;i++)
		if (numbers[i] != 0) {
			// check if circular
		}
		
	cout << count;
}
