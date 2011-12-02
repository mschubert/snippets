#include <iostream>
#include <math.h>
#include <list>
using namespace std;

int main() {
	double logs[99];
	for(int i=0;i<99;i++)
		logs[i] = log(i+2);
	int max=1;
	for(int i=0;i<20;i++)
		max*=10;
	
	list<unsigned long long int> v;
	for(int i=2;i<=100;i++)
		for(int j=2;j<=100;j++)
			v.push_back(static_cast<unsigned long long int>(logs[i-2] * j * max));
	
	v.sort();
	v.unique();
	cout << v.size();
}
