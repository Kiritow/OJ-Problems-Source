#include <stdio.h>
int jieceng(int a)
{
    int s,i;
    s=1;
    for(i=2;i<=a;i++)
        s*=i;
    return s;
}
int weishu(int a)
{
    int sum=0;
    int b;
    b=a;
    while(a)
    {
        sum+=jieceng(a%10);
        a/=10;
    }
    if(sum==b)
        return 1;
    return 0;
}
int main()
{
    int n,i;
    for(i=1;i<=50000;i++)
    {
        if(weishu(i))
            printf("%d\n",i);
    }
}
