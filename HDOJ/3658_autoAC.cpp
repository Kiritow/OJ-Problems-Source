#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
using namespace std;
#define LL __int64
const int mod=1000000007;
struct matrix{
    LL f[52][52];
};
matrix mul(matrix a,matrix b)
{
    int i,j,k;
    matrix c;
    memset(c.f,0,sizeof(c.f));
    for(i=0;i<52;i++)
    {
        for(j=0;j<52;j++)
        {
            for(k=0;k<52;k++)
            {
                c.f[i][j]+=a.f[i][k]*b.f[k][j]%mod;
            }
            c.f[i][j]%=mod;
        }
    }
    return c;
}
matrix pow_mod(matrix a,int b)
{
    matrix s;
    int i,j;
    memset(s.f,0,sizeof(s.f));
    for(i=0;i<52;i++)
        s.f[i][i]=1;
    while(b)
    {
        if(b&1)
            s=mul(s,a);
        a=mul(a,a);
        b=b>>1;
    }
    return s;
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int i,j,k,n,a[100];
        scanf("%d",&n);
        for(i=0;i<26;i++)
        {
            a[i]=i;
            a[i+26]=32+i;
        }
        matrix e,ee;
        memset(e.f,0,sizeof(e.f));
        memset(ee.f,0,sizeof(ee.f));
        for(j=0;j<52;j++)
        {
            for(i=0;i<52;i++)
            {
                if(abs(a[j]-a[i])<32)e.f[i][j]=1;
                if(abs(a[j]-a[i])<=32)ee.f[i][j]=1;
            }
        }
        e=pow_mod(e,n-1);
        ee=pow_mod(ee,n-1);
        LL ans=0;
        for(i=0;i<52;i++)
        {
            for(j=0;j<52;j++)
            {
                ans+=ee.f[i][j]-e.f[i][j];
            }
        }
        printf("%I64d\n",(ans%mod+mod)%mod);
    }
}
