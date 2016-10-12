#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
 
using namespace std;
typedef long long ll;
const int maxn = 1e5+10;
#define pii pair<int,int>
#define fi first
#define se second
#define mp make_pair
 
int N, M, P;
int color[maxn];
struct edge
{
        int v,next,w;
        edge() {}
        edge(int v,int next,int w):v(v),next(next),w(w) {}
}E[maxn<<1];
int h[maxn], edge_cnt, pos_cnt;
int deep[maxn], fa[maxn][20], top[maxn], son[maxn], size[maxn], pos[maxn];
int L, R;
inline void add_edge(int a,int b,int c)
{
        E[edge_cnt]=edge(b,h[a],c); h[a]=edge_cnt++;
        E[edge_cnt]=edge(a,h[b],c); h[b]=edge_cnt++;
}
void init()
{
        memset(h,-1,sizeof h);
        edge_cnt = pos_cnt = 0;
}
int Q[maxn];
void split()
{
        int r=0;
        Q[r++]=1; fa[1][0]=0;
        for(int i=0;i<r;i++)
        {
                int u=Q[i]; deep[u]=deep[fa[u][0]]+1; size[u]=1; son[u]=top[u]=0;
                for(int j=h[u];j!=-1;j=E[j].next)
                {
                        int v=E[j].v;
                        if(v!=fa[u][0]) {
                                fa[v][0]=u; Q[r++]=v;
                                color[v]=E[j].w;
                        }
                }
        }
        for(int i=r-1;i>0;i--)
        {
                int v=Q[i], u=fa[v][0];
                size[u]+=size[v];
                if(size[v]>size[son[u]]) son[u]=v;
        }
        for(int i=0;i<r;i++)
        {
                int u=Q[i];
                if(top[u]==0)
                        for(int v=u;v;v=son[v]) top[v]=u, pos[v]=++pos_cnt;
        }
        //    for(int i=1;i<=N;i++) printf("%d ", top[i]); putchar('\n');
        //  for(int i=1;i<=N;i++) printf("%d ", pos[i]); putchar('\n');
        //for(int i=1;i<=N;i++) printf("%d ", deep[i]); putchar('\n');
}
int value[maxn<<2], flag[maxn<<2], numl[maxn<<2], numr[maxn<<2];
inline void pushup(int o)
{
        value[o]=value[o<<1]+value[o<<1|1]-(numr[o<<1]==numl[o<<1|1]);
        numl[o]=numl[o<<1];
        numr[o]=numr[o<<1|1];
}
inline void pushdown(int o,int l,int r)
{
        if(l==r) return ;
        if(flag[o]!=-1) {
                flag[o<<1]=flag[o<<1|1]=flag[o];
                numl[o<<1]=numl[o<<1|1]=flag[o];
                numr[o<<1]=numr[o<<1|1]=flag[o];
                value[o<<1]=value[o<<1|1]=1;
                flag[o]=-1;
        }
}
void build()
{
        for(int i=0;i<maxn*4;i++) value[i]=1, flag[i]=-1;
}
void update(int o,int l,int r,int c)
{
        pushdown(o,l,r);
        if(L<=l&&r<=R) {
                value[o]=1; flag[o]=numl[o]=numr[o]=c; return ;
        }
        int m=(l+r)/2;
        if(L<=m) update(o<<1,l,m,c);
        if(m<R) update(o<<1|1,m+1,r,c);
        pushup(o);
}
void update(int l,int r,int c)
{
        if(l>r) return;
        L=l; R=r;
        update(1,1,N,c);
}
int query(int o,int l,int r)
{
        pushdown(o,l,r);
        if(L<=l&&r<=R) {
                return value[o];
        }
        int m=(l+r)/2;
        int ret=0;
        if(L<=m) ret+=query(o<<1,l,m);
        if(m<R) ret+=query(o<<1|1,m+1,r);
        if(L<=m&&m<R) ret-=(numr[o<<1]==numl[o<<1|1]);
        return ret;
}
int query(int l,int r)
{
        L=l; R=r;
        int ret=query(1,1,N);
        //    printf("query %d %d %d \n", l, r, ret);
        return ret;
}
int yanse(int o,int l,int r,int f)
{
        if(l==r) return numl[o];
        pushdown(o,l,r);
        int m=(l+r)/2;
        if(f<=m) return yanse(o<<1,l,m,f);
        return yanse(o<<1|1,m+1,r,f);
}
int query(int l)
{
        return yanse(1,1,N,l);
}
void work(int u,int v,int c)
{
        int f1=top[u], f2=top[v];
        while(f1!=f2)
        {
                if(deep[f1]<deep[f2]) {
                        swap(u,v);
                        swap(f1,f2);
                }
                update(pos[f1],pos[u],c);
                u=fa[f1][0]; f1=top[u];
        }
        if(deep[u]>deep[v]) swap(u,v);
        update(pos[u]+1,pos[v],c);
}
inline int lca(int u,int v)
{
        if(deep[u]<deep[v]) swap(u,v);
        int c=deep[u]-deep[v];
        for(int i=0;i<20;i++) if(c&(1<<i)) u=fa[u][i];
        if(u==v) return u;
        for(int i=19;i>=0;i--)
        {
                if(fa[u][i]!=fa[v][i])
                {
                        u=fa[u][i];
                        v=fa[v][i];
                }
        }
        return fa[u][0];
}
inline int find_next_root(int u,int r) {
        if(u==r) return -1;
        int c=deep[u]-deep[r]-1;
//        printf("find_next_root %d\n", c);
        for(int i=0;i<20;i++) if(c&(1<<i)) u=fa[u][i];
        return u;
}
inline int find(int u,int v)
{
        int ret=0;
        while(deep[top[u]]>deep[v])
        {
                ret+=query(pos[top[u]],pos[u]);
                u=top[u];
                ret-=(query(pos[u])==query(pos[fa[u][0]]));
                u=fa[u][0];
        }
        return ret+query(pos[v],pos[u]);
}
 
int main(int argc,char *argv[])
{
        if(argc>1) {
                freopen( argv[1], "r", stdin );
        }
 
        while(cin>>N>>P) {
                init();
        //        for(int i=1;i<=N;i++) scanf("%d", color+i);
                for(int i=1;i<N;i++)
                {
                        int a,b,c; scanf("%d%d%d", &a, &b, &c );
                        add_edge(a,b,c);
                }
                split();
                fa[1][0]=1;
                for(int i=1;i<20;i++) for(int j=1;j<=N;j++)
                        fa[j][i]=fa[fa[j][i-1]][i-1];
                build();
                for(int i=2;i<=N;i++) update(pos[i],pos[i],color[i]);
                //  for(int i=1;i<=N;i++) printf("%d ", query(pos[i],pos[i]) ); putchar('\n');
 
                while( P-- )
                {
                        char op[20]; int a,b,c;
                        scanf("%s%d%d", op, &a, &b);
                        if(op[0]=='Q') {
                                c=lca(a,b);
                                int d=find_next_root(a,c);
                                int e=find_next_root(b,c);
//                                printf("%d %d %d %d %d \n", a,b,c,d,e);
//                                printf("%d\n", find(a,c)+find(b,c)-1 );
                                if(a==b) {
                                        puts("0");
                                } else if(c==a) {
                                        printf("%d\n", find(b,e) );
                                } else if(c==b) {
                                        printf("%d\n", find(a,d) );
                                } else {
                                        printf("%d\n", find(a,d)+find(b,e)-(query(pos[d])==query(pos[e])) );
                                }
                        } else {
                                scanf("%d", &c);
                                work(a,b,c);
                        }
                }
        }
        return 0;
}
