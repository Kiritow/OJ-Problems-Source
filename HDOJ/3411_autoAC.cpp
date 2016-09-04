#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#define N 50005
#define M 30
#define read(a,b,c) scanf("%d%d%d",&a,&b,&c)
#define cl(a) memset(a,0,sizeof(a))
#define ll long long
ll x[M],f[3],r[N][3][3],q;
int p;
using namespace std;
ll bin(ll t)
{
    ll res=1;
    int i=0;
    while (t>0)
    {
        if (t&1) res=(res*x[i])%p;
        i++;
        t>>=1;
    }
    return res;
}
void init()
{
    r[0][1][1]=(q-1+p)%p;
    r[0][1][2]=q;
    r[0][2][1]=1;
    r[0][2][2]=0;
    f[1]=1;f[2]=0;
}
void mul(int t)
{
    int i,j,k;
    for (i=1;i<=2;i++)
        for (j=1;j<=2;j++)
        {
            r[t][i][j]=0;
            for (k=1;k<=2;k++) r[t][i][j]=r[t][i][j]+(r[t-1][i][k]*r[t-1][k][j])%p; 
        }
}
void zmul(int i)
{
    ll g1,g2;
    g1=(f[1]*r[i][1][1])%p+(f[2]*r[i][1][2])%p;
    g2=(f[1]*r[i][2][1])%p+(f[2]*r[i][2][2])%p;
    f[1]=g1%p;f[2]=g2%p;
}
void bin2(int t)
{
    int i=0;
    while (t>0)
    {
        if (t&1) zmul(i);
        t>>=1;
        i++;
    }   
}
int main()
{
    int x1,y1,z1,y2,z2,i,j;
    while (read(x1,y1,z1)!=EOF)
    {
        if (x1==-1&&y1==-1&&z1==-1) break;
        read(y2,z2,p);
        cl(x);
        x[0]=x1%p;
        for (i=1;i<M;i++) x[i]=(x[i-1]*x[i-1])%p;
        q=(bin(y1)+z1)%p;
        init();
        for (i=1;i<N;i++) mul(i);
        zmul(y2);
        if (z2>0) bin2(z2-1);
        if (z2>=1) printf("%d\n",f[1]);
        else printf("%d\n",f[2]);
    }
    return 0;
}
