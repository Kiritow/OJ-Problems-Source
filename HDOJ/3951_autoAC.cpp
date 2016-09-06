#include<iostream>
#include<cstdlib>
#include<stdio.h>
using namespace std;
int main()
{
    int t,n,k;
    int count=1;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&k);
        printf("Case %d: ",count++);
        if(k==1&&(n%2==1)) puts("first");
        else if(n<=k) puts("first");
        else puts("second");
    }
}
