#include<stdio.h>
int check(int n)
{
    int sum1=0,sum2=0,sum3=0;
    int m;
    m=n;
    while(m)
    {
        sum1+=m%10;
        m/=10;
    }
    m=n;
    while(m)
    {
        sum2+=m%12;
        m/=12;
    }
    m=n;
    while(m)
    {
        sum3+=m%16;
        m/=16;
    }
    if(sum1==sum2&&sum2==sum3)
        return 1;
    return 0;
}
int main()
{
    int m=2992;
    for(;m<=9999;m++)
    {   if(check(m))
            printf("%d\n",m);
    }
    return 0;
}
