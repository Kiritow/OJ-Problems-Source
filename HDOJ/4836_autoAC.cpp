#include <stdio.h>
#include <vector>
#include <string>
#include <queue>
#include <string.h>
#include <algorithm>
using namespace std;
#define repe(i,now) for(int i=head[now];i!=-1;i=edge[i].next)
#define rep(i,s,t) for(int i=s;i<t;i++)
#define clr(a,v) memset(a,v,sizeof a)
#define L t<<1
#define R t<<1|1
#define lowbit(x) (x&(-x))
const int N=10005;
struct Edge{
    int v,next;
}edge[N*2];
int head[N],e;
int t,n,a,b,v[N],to[N],rTo[N],last[N],fa[N][20],dep[N],cnt,q,x,y,all,r;
char op[10];
int c[N];
inline void add(int x,int v){
    while(x<=n){
        c[x]+=v;x+=lowbit(x);
    }
}
inline int sum(int x){
    int a=0;
    while(x>0){
        a+=c[x];x-=lowbit(x);
    }
    return a;
}
inline void addEdge(int u,int v){
    edge[e].v=v;
    edge[e].next=head[u];
    head[u]=e++;
}
inline void dfs(int now,int pre){
    to[now]=(++cnt);rTo[cnt]=now;
    fa[now][0]=pre;
    dep[now]=dep[pre]+1;
    rep(i,1,20) fa[now][i]=fa[fa[now][i-1]][i-1];
    repe(i,now){
        int nxt=edge[i].v;
        if(nxt!=pre){
            dfs(nxt,now);
        }
    }
    last[now]=cnt;
}
inline int lca(int a,int b){
    if(dep[a]>dep[b]) swap(a,b);
    int ha=dep[a],hb=dep[b];
    int ta=a,tb=b;
    int det=hb-ha;
    rep(i,0,20){
        if(det&(1<<i)){
            tb=fa[tb][i];
        }
    }
    if(ta==tb) return ta;
    for(int i=19;i>=0;i--){
        if(fa[ta][i]==fa[tb][i]) continue;
        ta=fa[ta][i];
        tb=fa[tb][i];
    }
    return fa[ta][0];
}
inline void Init(){
    scanf("%d",&n);
    clr(head,-1),e=all=cnt=0;
    r=1;
    rep(i,1,n){
        scanf("%d%d",&a,&b);
        addEdge(a,b);
        addEdge(b,a);
    }
    rep(i,1,n+1) scanf("%d",&v[i]),all+=v[i];
    fa[1][0]=1;
    dep[0]=0;
    dfs(1,0);
}
inline int find(int x,int y){
    int det=dep[y]-dep[x]-1;
    rep(i,0,20){
        if(det&(1<<i)){
            y=fa[y][i];
        }
    }
    return y;
}
inline void Work(){
    clr(c,0);
    rep(i,1,n+1) add(to[i],v[i]);
    scanf("%d",&q);
    rep(i,0,q){
        scanf("%s",op);
        if(op[0]=='Q'){
            scanf("%d",&x);
            a=lca(x,r);
            if(x==r){
                printf("%d\n",all);
            }
            else if(a!=x){
                printf("%d\n",sum(last[x])-sum(to[x]-1));
            }
            else{
               b=find(x,r);
               printf("%d\n",all-sum(last[b])+sum(to[b]-1));
            }
        }
        else if(op[0]=='R'){
            scanf("%d",&x);r=x;
        }
        else{
            scanf("%d%d",&x,&y);
            add(to[x],y-v[x]);
            all+=y-v[x];
            v[x]=y;
        }
    }
}
int main(){
    scanf("%d",&t);
    rep(ca,1,t+1){
        printf("Case #%d:\n",ca);
        Init();
        Work();
    }
    return 0;
}
