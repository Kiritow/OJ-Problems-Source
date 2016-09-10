#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <queue>
#include <map>
#include <set>
#include <vector>
#include <cctype>
using namespace std;
const int mod=6;
struct matrix{
    int f[6][6];
};
int A[1001][6],B[6][1001],C[1001][6],D[1001][1001];
matrix mul(matrix a,matrix b,int n)
{
    matrix c;
    memset(c.f,0,sizeof(c.f));
    int i,j,k;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            for(k=0;k<n;k++)
            {
                c.f[i][j]+=a.f[i][k]*b.f[k][j];
            }
            c.f[i][j]%=mod;
        }
    }
    return c;
}
matrix pow_mod(matrix a,int b,int n)
{
    matrix s;
    memset(s.f,0,sizeof(s.f));
    for(int i=0;i<n;i++)s.f[i][i]=1;
    while(b)
    {
        if(b&1)s=mul(s,a,n);
        a=mul(a,a,n);
        b=b>>1;
    }
    return s;
}
int main()
{
    int n,K;
    while(scanf("%d%d",&n,&K)!=EOF)
    {
        if(n==0&&K==0)break;
        int i,j,k;
        for(i=0;i<n;i++)
            for(j=0;j<K;j++)
                scanf("%d",&A[i][j]);
        for(i=0;i<K;i++)
            for(j=0;j<n;j++)
                scanf("%d",&B[i][j]);
        matrix e,g;
        memset(e.f,0,sizeof(e.f));
        for(i=0;i<K;i++)
        {
            for(j=0;j<K;j++)
            {
                for(k=0;k<n;k++)
                    e.f[i][j]+=B[i][k]*A[k][j];
                e.f[i][j]%mod;
            }
        }
        e=pow_mod(e,n*n-1,K);
        memset(C,0,sizeof(C));
        for(i=0;i<n;i++)
        {
            for(j=0;j<K;j++)
            {
                for(k=0;k<K;k++)
                    C[i][j]+=A[i][k]*e.f[k][j];
                C[i][j]%=mod;
            }
        }
        int ans=0;
        memset(D,0,sizeof(D));
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                for(k=0;k<K;k++)
                    D[i][j]+=C[i][k]*B[k][j];
                ans+=D[i][j]%mod;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
