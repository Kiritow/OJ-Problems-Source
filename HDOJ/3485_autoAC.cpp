#include<iostream>
using namespace std;
int f[10005];
int n;
int deal(int n)
{
    if(f[n]!=0)
        return f[n];
    f[n-1]=deal(n-1)%9997;
    f[n-2]=deal(n-2)%9997;
    f[n-4]=deal(n-4)%9997;
    return ((f[n-1]+f[n-2]+f[n-4])%9997);
}
int main()
{
    while(scanf("%d",&n)!=EOF&&n!=-1)
    {
        f[0]=1;
        f[1]=2;
        f[2]=4;
        f[3]=7;
        printf("%d\n",deal(n));
    }
}
