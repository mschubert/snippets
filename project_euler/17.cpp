#include <iostream>
using namespace std;

int main() {

	for(int i=1;i<1000;i++) {
		switch(i%10) {
			case 1: count+=3;
			case 2: count+=3;
			case 3: count+=5;
			case 4: count+=4;
			case 5: count+=4;
			case 6: count+=3;
			case 7: count+=5;
			case 8: count+=5;
			case 9: count+=4;
		}
		
		switch((i%100)/10) {
			case 1: count+=3;
			case 2: count+=6;
			case 3: count+=6;
			case 4: count+=6;
			case 5: count+=5;
			case 6: count+=5;
			case 7: count+=7;
			case 8: count+=6;
			case 9: count+=6;
		}
		
		switch(i/100) {
			case 1: count+=10;
			case 2: count+=10;
			case 3: count+=12;
			case 4: count+=11;
			case 5: count+=11;
			case 6: count+=10;
			case 7: count+=12;
			case 8: count+=12;
			case 9: count+=11;
		}
	}
	count += 11 -2*10;
	cout << count;
}
