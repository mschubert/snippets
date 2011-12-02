#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main() {
	unsigned char *a = new unsigned char[1000001];
	
	int num=1, idx=1;
	stringstream converter;
	do {
		converter << num++;
		string s = converter.str();
		for(unsigned int i=0;i<s.length();i++)
			a[idx++]=s[i]-'0';
	} while(idx<1000001);
	
	unsigned long erg = a[1]*a[10]*a[100]*a[1000]*a[10000]*a[100000]*a[1000000];
	cout << erg;
	delete[] a;
}
