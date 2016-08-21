#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;
const int maxn=50500;
const double zero=1e-8;
const double inf=1e10;
int n,K,m,L,tot,root,ans;
int E[maxn],pre[maxn],fst[maxn];
int V[maxn],ft[maxn],pl[maxn],pr[maxn],f[maxn][110],g[maxn][110],h[maxn],q[maxn];
struct Event
{
       double x,y,r,px; int id,v;
       Event(){};
       Event(double _x,double _y,double _r,double _px,int i,int _v) {x=_x; y=_y; r=_r; px=_px; id=i; v=_v;};
       bool operator <(const Event &rhs)const
       {
            return px+zero<rhs.px;
       }
       double gety(double x0,int v0)
       {
              if(fabs(x0-x)+zero>=r) return y;
              double tmp=sqrt(r*r-(x-x0)*(x-x0));
              if(v0==0) return y-tmp; else return y+tmp;
       }
}Et[2*maxn];
struct Tree
{
       int ft,lc,rc,x,v;
       void clear() {ft=lc=rc=x=v=0;}
}tr[4*maxn];
struct Splay
{
       void New(int i)
       {
            tr[++tot].clear(); tr[tot].x=i; tr[tot].v=0; tr[tot].rc=tot+1; pl[Et[i].id]=tot;
            tr[++tot].clear(); tr[tot].x=i; tr[tot].v=1; tr[tot].ft=tot-1; pr[Et[i].id]=tot;
       }
       void rotate(int x)
       {
            int y=tr[x].ft,z=tr[y].ft;
            if(tr[z].lc==y) tr[z].lc=x; else tr[z].rc=x;
            tr[x].ft=z; tr[y].ft=x;
            if(tr[y].lc==x) tr[y].lc=tr[x].rc,tr[tr[x].rc].ft=y,tr[x].rc=y;
               else tr[y].rc=tr[x].lc,tr[tr[x].lc].ft=y,tr[x].lc=y;
       }
       void splay(int x,int p)
       {
            int fa=tr[p].ft;
            while(tr[x].ft!=fa)
            {
                  int y=tr[x].ft,z=tr[y].ft;
                  if(z==fa) {rotate(x); continue;}
                  if((tr[y].lc==x)^(tr[z].lc==y)) rotate(x); else rotate(y);
                  rotate(x);
            }
            if(p==root) root=x;
       }
       int select(int i)
       {
           int p=root,ql=p,qr=p; double x=Et[i].px,y=Et[i].y;
           while(p>0)
           {
                 int id=tr[p].x,v=tr[p].v; double y0;
                 if(id==0) y0=v?inf:-inf; else y0=Et[id].gety(x,v);
                 if(y0+zero<y) ql=p,p=tr[p].rc; else qr=p,p=tr[p].lc;
           }
           splay(ql,root); splay(qr,tr[root].rc);
           return qr;
       }
       int getpre(int x)
       {
           splay(x,root);
           int p=tr[x].lc; while(tr[p].rc) p=tr[p].rc;
           return p;
       }
       int getnext(int x)
       {
           splay(x,root);
           int p=tr[x].rc; while(tr[p].lc) p=tr[p].lc;
           return p;
       }
}Tr;
int get()
{
    int f=0,v=0; char ch;
    while(!isdigit(ch=getchar())) if(ch=='-') break;
    if(ch=='-') f=1; else v=ch-48;
    while(isdigit(ch=getchar())) v=v*10+ch-48;
    if(f) return -v; else return v;
}
void init()
{
     m=0; int x,y,r;
     n=get(); K=get()+1;
     for(int i=1;i<=n;i++)
     {
         x=get(); y=get(); r=get(); V[i]=get();
         Et[++m]=Event(x,y,r,x-r,i,1);
         Et[++m]=Event(x,y,r,x+r,i,0);
     }
}
void add(int a,int b)
{
     E[++L]=b; pre[L]=fst[a]; fst[a]=L;
}
void build()
{
     tot=L=0; root=1;
     memset(fst,0,sizeof(fst));
     tr[0].clear(); Tr.New(0);
     sort(Et+1,Et+m+1);
     for(int i=1;i<=m;i++)
         if(Et[i].v)
         {
            Tr.New(i);
            int k=Tr.select(i); tr[tot-1].ft=k; tr[k].lc=tot-1;
            ft[Et[i].id]=(tr[k].v)?Et[tr[k].x].id:ft[Et[tr[k].x].id];
            add(ft[Et[i].id],Et[i].id);
         }else
         {
            int a=Tr.getpre(pl[Et[i].id]),b=Tr.getnext(pr[Et[i].id]);
            Tr.splay(a,root); Tr.splay(b,tr[root].rc);
            tr[tr[b].lc].ft=0; tr[b].lc=0;
         }
}
void bfs()
{
     int head=1,tail=2; q[head]=0;
     while(head<tail)
     {
           int u=q[head];
           for(int k=fst[u];k;k=pre[k]) q[tail++]=E[k];
           head++;
     }
}
void dp()
{
     for(int i=n+1;i>1;i--)
     {
         int u=q[i]; h[u]=0;
         for(int j=1;j<=K;j++) f[u][j]=g[u][j]=V[u];
         for(int k=fst[u];k;k=pre[k])
         {
             for(int j=1;j<K;j++)
                 h[u]=max(h[u],max(abs(f[E[k]][j]-g[u][K-j]),abs(g[E[k]][j]-f[u][K-j])));
             for(int j=2;j<K;j++)
             {
                 f[u][j]=min(f[u][j],f[E[k]][j-1]);
                 g[u][j]=max(g[u][j],g[E[k]][j-1]);
             }
         }
     }
     h[0]=0; int k=fst[0];
     for(int j=2;j<=K;j++) f[0][j]=f[E[k]][j-1],g[0][j]=g[E[k]][j-1];
     for(k=pre[k];k;k=pre[k])
     {
         for(int j=1;j<K-1;j++)
             h[0]=max(h[0],max(abs(f[E[k]][j]-g[0][K-j]),abs(g[E[k]][j]-f[0][K-j])));
         for(int j=2;j<K;j++)
         {
             f[0][j]=min(f[0][j],f[E[k]][j-1]);
             g[0][j]=max(g[0][j],g[E[k]][j-1]);
         }
     }
}
void work()
{
     build(); bfs(); dp();
     ans=0;
     for(int i=0;i<=n;i++) ans=max(ans,h[i]);
     printf("%d\n",ans);
}
int main()
{
    int TT=get();
    for(int i=1;i<=TT;i++)
    {
        printf("Case %d: ",i);
        init();
        work();
    }
    return 0;
}
