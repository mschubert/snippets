#include <iostream>
using namespace std;

int main() {
	const int size=1000000;
	
	int psb=0;
	const int arsize=size/4+1;
	int *g = new int[arsize];
	int *u = new int[arsize];
	for(int i=0;i<arsize;i++) {
		g[i] = i*8+12;
		u[i] = i*8+8;
	}
	
//	int g[] = {12, 20, 28, 36, 44, 52, 60, 68, 76, 84, 92, 100, 108};
	for(int i=0;i<arsize;i++) {
		int blocks=0;
		for(int j=0;j<=i;j++) {
			blocks+=g[i-j];
			if (blocks>size)
				break;
			psb++;
		}
	}
	
	
//	int u[] = {8, 16, 24, 32, 40, 48, 56, 64, 72, 80, 88, 96, 104};
	for(int i=0;i<arsize;i++) {
		int blocks=0;
		for(int j=0;j<=i;j++) {
			blocks+=u[i-j];
			if (blocks>size)
				break;
			psb++;
		}
	}
	
	cout << psb;
}
