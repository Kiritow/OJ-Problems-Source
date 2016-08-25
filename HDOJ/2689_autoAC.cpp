#include<stdio.h>
#include<string.h>
int a[1002];
int lowbit(int x)
{
    return x&(-x);
}
void add(int x)
{
    while(x<=1000)
    {
        ++a[x];
        x=x+lowbit(x);
    }
}
int getsum(int x)
{
    int sum=0;
    while(x>0)
    {
        sum=sum+a[x];
        x=x-lowbit(x);
    }
    return sum;
}
int main()
{
    int i,j,n,x,sum;
    while(scanf("%d",&n)==1)
    {
        sum=0;
        memset(a,0,sizeof(a));
        for(i=1;i<=n;i++)
        {
            scanf("%d",&x);
            sum=sum+(i-1-getsum(x));
            add(x);
        }
        printf("%d\n",sum);
    }
    return 0;
}
