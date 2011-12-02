#include <iostream>
using namespace std;

bool is_palindrome(int p) {
	char c[7];
	sprintf(c, "%i", p);
	int len = strlen(c);
	for(int k=0;k<len/2;k++)
		if (c[k] != c[len-k-1])
			return false;
	return true;
}

int main() {
	int erg = 0, ei = 0, ej = 0;
	for(int i=999;i>99;i--)
		for(int j=i;j>99;j--) {
			int p = i*j;
			if (is_palindrome(p) && p > erg) {
				erg = p;
				ei = i;
				ej = j;
			}
		}
	cout << ei << "*" << ej << " = " << erg << endl;
}
