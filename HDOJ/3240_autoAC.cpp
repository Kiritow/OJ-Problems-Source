#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <queue>
#include <iterator>
#include <stack>
#include <map>
#include <set>
#include <algorithm>
#include <cctype>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cmath>
using namespace std;
const int N=10001;
typedef long long LL;
int su[N],num[N];
int n,m,sui;
void mul(LL &res,int k)
{
    for(int i=0;i<sui;i++)
    {
        while(k%su[i]==0)
        {
            k/=su[i];
            num[i]++;
        }
    }
    res=(res*k)%m;
}
int ext_gcd(int a,int b,int &x,int &y)
{
    int t,ret;
    if(!b)
    {
        x=1;y=0;return a;
    }
    ret=ext_gcd(b,a%b,y,x);
    y-=x*(a/b);
    return ret;
}
void chu(LL &res,int k)
{
    for(int i=0;i<sui;i++)
    {
        while(k%su[i]==0&&num[i]>0)
        {
            k/=su[i];
            num[i]--;
        }
    }
    if(k!=1)
    {
        int x,y,temp;
        temp=ext_gcd(k,m,x,y);
        x=(x%m+m)%m;
        res=(res*x)%m;
    }
}
int main()
{
    int i,j,k,t;
    while(scanf("%d%d",&n,&m)&&(n+m))
    {
        sui=0,t=m;
        for(i=2;i*i<=t;i++)
            if(t%i==0)
            {
                su[sui++]=i;
                while(t%i==0)
                    t/=i;
            }
        if(t>1)
            su[sui++]=t;
        memset(num,0,sizeof(num));
        LL res=1,sum=1,l;
        for(i=2;i<=n;i++)
        {
            mul(res,4*i-2);
            chu(res,i+1);
            l=res;
            for(j=0;j<sui;j++)
                for(k=0;k<num[j];k++)
                    l=l*su[j]%m;
            sum=(sum+l)%m;
        }
        printf("%lld\n",sum);
    }
    return 0;
}
