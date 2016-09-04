#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>
using namespace std;
#define LL __int64
const LL mod=112233;
LL a[14][14]={
                { 0, 1, 1, 1, 1, 1,1,0,0,0,0,0,0,0},
                { 1, 0, 1, 1, 1, 1,0,0,0,0,0,0,0,0},
                { 1, 1, 0, 1, 1, 1,0,0,0,0,0,0,0,0},
                { 1, 1, 1, 0, 1, 1,0,0,0,0,0,0,0,0},
                { 1, 1, 1, 1, 0, 1,0,0,0,0,0,0,0,0},
                { 1, 1, 1, 1, 1, 0,0,0,0,0,1,0,0,0},
                { 0, 0, 0, 0, 0, 0,0,1,0,0,0,0,0,0},
                { 0, 0, 0, 0, 0, 0,0,0,1,0,0,0,0,0},
                { 0, 0, 0, 0, 0, 0,0,0,0,1,0,0,0,0},
                { 0, 0, 0, 0, 0,-1,0,0,0,0,0,0,0,0},
                { 0, 0, 0, 0, 0, 0,0,0,0,0,0,1,0,0},
                { 0, 0, 0, 0, 0, 0,0,0,0,0,0,0,1,0},
                { 0, 0, 0, 0, 0, 0,0,0,0,0,0,0,0,1},
                {-1, 0, 0, 0, 0, 0,0,0,0,0,0,0,0,0}
};
struct matrix{
    LL f[14][14];
};
matrix mul(matrix a,matrix b)
{
    matrix c;
    LL i,j,k;
    memset(c.f,0,sizeof(c.f));
    for(k=0;k<14;k++)
    {
        for(i=0;i<14;i++)
        {
            if(!a.f[i][k])continue;
            for(j=0;j<14;j++)
            {
                if(!b.f[k][j])continue;
                c.f[i][j]=(c.f[i][j]+a.f[i][k]*b.f[k][j])%mod;
            }
        }
    }
    return c;
}
matrix pow_mod(matrix a,LL b)
{
    matrix s;
    memset(s.f,0,sizeof(s.f));
    for(LL i=0;i<14;i++)
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
    LL n;
    while(cin>>n)
    {
        if(n%2==0)
        {
            cout<<0<<endl;
            continue;
        }
        matrix e;
        LL i,j,ans=0;
        memcpy(e.f,a,sizeof(a));
        e=pow_mod(e,n/2);
        for(i=0;i<6;i++)
            for(j=0;j<6;j++)
            ans=(ans+e.f[i][j])%mod;
        cout<<(ans+mod)%mod<<endl;
    }
    return 0;
}
