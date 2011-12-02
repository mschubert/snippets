#include <iostream>
using namespace std;

int main() {
	float pre=1,cur=1;
	int digits=1,count=2;
	
	do {
		float temp = pre;
		pre = cur;
		cur = temp+pre;
		count++;
		
		if (cur > 10) {
			cur/=10;
			pre/=10;
			digits++;
		}
	} while (digits < 1000);
	
	cout << count;
}
