#include <iostream>
#include <cmath>
using namespace std;

bool isPrime(long long int num)
{
    //return ((num+1)/6)*6 == (num+1) || ((num-1)/6)*6 == (num+1);

    for(long long int i=2; i<num; i++)
        if (num%i==0) return false;
    //cout << num << " ";
    return true;
}

int main()
{
    int cur = 3;
    int plus = 2;
    int atn = 0;

    const long long int limit = 1000000000;

    int ndiag = 2;
    int nprimes = 1;

    while((cur+=plus) < limit)
    {
        ndiag++;

        if (isPrime(cur+atn))
            nprimes++;
        if (nprimes*10 < ndiag*1)
            break;

        atn==0 ? atn=-1 : atn=0;

        cur += plus;
        ndiag++;

        if (isPrime(cur))
            nprimes++;
        if (nprimes*10 < ndiag*1)
            break;
        
        plus += 1;
    }

    cout << cur << " " << plus << endl;
}