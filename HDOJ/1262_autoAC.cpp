#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<iostream>
#include<string.h>
using namespace std;
#define M 10005
char a[M]={1,1,0};
void prime()
{
    int i,j;
    for(i=2;i<M;i++)
    {
        if(!a[i])
        for(j=i+i;j<M;j+=i)
            a[j]=1;
    }
}
int main()
{
    prime();
    int n;
    while(cin>>n)
    {
        int i=n/2;
        while(a[i]+a[n-i])i--;
        cout<<i<<' '<<n-i<<endl;
    }
    return 0;
}
