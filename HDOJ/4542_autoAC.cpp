#include <stdio.h>
#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;
const int MAXN=100000;
int prime[MAXN+1];
void getPrime()
{
    memset(prime,0,sizeof(prime));
    for(int i=2;i<=MAXN;i++)
    {
        if(!prime[i])prime[++prime[0]]=i;
        for(int j=1;j<=prime[0]&&prime[j]<=MAXN/i;j++)
        {
            prime[prime[j]*i]=1;
            if(i%prime[j]==0)break;
        }
    }
}
long long factor[100][2];
int fatCnt;
int getFactors(long long x)
{
    fatCnt=0;
    long long tmp=x;
    for(int i=1;prime[i]<=tmp/prime[i];i++)
    {
        factor[fatCnt][1]=0;
        if(tmp%prime[i]==0)
        {
            factor[fatCnt][0]=prime[i];
            while(tmp%prime[i]==0)
            {
                factor[fatCnt][1]++;
                tmp/=prime[i];
            }
            fatCnt++;
        }
    }
    if(tmp!=1)
    {
        factor[fatCnt][0]=tmp;
        factor[fatCnt++][1]=1;
    }
    return fatCnt;
}
const long long INF=(1LL<<62)+1;
int N;
long long ans;
long long a[47787];
void dfs(int i,long long x,int n)
{
    if(n>47777)return;
    if(x<INF && (a[n]==0||a[n]>x))a[n]=x;
    for(int j=1;j<=62;j++)
    {
        if(INF/prime[i]<x)break;
        x*=prime[i];
        if(x>=INF)break;
        dfs(i+1,x,n*(j+1));
    }
}
int get(int x)
{
    getFactors(x);
    int ans=1;
    for(int i=0;i<fatCnt;i++)
       ans*=(factor[i][1]+1);
    return ans;
}
void solve2()
{
    int x=2;
    while(x*x<=4*(N+x))
    {
        if(x==get(N+x))
        {
            printf("%d\n",N+x);
            return;
        }
        x++;
    }
    printf("Illegal\n");
}
void init()
{
    memset(a,0,sizeof(a));
    dfs(1,1,1);
}
int main()
{
    int T;
    getPrime();
    int iCase=0;
    scanf("%d",&T);
    int Type;
    init();
    while(T--)
    {
        iCase++;
        scanf("%d%d",&Type,&N);
        printf("Case %d: ",iCase);
        if(Type==0)
        {
            if(a[N]!=0)printf("%I64d\n",a[N]);
            else printf("INF\n");
        }
        else solve2();
    }
    return 0;
}
