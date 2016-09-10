#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<string>
#include<iostream>
#include<queue>
#include<stack>
#include<cmath>
using namespace std;
typedef long long ll;
const int maxn=1005;
const int mod=1000000007;
int a[maxn],n;
bool vis[maxn];
ll c[maxn][maxn],b[maxn][maxn];
ll f[maxn][maxn];
void init()
{
    for(int i=0; i<maxn; i++)c[i][0]=c[i][i]=1;
    for(int i=1; i<maxn; i++)
        for(int j=1; j<i; j++)
        {
            c[i][j]=c[i-1][j-1]+c[i-1][j];
            if(c[i][j]>=mod)c[i][j]-=mod;
        }
    for(int i=0; i<maxn; i++)b[i][0]=1;
    for(int i=1; i<maxn; i++)
        for(int j=1; j<=i; j++)
        {
            b[i][j]=b[i][j-1]*(i-j+1)%mod;
        }
}
void pd(ll&ret,ll val)
{
    ret+=val;
    if(ret>=mod)ret-=mod;
}
int main()
{
    init();
    int ncase=0;
    while(scanf("%d",&n)&&n)
    {
        memset(vis,0,sizeof(vis));
        bool sign=0;
        int cc=0;
        for(int i=1; i<=n; i++)
        {
            scanf("%d",&a[i]);
            if(a[i])cc++;
            for(int j=1; j<=a[i]; j++)
            {
                int x;
                scanf("%d",&x);
                if(vis[x])sign=1;
                vis[x]=1;
            }
        }
        if(sign||(n==1&&cc)||(n>1&&cc<2))printf("Case #%d: 0\n",++ncase);
        else
        {
            for(int i=0; i<=n; i++)
                for(int j=0; j<=i; j++)f[i][j]=0;
            int sum=0,sum2=0;
            f[0][0]=1;
            for(int i=0; i<n; i++)
            {
                for(int j=0; j<=i; j++)
                {
                    if(f[i][j]==0LL)continue;
                    if(a[i+1])
                    {
                        for(int k=0; k<=j; k++)
                        {
                            if(k>a[i+1])break;
                            pd(f[i+1][j+1-k],f[i][j]*c[a[i+1]][k]%mod*b[j][k]%mod);
                            pd(f[i+1][j-k],f[i][j]*c[a[i+1]][k]%mod*c[sum-(sum2-j)][1]%mod*b[j][k]%mod);
                        }
                    }
                    else
                    {
                        for(int k=0; k<=j; k++)
                        {
                            if(k>a[i+1])break;
                            pd(f[i+1][j-k],f[i][j]*c[a[i+1]][k]%mod*b[j][k]%mod);
                        }
                    }
                }
                sum+=a[i+1];
                if(a[i+1])sum2++;
            }
            printf("Case #%d: %I64d\n",++ncase,f[n][0]);
        }
    }
    return 0;
}
