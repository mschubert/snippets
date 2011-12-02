#include <iostream>
#include <math.h>
using namespace std;

int main() {
	double max=0;
	int i=1,maxidx=0;
	FILE *fid = fopen("base_exp.txt", "r");
	int base, exponent;
	while(fscanf(fid, "%i %i", &base, &exponent) != EOF) {
		double size = log(base) * exponent;
		if (size > max) {
			max=size;
			maxidx = i;
		}
		i++;
	}
	fclose(fid);
	cout << maxidx;
}
