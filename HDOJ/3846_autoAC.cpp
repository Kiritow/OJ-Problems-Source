#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct pnt
{
    int n,h,f;
}p[1000];
const int maxn=1000000;
int cmp(pnt a,pnt b)
{
    if(a.n==b.n) return a.f<b.f;
    return a.n<b.n;
}
int c;
void init()
{
    long long i,x;
    for(i=2;;i++)
    {
        x=i*(i+1)*(2*i+1)/6;
        if(x>maxn) break;
        p[c].n=x,p[c].h=i,p[c++].f=1;
    }
    x=1;
    for(i=3;;i+=2)
    {
        x+=i*i;
        if(x>maxn) break;
        p[c].n=x,p[c].h=i,p[c++].f=0;
    }
    x=4;
    for(i=4;;i+=2)
    {
        x+=i*i;
        if(x>maxn) break;
        p[c].n=x,p[c].h=i,p[c++].f=0;
    }
    sort(p,p+c,cmp);
}
int dp[maxn+5][12],pre[maxn+5][7];
int sta[1000],top;
int main()
{
    init();
    int tot,i,j,tc=1;
    for(i=0;i<=maxn;i++)
        for(j=0;j<=8;j++)
        dp[i][j]=21000;
    dp[0][0]=-1;
    int k;
    for(i=0;i<=maxn;i++)
    {
        for(j=0;j<=6;j++)if(dp[i][j]<=10000)
        for(k=dp[i][j]+1;k<c&&p[k].n+i<=maxn;k++)if(dp[i+p[k].n][j+1]>k)
            dp[i+p[k].n][j+1]=k;
    }
    int ii=0;
    while(scanf("%d",&tot),tot)
    {
        int ans=-1;
        for(i=1;i<=6;i++)if(dp[tot][i]<=2100)
        {
        ans=i;
        break;
        }
        printf("Case %d:",++ii);
        if(ans<0)
        {
        puts(" impossible");
        continue;
        }
        i=c;
        while(ans--)
        {
        for(i--;i>=0;i--)if(tot>=p[i].n&&dp[tot-p[i].n][ans]<i)
        {
            printf(" %d",p[i].h);
            if(p[i].f)
            printf("H");
            else
            printf("L");
            break;
        }
        tot-=p[i].n;
        }
        puts("");
    }
}
