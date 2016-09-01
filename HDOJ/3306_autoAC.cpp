#include<stdio.h>
#include<algorithm>
#include<string.h>
using namespace std;
struct mart
{
    __int64 mat[5][5];
};
__int64 mod=10007;
mart kk;
mart multi(mart a,mart b)
{
    mart c;
    int i,j,k;
    for(i=1;i<=4;i++)
        for(j=1;j<=4;j++)
        {
            c.mat[i][j]=0;
            for(k=1;k<=4;k++)
                c.mat[i][j]=(c.mat[i][j]+a.mat[i][k]*b.mat[k][j])%mod;
        }
    return c;
}
mart power(int k)
{
    mart p,q;
    int i,j;
    for(i=1;i<=4;i++)
        for(j=1;j<=4;j++)
        {
            p.mat[i][j]=kk.mat[i][j];
            if(i==j)
                q.mat[i][j]=1;
            else
                q.mat[i][j]=0;
        }
    if(k==0)
        return q;
    while(k!=1)
    {
        if(k&1)
        {
            k--;
            q=multi(p,q);
        }
        else
        {
            k=k>>1;
            p=multi(p,p);
        }
    }
    p=multi(p,q);
    return p;
}
void init(__int64 x,__int64 y)
{
    kk.mat[1][1]=1;
    kk.mat[1][2]=(x%mod)*(x%mod)%mod;
    kk.mat[1][3]=(y%mod)*(y%mod)%mod;
    kk.mat[1][4]=(2*x%mod)*(y%mod)%mod;
    kk.mat[2][1]=0;
    kk.mat[2][2]=(x%mod)*(x%mod)%mod;
    kk.mat[2][3]=(y%mod)*(y%mod)%mod;
    kk.mat[2][4]=(2*x%mod)*(y%mod)%mod;
    kk.mat[3][1]=0;
    kk.mat[3][2]=1;
    kk.mat[3][3]=0;
    kk.mat[3][4]=0;
    kk.mat[4][1]=0;
    kk.mat[4][2]=x%mod;
    kk.mat[4][3]=0;
    kk.mat[4][4]=y%mod;
}
int main()
{
    int n,i;
    __int64 a[5],x,y;
    mart xx;
    while(scanf("%d%I64d%I64d",&n,&x,&y)!=EOF)
    {
        a[1]=2,a[2]=1,a[3]=1,a[4]=1;
        init(x,y);
        xx=power(n-1);
        __int64 ans=0;
        for(i=1;i<=4;i++)
            ans=(ans+a[i]*xx.mat[1][i])%mod;
        printf("%I64d\n",ans);
    }
    return 0;
}
