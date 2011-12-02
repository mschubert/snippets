#include <iostream>
#include <cmath>
using namespace std;

int main() { // beliebige position: row C element (start: 0)
	const int rows=25;
	unsigned long long int sum=0;

	int num[rows+1];
	num[0]=0; num[1]=1;
	for(int i=2;i<=rows;i++)
		num[i]=num[i-1]+i;

	int row;
	for(row=7;row<rows;row+=7) {
		int add;
		int a=num[row-1];
		int b=num[row-8];
		row>7? add=num[row-1]-num[row-8] : add=num[row-1]; // max size:7
		sum+=add;
	}

	row-=7;
	sum+=num[6]-num[row-1-(rows-row)];
	cout << num[rows] << " Zahlen, davon sind " << sum << " durch 7 teilbar und " << num[rows]-sum << " nicht\n";
}
