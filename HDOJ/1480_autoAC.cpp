#include<iostream>
#include<cmath>
#define N 30
using namespace std;
long long d[N],d1[N],d2[N];
int main()
{
    int i;
    long long t;
    d1[3]=32;
    d2[3]=72;
    d[3]=104;
    int n;
    n=25;
    for(i=4;i<=n;i++)
    {
        d1[i]=d1[i-1]+2*d2[i-1];
        d2[i]=4*d[i-1];
        t=pow(2,i+1);
        d1[i]=d1[i]+4*t-32;
        d2[i]=d2[i]+9*t-72;
        d[i]=d1[i]+d2[i];
    }
    for(i=3;i<=n;i++)
    {
        cout<<"N="<<i<<": "<<d[i]<<endl;
    }
    return 0;
}
