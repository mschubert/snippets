#include <iostream>
#include <list>
#include <string>
using namespace std;

int main() {
	list<string> names;
	FILE *fid = fopen("names.txt", "r");
	char buffer[100];
	while(fscanf(fid, "%s,", buffer) != EOF) {
		names.push_back(string(buffer));
	}
	fclose(fid);
	names.sort();

	unsigned long sum = 0;
	int hops = 0;
	for(list<string>::iterator it=names.begin();it!=names.end();it++) {
		string s = *it;
		int count = 0;
		for(unsigned int i=0;i<s.length();i++)
			count += s[i] - 'A' + 1;
		count *= ++hops;
		sum += count;
	}
	cout << sum;
}
