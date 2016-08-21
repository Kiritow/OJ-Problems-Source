#include<stdio.h>
int gcd(int x,int y)
{
    if(x==y)
        return x;
    if(x>y)
        return gcd(x-y,y);
    if(x<y)
        return gcd(x,y-x);
}
int main()
{
    int a,b,c,d,e,f,g;
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        while(n--)
        {
            scanf("%d%d%d%d",&a,&b,&c,&d);
            e=a*d+b*c;
            f=b*d;
            g=gcd(e,f);
            printf("%d %d\n",e/g,f/g);
        }
    }
}
