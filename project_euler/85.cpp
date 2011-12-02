#include <iostream>
using namespace std;

typedef struct { int x, y; } vec;

int calc(vec grid, vec query) {
	int psb=0;
	// calc wie oft so möglich
	
	if (query.x<grid.x) {
		vec n1=query;
		n1.x++;
		psb+=calc(grid, n1);
	}
	if (query.y<grid.y) {
		vec n2=query;
		n1.y++;
		psb+=calc(grid, n2);
	}
	
	return psb;
}

int main() {
	vec grid, query;
	grid.x=3;
	grid.y=2;
	query.x=1;
	query.y=1;
	
	cout << calc(grid, query);
	
}
