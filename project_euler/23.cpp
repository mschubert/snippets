#include <iostream>
#include <vector>
using namespace std;

int main() {
	vector<int> abnum;
	
	for(int i=12;i<28124;i++) {
		int sum=1;
		for(int j=2;j<i;j++)
			if (i%j==0)
				sum+=j;

		if (sum>i) // number is abundant
			abnum.push_back(i);
	}
	
	int *sumabnum = new int[28124];
	for(int i=0;i<28124;i++)
		sumabnum[i] = i;
	
	for(unsigned int i=0;i<abnum.size();i++)
		for(unsigned int j=i;j<abnum.size();j++)
			sumabnum[abnum[i]+abnum[j]] = 0;
	
	long sum=0;
	for(int i=0;i<28124;i++)
		sum+=sumabnum[i];
	
	cout << sum << endl;
}
