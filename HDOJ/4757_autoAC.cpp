#include <cstdio>
#include <cstring>
#include <algorithm>
#define maxn 200010
using namespace std;
struct ww {
    int son[2];
    int cnt;
    ww() {
        cnt=0;
        memset(son,0,sizeof son);
    }
}t[maxn<<5];
int n,m,l,tot;
int a[maxn],pre[maxn<<1],other[maxn<<1],last[maxn],que[maxn],dis[maxn],jump[maxn][20];
void connect(int x,int y) {
    pre[++l]=last[x];
    last[x]=l;
    other[l]=y;
}
int lca(int x,int y) {
    if (dis[x]>dis[y]) swap(x,y);
    int dep=dis[y]-dis[x];
    for (int i=0;i<=18;i++) if (dep&(1<<i)) y=jump[y][i];
    if (x==y) return x;
    for (int i=18;i>=0;i--) if (jump[x][i]!=jump[y][i]) x=jump[x][i],y=jump[y][i];
    return jump[x][0];
}
void build(int &x,int dep) {
    if (!x) x=++tot;
    if (dep<0) return ;
    build(t[x].son[0],dep-1); build(t[x].son[1],dep-1);
}    
void insert(int &x,int rot,int dep,int key) {
    if (!x) x=++tot;
    if (dep==-2) return ; 
    if (key&(1<<dep)) {
        insert(t[x].son[1],t[rot].son[1],dep-1,key);
        t[x].son[0]=t[rot].son[0];
    } else {
        insert(t[x].son[0],t[rot].son[0],dep-1,key);
        t[x].son[1]=t[rot].son[1];
    }
    t[x].cnt+=t[rot].cnt+1;
}
int query(int rx,int lx,int key,int dep) {
    if (dep==-2) return 0;
    int ans=0;
    if (key&(1<<dep)) {
        if (t[t[rx].son[0]].cnt-t[t[lx].son[0]].cnt) {
            ans=1<<dep;
            ans+=query(t[rx].son[0],t[lx].son[0],key,dep-1);
        } else ans=query(t[rx].son[1],t[lx].son[1],key,dep-1);
    } else {
        if (t[t[rx].son[1]].cnt-t[t[lx].son[1]].cnt) {
            ans=1<<dep;
            ans+=query(t[rx].son[1],t[lx].son[1],key,dep-1);
        } else ans=query(t[rx].son[0],t[lx].son[0],key,dep-1);
    }
    return ans;
}
void work() {
     memset(t,0,sizeof t);
    memset(last,0,sizeof last);
    memset(dis,0,sizeof dis);
    tot=n; l=0;
    for (int i=1;i<=n;i++) scanf("%d",&a[i]);
    for (int i=1;i<n;i++) {
        int x,y; scanf("%d%d",&x,&y);
        connect(x,y); connect(y,x);
    }
    int head=0,tail=1; que[1]=1; dis[1]=1;
    while (head<tail) {
        int cur=que[++head];
        for (int p=last[cur];p;p=pre[p]) {
            if (dis[other[p]]) continue;
            que[++tail]=other[p]; dis[other[p]]=dis[cur]+1;
        }
    }
    jump[1][0]=++tot;
    for (int i=1;i<=n;i++) 
        for (int p=last[que[i]];p;p=pre[p]) 
            if (dis[other[p]]>dis[que[i]]) jump[other[p]][0]=que[i];
    for (int i=1;i<=18;i++)
        for (int j=1;j<=n;j++){
            int cur=que[j];
            jump[cur][i]=jump[jump[cur][i-1]][i-1];
        }
    build(jump[1][0],15);
    for (int i=1;i<=n;i++) insert(que[i],jump[que[i]][0],15,a[que[i]]);
    while (m--) {
        int x,y,z; scanf("%d%d%d",&x,&y,&z);
        int root=lca(x,y);
        int ans=0;
        ans=max(query(x,jump[root][0],z,15),query(y,jump[root][0],z,15));
        printf("%d\n",ans);
    }
}
int main() {
    while (scanf("%d%d",&n,&m)!=EOF) work(); 
    return 0;
}
