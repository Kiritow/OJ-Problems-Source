#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>
using namespace std;
const int maxn = 1e6+10;
typedef long long LL;
int dp[maxn];
int head[maxn],ip;
LL cnt[maxn];
int n;
struct nod{
    int to,next,w;
}edge[maxn];
bool vis[maxn];
void init(){
    ip=0;
    memset(head,-1,sizeof(head));
    memset(cnt,0,sizeof(cnt));
    memset(vis,0,sizeof(vis));
}
void add(int u,int v,int w){
    edge[ip].to=v;
    edge[ip].w=w;
    edge[ip].next=head[u];
    head[u]=ip++;
}
int mmax;
void dfs(int u,int pre,int val){
    for(int i=head[u];i!=-1;i=edge[i].next){
        int v= edge[i].to;
        if(v==pre) continue;
        if(edge[i].w^val>mmax)
            mmax = edge[i].w^val;
        cnt[edge[i].w^val]++;
        dfs(v,u,val^edge[i].w);
    }
}
int main()
{
    int t,m;
    scanf("%d",&t);
    while(t--){
        init();
        scanf("%d",&n);
        for(int i=0;i<n-1;i++){
            int u,v,w;
            scanf("%d%d%d",&u,&v,&w);
            add(u,v,w);
            add(v,u,w);
        }
        mmax = 0;
        dfs(1,1,0);
        scanf("%d",&m);
        cnt[0]++;
        for(int i=0;i<m;i++){
            int s;
            scanf("%d",&s);
            LL ans = 0;
            for(int j=0;j<maxn;j++){
                if((s^j)==j) ans=ans+(cnt[j]*(cnt[j]-1));
                else ans = ans=ans+cnt[j]*cnt[s^j];
            }
            ans=ans/2;
            if(s==0) ans=ans+n;
            printf("%I64d\n",ans);
        }
    }
    return 0;
}
