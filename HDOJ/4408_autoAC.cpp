#include <map>
#include <stack>
#include <queue>
#include <math.h>
#include <vector>
#include <string>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#define N 405
#define M 4005
#define E
#define inf 0x3f3f3f3f
#define dinf 1e10
#define linf (LL)1<<60
#define LL long long
#define clr(a,b) memset(a,b,sizeof(a))
using namespace std;
LL mod;
struct Edge
{
    int a,b,c;
    bool operator<(const Edge & t)const
    {
        return c<t.c;
    }
}edge[M];
int n,m;
LL ans;
int fa[N],ka[N],vis[N];
LL gk[N][N],tmp[N][N];
vector<int>gra[N];
int findfa(int a,int b[]){return a==b[a]?a:b[a]=findfa(b[a],b);}
LL det(LL a[][N],int n)
{
    for(int i=0;i<n;i++)for(int j=0;j<n;j++)a[i][j]%=mod;
    long long ret=1;
    for(int i=1;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
            while(a[j][i])
            {
                LL t=a[i][i]/a[j][i];
                for(int k=i;k<n;k++)
                    a[i][k]=(a[i][k]-a[j][k]*t)%mod;
                for(int k=i;k<n;k++)
                    swap(a[i][k],a[j][k]);
                ret=-ret;
            }
        if(a[i][i]==0)return 0;
        ret=ret*a[i][i]%mod;
    }
    return (ret+mod)%mod;
}
int main()
{
    while(scanf("%d%d%I64d",&n,&m,&mod)==3)
    {
        if(n==0 && m==0 && mod==0)break;
        memset(gk,0,sizeof(gk));
        memset(tmp,0,sizeof(tmp));
        memset(fa,0,sizeof(fa));
        memset(ka,0,sizeof(ka));
        memset(tmp,0,sizeof(tmp));
        for(int i=0;i<N;i++)gra[i].clear();
        for(int i=0;i<m;i++)
            scanf("%d%d%d",&edge[i].a,&edge[i].b,&edge[i].c);
        sort(edge,edge+m);
        for(int i=1;i<=n;i++)fa[i]=i,vis[i]=0;
        int pre=-1;
        ans=1;
        for(int h=0;h<=m;h++)
        {
            if(edge[h].c!=pre||h==m)
            {
                for(int i=1;i<=n;i++)
                    if(vis[i])
                    {
                        int u=findfa(i,ka);
                        gra[u].push_back(i);
                        vis[i]=0;
                    }
                for(int i=1;i<=n;i++)
                    if(gra[i].size()>1)
                    {
                        for(int a=1;a<=n;a++)
                            for(int b=1;b<=n;b++)
                                tmp[a][b]=0;
                        int len=gra[i].size();
                        for(int a=0;a<len;a++)
                            for(int b=a+1;b<len;b++)
                            {
                                int la=gra[i][a],lb=gra[i][b];
                                tmp[a][b]=(tmp[b][a]-=gk[la][lb]);
                                tmp[a][a]+=gk[la][lb];tmp[b][b]+=gk[la][lb];
                            }
                        long long ret=(long long)det(tmp,len);
                        ret%=mod;
                        ans=(ans*ret%mod)%mod;
                        for(int a=0;a<len;a++)fa[gra[i][a]]=i;
                    }
                for(int i=1;i<=n;i++)
                {
                    ka[i]=fa[i]=findfa(i,fa);
                    gra[i].clear();
                }
                if(h==m)break;
                pre=edge[h].c;
            }
            int a=edge[h].a,b=edge[h].b;
            int pa=findfa(a,fa),pb=findfa(b,fa);
            if(pa==pb)continue;
            vis[pa]=vis[pb]=1;
            ka[findfa(pa,ka)]=findfa(pb,ka);
            gk[pa][pb]++;gk[pb][pa]++;
        }
        int flag=0;
        for(int i=2;i<=n&&!flag;i++)if(ka[i]!=ka[i-1])flag=1;
        ans%=mod;
        printf("%I64d\n",flag?0:ans);
    }
    return 0;
}
