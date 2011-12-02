#include <iostream>
using namespace std;

int main() {
	const int size=10000000;
	int *array = new int[size];
	
	for(int i=2;i<size/2;i++)
		for(int j=2*i;j<size;j+=i)
			array[j]++;
	
	int count=0;
	for(int i=2;i<size;i++)
		if (array[i]==array[i+1])
			count++;
	
	cout << count;
}


/*
fastest method:

#include <stdio.h>
#include <math.h>
#include <time.h>
 
#define N 10000000
 
int main ()
{
    double dtime=clock();
    int rootN=(int) sqrt(N)+1;
    int count[rootN];
    int found=0;
    int i,f,i2,stored,st,first,last,up,p,sq,mini;
 
for(first=0;first<N;first+=rootN)  {
    for(i=0;i<rootN;i++)  count[i]=1;
 
    last=first+rootN;
    sq=(int) sqrt(last)+1;
 
    for(i=2;i<=sq;i++)  {
        mini=(first+i-1)/i;
        if(mini<i)  mini=i;
        for(f=mini*i-first;f<rootN;f+=i)  count[f]++;
    }
 
    if(first==0)  st=2;
    else          st=0;
    up=rootN-1;
    if(up+first>N)  up=N-first;
 
    for(i=st;i<up;i++)
        if(count[i]==count[i+1])  found++;
 
    if((first!=0)&&(stored==count[0]))  found++;
 
    for(i=(int) sqrt(first),i2=i*i;i2<last;i++,i2=i*i)  {
        p=i2-1-first;
        if((p>=0)&&(p<up)&&(count[p]==count[p+1]))  found--;
        p+=2;
        if((p>0)&&(p<=up)&&(count[p]==count[p-1]))  found--;
    }
 
    if(first!=0)  {
       sq=(int) sqrt(first);
       if((sq*sq==first)&&(stored==count[0]))  found--;
       sq=(int) sqrt(first-1);
       if((sq*sq==first-1)&&(stored==count[0]))  found--;
    }
    else {
          if(count[0]==count[1])  found+=2;
          if(count[1]==count[2])  found++;
    }
    stored=count[rootN-1];
}
    dtime=clock()-dtime;
    printf("for N=%d: fast method %d, %.3lf sec",N,found,(double) dtime/CLOCKS_PER_SEC);
    return 0;
}
*/