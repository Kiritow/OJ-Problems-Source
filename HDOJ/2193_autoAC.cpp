#include<iostream>
#include<cstdio>
using namespace std;
#define inf 100000000
#define max 100
__int64 a[max];
int main()
{
    int n;
    a[0]=1;
    a[1]=2;
    int i;
    int j;
    for(i=2;a[i]<=inf;i++)
    {
        a[i]=i+1;
        for(j=0;j<=i-2;j++)
            a[i]+=a[j];
    }
    while(1)
    {
        scanf("%d",&n);
        if(n==0)
        break;
        for(j=0;n>=a[j];j++);
        printf("%d\n",j-1);
    }
    return 0;
}
