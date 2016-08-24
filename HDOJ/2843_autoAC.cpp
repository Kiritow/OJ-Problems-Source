#include<stdio.h>
#include<string.h>
int gcd(int a, int  b)
{
    return b == 0 ? a : gcd(b, a % b);
}
int main()
{
    int n,m,c;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        if(n==0&&m==0)break;
        n+=2;m+=1;
        c=gcd(n,m);
        printf("%d %d\n",m/c,n/c);
    }
    return 0;
}
