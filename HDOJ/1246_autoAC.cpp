#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int main()
{
    int i,a[310]={1,1},n,j;
    for(i=3;i<310;i+=2)
    {
        for(j=310;j>=0;j--)
        {
            if(i+j<=310)
            a[i+j]+=a[j];
        }
    }
    while(cin>>n)
    {
        cout<<a[n]<<endl;
    }
    return 0;
}
