#include <stdio.h>
//Written by Kiritow. 求最大公约数
long gcd(long a,long b)
{
    if(a==0||b==0)
    {
        if(a+b==0)
        {
            return 0;
        }
        return (a==0)?b:a;
    }
 
    while(a!=b)
    {
        if(a>b)
        {
            a=a-b;
        }
        else
        {
            b=b-a;
        }
    }
    return a;
}
int main()
{
    int a,b;
    scanf("%d %d",&a,&b);
    int ans=gcd(a,b);
    printf("最大公约数:%d\n最小公倍数:%d\n",ans,a*b/ans);
    return 0;
}
