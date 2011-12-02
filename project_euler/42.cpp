#include <iostream>
using namespace std;

int main() {
	int tri[100], triwords=0;
	for(int i=2;i<100;i++)
		tri[i] = static_cast<int>((static_cast<float>(i)/2)*(i+1));
	
	FILE *fid = fopen("words.txt", "r");
	char buf[50];
	while(fscanf(fid, "%s", buf) != EOF) {
		int i=0,sum=0;
		do { sum+=buf[i]-'A'+1; } while(buf[++i] != '\0');
		
		for(int i=0;i<100;i++)
			if (sum==tri[i]) {
				triwords++;
				cout << triwords << ":" <<buf << " ";
				break;
			}
	}
	fclose(fid);
	cout << triwords+1; // warum +1?
}
