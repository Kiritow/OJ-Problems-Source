#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;
const int MAXN=10000010;
bool nprime[MAXN];
int prime[750000],tot,dnum[MAXN],tms[MAXN],tms2[MAXN];
int s1[MAXN];
long long s2[MAXN];
int n,m;
long long ans;
void getPrime(int n)
{
    for(int i=2;i<=n;i++)
    {
        if(!nprime[i]) {prime[++tot]=i,dnum[i]=2,tms[i]=1;}
        for(int j=1;(j<=tot)&&(i*prime[j]<=n);j++)
        {
            nprime[i*prime[j]]=true;
            if(i%prime[j]==0)
            {
                dnum[i*prime[j]]=dnum[i]/(tms[i]+1)*(tms[i]+2);
                tms[i*prime[j]]=tms[i]+1;
                break;
            }
            dnum[i*prime[j]]=dnum[i]*dnum[prime[j]];
            tms[i*prime[j]]=1;
        }
    }
}
int main()
{
    getPrime(10000000);
    tms2[1]=0,tms2[2]=1,dnum[1]=1;
    for(int i=3;i<=10000000;i++) if(!(i&1)) tms2[i]=tms2[i>>1]+1;
    for(int i=1;i<=10000000;i++)
        dnum[i]/=tms2[i]+1,s1[i]=s1[i-1]+(long long)dnum[i],s2[i]=s2[i-1]+(long long)i*dnum[i];
    scanf("%d",&m);
    for(int cas=1;cas<=m;cas++)
    {
        scanf("%d",&n);
        ans=n+1+(long long)s1[n-1]*n-s2[n-1];
        printf("Case #%d:\n",cas);
        printf("%I64d\n",ans);
    }
    return 0;
}
