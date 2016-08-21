#include<stdio.h>
int gcd(int x,int y) 
{
    return y==0?x:gcd(y,x%y);
}
int main()
{
    int a,b,c,t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&a,&b);
        c=b+b;
        while(gcd(a,c)!=b)
        c+=b;
        printf("%d\n",c);
    }
}
