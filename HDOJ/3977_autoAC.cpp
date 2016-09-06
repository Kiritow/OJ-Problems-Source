#include <stdio.h>
#include <algorithm>
#include <math.h>
#include <string.h>
#include <vector>
using namespace std;
#define MAXN 1000005
int prime[MAXN];
int p[MAXN];
int s[MAXN];
vector <int> pmo[MAXN];
int up;
int tag[MAXN];
int ttt[MAXN];
int answer[MAXN];
typedef struct
{
    long long m[2][2];
}Matrix;
void Prime()
{
    long long i,k;
    up=0;
    memset(prime,0,sizeof(prime));
    for (i=2;i<=MAXN-3;i++)
    {
        if (prime[i]==1) continue;
        k=i;
        while(k*i<MAXN-2)
        {
            prime[i*k]=1;
            k++;
        }
        p[up++]=i;
        prime[i]=up-1;
    }
}
Matrix Mul(Matrix a,Matrix b,int mod)
{
    Matrix c;
    int i,j,k;
    for (i=0;i<2;i++)
    {
        for (j=0;j<2;j++)
        {
            c.m[i][j]=0;
            for (k=0;k<2;k++)
            {
                c.m[i][j]=(c.m[i][j]+a.m[i][k]*b.m[k][j])%mod;
            }
        }
    }
    return c;
}
long long CountFib(int t,int mod)
{
    Matrix a,b;
    int k=t;
    a.m[0][0]=a.m[0][1]=a.m[1][0]=b.m[0][0]=1;
    a.m[1][1]=b.m[1][0]=b.m[0][1]=b.m[1][1]=0;
    while(t)
    {
        if (t&1)
        {
            b=Mul(a,b,mod);
        }
        a=Mul(a,a,mod);
        t>>=1;
    }
    return b.m[0][0];
}
int num[100][2];
int ret;
int now=0;
int Multi(int t,int n)
{
    int ans=1;
    while(n)
    {
        if (n&1) ans=ans*t;
        t=t*t;
        n>>=1;
    }
    return ans;
}
void DFS(int t,int mod,int mul)
{
    int j;
    if (mul>=ret) return;
    if (t==now)
    {
        if (CountFib(mul,mod)==1 && CountFib(mul+1,mod)==1) ret=mul;
        return;
    }
    for (j=0;j<=num[t][1];j++)
    {
        if (num[t][0]==2 && j==0) continue;
        int k=mul*Multi(num[t][0],j);
        DFS(t+1,mod,k);
    }
}
int DT(int t,int mod)
{
    int i;
    ret=t;
    now=0;
    for (i=0;i<up;i++)
    {
        if (t%p[i]!=0) continue;
        num[now][0]=p[i];
        num[now][1]=0;
        while(t%p[i]==0)
        {
            num[now][1]++;
            t/=p[i];
        }
        now++;
        if (t==1) break;
    }
    if (t!=1)
    {
        num[now][0]=t;
        num[now++][1]=1;
    }
    DFS(0,mod,1);
    return ret;
}
int Count(int t)
{
    int i,k,j;
    if (t==2)
    {
        return 3;
    }
    else if (t==5)
    {
        return 20;
    }
    if (t%10==1 || t%10==9) k=t-1;
    if (t%10==3 || t%10==7) k=t*2+2;
    return DT(k,t);
}
int fj[50][2];
int main()
{
    int i,j,m,T,cnt;
    long long n;
    Prime();
    scanf("%d",&T);
    cnt=1;
    while(T--)
    {
        scanf("%I64d",&n);
        m=0;
        for (i=0;i<up;i++)
        {
            if (n%p[i]==0)
            {
                fj[m][0]=p[i];
                fj[m][1]=0;
                while(n%p[i]==0)
                {
                    fj[m][1]++;
                    n/=p[i];
                }
                m++;
            }
            if (n==1) break;
        }
        memset(answer,0,sizeof(answer));
        int mm=0;
        for (i=0;i<m;i++)
        {
            memset(tag,0,sizeof(tag));
            if (fj[i][1]>0)
            {
                mm=max(prime[fj[i][0]],mm);
                tag[prime[fj[i][0]]]+=fj[i][1]-1;
            }
            int tt=Count(fj[i][0]);
            for (j=0;j<up;j++)
            {
                while(tt%p[j]==0)
                {
                    tt/=p[j];
                    tag[j]++;
                    mm=max(mm,j);
                }
                if (tt==1) break;
            }
            for (j=0;j<=mm;j++)
            {
                answer[j]=max(tag[j],answer[j]);
            }
        }
        long long pr=1;
        for (i=0;i<=mm;i++)
        {
            for (j=0;j<answer[i];j++)
            {
                pr*=p[i];
            }
        }
        printf("Case #%d: %I64d\n",cnt++,pr);
    }
    return 0;
}
