#include <iostream>
#include <list>
using namespace std;

struct s {
	int n, rad;
	bool operator<( const s &rhs) { return rad < rhs.rad; }
};

int main() {
	list<int> pfactors;
	list<s> radical;
	int max=100000, query=10000;

	for(int i=2;i<=max;++i) { // sehr ineffizient, besser: radical array, und mit primes aufmultiplizieren
		unsigned long long int pnum = i;
		for(unsigned int p=2;p<=pnum;p++) {
			if (pnum%p == 0) {
				pnum /= p;
				pfactors.push_back(p);
				p--;
			}
		}
		pfactors.unique();

		int rad=1;
		for(list<int>::iterator it=pfactors.begin();it!=pfactors.end();it++)
			rad *= *it;
		
		s item; item.n=i; item.rad=rad;
		radical.push_back(item);
		pfactors.clear();
	}
	
	radical.sort();
	int i=2;
	while(i<query) {
		radical.pop_front();
		i++;
	}
	cout << (*radical.begin()).n;
	radical.clear();
}
