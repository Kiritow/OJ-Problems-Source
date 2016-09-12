#pragma comment(linker,"/STACK:102400000,102400000")
#include<stdio.h>
#include<string.h>
#include<iostream>
#include<vector>
#include<math.h>
#include<algorithm>
#define ll int
using namespace std;
const int maxn = 100000+10;
int t,n,m;
vector<int> g[maxn];
int fa[maxn][25],deep[maxn];
int cnt,l[maxn],r[maxn];
vector<int> lis[maxn];
void dfs(int u,int f,int d){
    l[u]=++cnt,deep[u]=d,fa[u][0]=f;
    for(int i=0;i<g[u].size();i++){
        int v=g[u][i];
        if(v==f) continue;
        dfs(v,u,d+1);
    }
    r[u]=++cnt;
}
void init(){
    cnt=0; dfs(1,0,1);
    for(int i=1;i<=20;i++) for(int j=1;j<=n;j++) fa[j][i]=fa[fa[j][i-1]][i-1];
    for(int i=1;i<=n;i++) lis[i].clear();
}
int lca(int x, int y) {
    if (deep[x] < deep[y]) swap(x, y);
    int delta = deep[x] - deep[y];
    for(int j=0;j<=20;j++) if ((1<<j) & delta) x = fa[x][j];
    if (x == y) return x;
    for(int j=20;j>=0;j--) if (fa[x][j] != fa[y][j]) x = fa[x][j], y = fa[y][j];
    return fa[x][0];
}
int st[maxn],en[maxn],quan[maxn];
int dp[maxn],sum[maxn],sd[maxn<<1],ss[maxn<<1];
int lowbit(int x) { return x&(-x); }
void Add(int id,int x,int c[]) { for(int i=id;i<=2*n;i+=lowbit(i)) c[i]+=x; }
int Sum(int id,int c[]) { int tmp=0; for(int i=id;i>0;i-=lowbit(i)) tmp+=c[i]; return tmp; }
void dfs2(int u,int f){
    for(int i=0;i<g[u].size();i++){
        int v=g[u][i];
        if(v==f) continue;
        dfs2(v,u);
        sum[u]+=dp[v];
    }
    dp[u]=sum[u];
    for(int i=0;i<lis[u].size();i++){
        int id=lis[u][i],s=st[id],t=en[id],w=quan[id];
        int tmp=Sum(l[s],ss)+Sum(l[t],ss)-Sum(l[s],sd)-Sum(l[t],sd)+sum[u];
        dp[u]=max(dp[u],tmp+w);
    }
    Add(l[u],dp[u],sd),Add(r[u],-dp[u],sd),Add(l[u],sum[u],ss),Add(r[u],-sum[u],ss);
}
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++) g[i].clear();
        for(int i=1;i<n;i++) { int u,v; scanf("%d%d",&u,&v); g[u].push_back(v); g[v].push_back(u); }
        init();
        for(int i=1;i<=m;i++){
            scanf("%d%d%d",&st[i],&en[i],&quan[i]);
            int tmp=lca(st[i],en[i]); lis[tmp].push_back(i);
        }
        memset(dp,0,sizeof(dp)); memset(sum,0,sizeof(sum)); memset(sd,0,sizeof(sd)); memset(ss,0,sizeof(ss));
        dfs2(1,0);
        printf("%d\n",dp[1]);
    }
    return 0;
}
