#include <iostream>
#include <stdio.h>
#include<string.h>
#include<algorithm>
#include<string>
#include<ctype.h>
using namespace std;
#define mod 10001
long long in[10010];
long long out[10010];
long long exgcd(long long a,long long b,long long &x,long long &y)
{
    if(!b)
    {
        x=1;
        y=0;
        return a;
    }
    long long tt=exgcd(b,a%b,x,y);
    long long t;
    t=x;
    x=y;
    y=(t-a/b*y);
    return tt;
}
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%I64d",in+i);
    int ok=0;
    for(long long i=0;i<=10000;i++)
    {
        long long c=((in[1]-i*i*in[0]%10001)%10001+10001)%10001;
        long long a=i+1;
        long long b=-10001;
        long long x,y;
        long long d=exgcd(a,b,x,y);
        if(c%d)
            continue;
        long long t=abs(b/d);
        x*=c/d;
        x=(x%t+t)%t;
        for(int j=0;j<n;j++)
        {
            out[j]=(i*in[j]+x)%10001;
            if(j==n-1)
            {
                ok=1;
                break;
            }
            if(((i*out[j]+x)%10001)!=in[j+1])
                break;
        }
        if(ok)
            break;
    }
    for(int i=0;i<n;i++)
    {
        printf("%I64d\n",out[i]);
    }
    return 0;
}
