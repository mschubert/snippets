#include <iostream>
#include <vector>
using namespace std;

int main() {
	const unsigned int limit = 40;
	vector<int> v;
	unsigned int numbers[limit];
	for(unsigned int i=0;i<limit;i++)
		numbers[i] = i+2;
	
	for(unsigned int i=2;i<=limit;i++)
		if (numbers[i-2] != 0)
			for(unsigned int j=2*i;j<=limit;j+=i)
				numbers[j-2] = 0;
			
	unsigned long long int sum = 0;
	for(unsigned int i=8;i<limit;i++)
		if (numbers[i] != 0) {
			int num = numbers[i];
			int digits = 1;
			bool truncatable = true;
			int count =1;
			do { // re->li
				num/=10;
				count*=10;
				if (num==1 || numbers[num-2]==0) {
					truncatable = false;
					break;
				}
			} while(num>0);
			
			if (!truncatable)
				continue;
			
			for(int k=10;k<=count;k*=10) { // li->re
				num=numbers[i]%k;
				if (num==1 || numbers[num-2]==0) {
					truncatable = false;
					break;
				}
			}
			
			if (!truncatable)
				continue;
			
			v.push_back(numbers[i]);
		}
		
	for(int i=0;i<v.size();i++)
	cout<<v[i] << " ";//	sum+= v[i];
//	cout << sum;
}
