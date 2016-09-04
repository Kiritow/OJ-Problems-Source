#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <queue>
#include <map>
#include <set>
using namespace std;
long long quickpow(long long a,long long b)
{
    long long n=1;
    while(b>0)
    {
        if(b&1)
        {
            n*=a;
        }
        b>>=1;
        a*=a;
    }
    return n;
}
int main()
{
    long long n;
    while(scanf("%I64d",&n),n)
    {
        long long sign=0;
        long long num=0;
        for(int i=1;i<=sqrt(n);i++)
        {
            if(i*i==n)
            {
                num=i;
                break;
            }
        }
        if(num)
        {
            if(num%2==0)
            sign+=(num/2-1);
            else
            sign+=(num/2);
        }
        for(long long k=3;k<=31;k++)
        {
            for(long long i=1;i<=1500;i++)
            {
                for(long long j=i+1;j<=1500;j++)
                {
                    long long powsum=quickpow(j,k)+quickpow(i,k)+j*i*k;
                    if(powsum==n)
                    sign++;
                    if(powsum>n||powsum<0)
                    break;
                }
                if(quickpow(i,k)>n)
                break;
            }
        }
        printf("%I64d\n",sign);
    }
}
