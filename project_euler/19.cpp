#include <iostream>
using namespace std;

int main() {
	int day=1;
	int dpm[] = {31, 0, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	int count=0;
	
	for(int year=1901;year<2001;year++) {
		year%4 == 0 && year%100 != 0 && year%400 == 0 ? dpm[1]=29 : dpm[1]=28;
		for(int months=0;months<12;months++) {
			day+=dpm[months];
			day=day%7;
			if (day == 0)
				count++;
		}
	}
	cout << --count;
}
