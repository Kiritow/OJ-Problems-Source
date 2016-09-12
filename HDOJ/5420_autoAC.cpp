#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <set>
#include <vector>
#include <map>
#include <queue>
#include <set>
#include <algorithm>
#include <limits>
using namespace std;
typedef long long LL;
const int MAXN=100000+1000;
const int MAXM=MAXN*20;
const int INF = numeric_limits<int>::max();
const LL LL_INF= numeric_limits<LL>::max();
struct Edge {
    int to,next;
    Edge(){}
    Edge(int _to,int _next):to(_to),next(_next){}
}e[MAXM<<3];
int head[MAXM],tot;
void init(){
    memset(head,-1,sizeof(head));
    tot=0;
}
void AddEdge(int u,int v){
    e[tot]=Edge(v,head[u]);
    head[u]=tot++;
}
typedef pair<int,int> ii;
vector <ii> t[MAXN<<2];
int d[MAXN],L[MAXN],R[MAXN],dep[MAXN],ncnt,rid[MAXN],n,Begin[MAXN<<2];
void dfs(int u,int d){
    L[u]=++ncnt;
    rid[ncnt]=u;
    dep[u]=d;
    for(int i=head[u];~i;i=e[i].next)
        dfs(e[i].to,d+1);
    R[u]=ncnt;
}
#define lson L,mid,rt<<1
#define rson mid+1,R,rt<<1|1
void build(int L,int R,int rt){
    t[rt].resize(R-L+1);
    if(L==R){
        Begin[rt]=n+1;
        t[rt][0]=make_pair(dep[rid[L]],rid[L]);
        ++n;
        AddEdge(n,rid[L]);
        return ;
    }
    int mid=(L+R)>>1;
    build(lson);build(rson);
    merge(t[rt<<1].begin(),t[rt<<1].end(),t[rt<<1|1].begin(),t[rt<<1|1].end(),t[rt].begin());
    Begin[rt]=n+1;
    for(int i=1;i<R-L+1;i++)AddEdge(n+1+i,n+i);
    for(int i=0;i<R-L+1;i++)AddEdge(n+1+i,t[rt][i].second);
    n+=R-L+1;
}
void connect(int L,int R,int rt,int l,int r,int x,int d){
    if(l<=L&&R<=r){
        int pos=lower_bound(t[rt].begin(),t[rt].end(),make_pair(d,1<<30))-t[rt].begin()-1;
        if(~pos)AddEdge(x,Begin[rt]+pos);
        return ;
    }
    int mid=(L+R)>>1;
    if(l<=mid)connect(lson,l,r,x,d);
    if(r>mid)connect(rson,l,r,x,d);
}
int dfn[MAXM],low[MAXM],sta[MAXM],top,times,bleg[MAXM],cnt[MAXM];
void tarjan(int u){
    low[u]=dfn[u]=++times;
    sta[++top]=u;
    for(int i=head[u];~i;i=e[i].next){
        int v=e[i].to;
        if(!dfn[v]){
            tarjan(v);
            low[u]=min(low[u],low[v]);
        }
        else if(!bleg[v])
            low[u]=min(low[u],dfn[v]);
    }
    if(dfn[u]==low[u]){
        bleg[0]++;
        cnt[bleg[0]]=0;
        do{
            bleg[sta[top]]=bleg[0];
            cnt[bleg[0]]+=(sta[top]<=ncnt);
        }while(sta[top--]!=u);
    }
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        init();
        for(int i=2,x;i<=n;i++){
            scanf("%d",&x);
            AddEdge(x,i);
        }
        ncnt=0;
        dfs(1,0);
        init();
        build(1,ncnt,1);
        for(int i=1,x,y;i<=ncnt;i++){
            scanf("%d%d",&x,&y);
            connect(1,ncnt,1,L[x],R[x],i,dep[x]+y);
        }
        memset(dfn,0,sizeof(dfn));
        memset(bleg,0,sizeof(bleg));
        top=times=0;
        for(int i=1;i<=n;i++)if(!dfn[i])tarjan(i);
        LL ans=0;
        for(int i=1;i<=bleg[0];i++){
            ans+=(LL)cnt[i]*(cnt[i]-1)/2;
        }
        printf("%I64d\n",ans);
    }
    return 0;
}
