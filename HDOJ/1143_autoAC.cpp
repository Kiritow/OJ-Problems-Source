#include<string.h>
#include<cstdio>
#include<iostream>
#include<algorithm>
const int MAX=31;
int s[MAX];
using namespace std;
int main()
{
    int i,n;
    s[0]=1;
    s[2]=3;
    for(i=4;i<MAX;i+=2)
    {
        s[i]=4*s[i-2]-s[i-4];
    }
    while(cin>>n,n>=0)
    {
        if(n&1)
        cout<<0<<endl;
        else
        cout<<s[n]<<endl;
    }
    return 0;
}
