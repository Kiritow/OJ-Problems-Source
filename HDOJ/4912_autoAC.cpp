#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN=111111;
struct Edge{
    int from,to,next;
    Edge(){}
    Edge(int f,int t,int n):from(f),to(t),next(n){}
}edge[MAXN*2];
int head[MAXN],tot,fa[MAXN][20],dep[MAXN],q[MAXN],n,m;
bool vis[MAXN];
struct Qes{
    int u,v,lca;
    Qes(){}
    Qes(int _u,int _v,int _fa):u(_u),v(_v),lca(_fa){}
    bool operator<(const Qes&rhs)const{
        return dep[lca]>dep[rhs.lca];
    }
}qes[MAXN];
void init(){
    for(int i=1;i<=n;i++){
        head[i]=-1;
        vis[i]=0;
    }
    tot=0;
}
void add(int f,int t){
    edge[tot]=Edge(f,t,head[f]);
    head[f]=tot++;
}
void bfs(int root){
    int tail=0;
    q[tail++]=root;
    fa[root][0]=root;dep[root]=0;
    for(int i=0;i<tail;i++){
        int u=q[i];
        for(int i=1;i<20;i++) fa[u][i]=fa[fa[u][i-1]][i-1];
        for(int i=head[u];~i;i=edge[i].next){
            int v=edge[i].to;
            if(v==fa[u][0])continue;
            fa[v][0]=u;dep[v]=dep[u]+1;
            q[tail++]=v;
        }
    }
}
int Lca(int x,int y){
    if(dep[x]<dep[y]){int t=x;x=y;y=t;}
    for(int i=19;~i;i--) if((dep[x]-dep[y])&(1<<i))x=fa[x][i];
    if(x==y)return x;
    for(int i=19;~i;i--) if(fa[x][i]!=fa[y][i]){x=fa[x][i],y=fa[y][i];}
    return fa[x][0];
}
bool can(int u,int v,int lca){
    if(vis[u]||vis[v]||vis[lca]) return false;
    for(;u!=lca;u=fa[u][0])
        if(vis[u]) return false;
    for(;v!=lca;v=fa[v][0])
        if(vis[v]) return false;
    return true;
}
void cut(int u,int v,int lca){
    for(;u!=lca;u=fa[u][0])
        vis[u]=1;
    for(;v!=lca;v=fa[v][0])
        vis[v]=1;
    vis[lca]=1;
}
inline bool get(int &a){
    char c=0;
    a=0;
    do{
        c=getchar();
    }while(c!=EOF && (c<'0'||c>'9'));
    if(c==EOF)return false;
    while('0'<=c && c<='9'){a=a*10-'0'+c;c=getchar();}
    return true;
}
inline void ot(int a){
    if(a>9)
        ot(a/10);
    putchar(a%10+'0');
}
int main()
{
    while(get(n)){
        get(m);
        init();
        int u,v;
        for(int i=1;i<n;i++){
            get(u);
            get(v);
            add(u,v);
            add(v,u);
        }
        bfs(1);
        for(int i=0;i<m;i++){
            get(u);
            get(v);
            qes[i]=Qes(u,v,Lca(u,v));
        }
        sort(qes,qes+m);
        int ans=0;
        for(int i=0;i<m;i++){
            if(can(qes[i].u,qes[i].v,qes[i].lca)){
                cut(qes[i].u,qes[i].v,qes[i].lca);
                ans++;
            }
        }
        ot(ans);
        putchar('\n');
    }
    return 0;
}
