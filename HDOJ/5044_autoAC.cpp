#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>
using namespace std;
const int MAXN = 100010;
struct Edge{
    int to,next;
    int index;
}edge[MAXN*2];
int head[MAXN],tot;
void init(){
    tot = 0;
    memset(head,-1,sizeof(head));
}
inline void addedge(int u,int v,int index){
    edge[tot].to = v;
    edge[tot].next = head[u];
    edge[tot].index = index;
    head[u] = tot++;
}
int F[MAXN];
inline int find(int x){
    if(F[x] == -1)return x;
    return F[x] = find(F[x]);
}
inline void bing(int x,int y){
    int t1 = find(x);
    int t2 = find(y);
    if(t1 != t2)F[t1] = t2;
}
long long PF[MAXN],EF[MAXN];
struct Node{
    int id;
    int v,val;
    int next;
    Node(int _id = 0,int _v = 0,int _val = 0){
        id = _id;
        v = _v;
        val = _val;
    }
}query[MAXN*2];
int h[MAXN];
int tt;
inline void init2(){
    tt = 0;
    memset(h,-1,sizeof(h));
}
inline void add_query(int u,int v,int id,int val){
    query[tt].id = id;
    query[tt].next = h[u];
    query[tt].v = v;
    query[tt].val = val;
    h[u] = tt++;
}
bool vis[MAXN];
int fa[MAXN];
bool ff[MAXN];
int sta[MAXN];
int cur[MAXN];
void dfs1(int u,int pre){
    memcpy(cur,head,sizeof(head));
    memset(ff,false,sizeof(ff));
    fa[1] = -1;
    int top = 0;
    sta[top++] = 1;
    while(top != 0){
        u = sta[top-1];
        if(!ff[u])ff[u] = true;
        bool flag = false;
        for(int i = cur[u];i != -1;i = edge[i].next){
            int v = edge[i].to;
            if(ff[v])continue;
            fa[v] = u;
            sta[top++] = v;
            flag = true;
            cur[u] = edge[i].next;
            break;
        }
        if(!flag){
            top--;
            for(int i = h[u];i != -1;i = query[i].next){
                int v = query[i].v;
                int type = query[i].id;
                int w = query[i].val;
                if(vis[v]){
                    if(type == 1){
                        PF[find(v)] -= w;
                        if(fa[find(v)] != -1)PF[fa[find(v)]] -= w;
                        PF[v] += w;
                    }
                    else {
                        EF[find(v)] -= 2*w;
                        EF[v] += w;
                    }
                }
                else {
                    if(type == 1)PF[v] += w;
                    else EF[v] += w;
                }
            }
            if(fa[u] != -1)bing(u,fa[u]);
            vis[u] = true;
        }
    }
}
long long a[MAXN];
long long ans1[MAXN],ans2[MAXN];
int gg[MAXN];
void dfs2(int u,int pre){
    int l,r;
    gg[l = r = 1] = 1;
    for(;l <= r;l++)
        for(int i = head[gg[l]];i != -1;i = edge[i].next){
            int v = edge[i].to;
            if(v == fa[gg[l]])continue;
            gg[++r] = v;
        }
    for(l--;l;l--){
        u = gg[l];
        for(int i = head[u];i != -1;i = edge[i].next){
            int v = edge[i].to;
            if(v == fa[u])continue;
            EF[u] += EF[v];
            PF[u] += PF[v];
            ans2[edge[i].index] = EF[v];
        }
        ans1[u] = PF[u] + a[u];
    }
}
template <class T>
inline bool scan_d(T &ret) {
    char c; int sgn;
    if(c=getchar(),c==EOF) return 0; 
    while(c!='-'&&(c<'0'||c>'9')) c=getchar();
    sgn=(c=='-')?-1:1;
    ret=(c=='-')?0:(c-'0');
    while(c=getchar(),c>='0'&&c<='9') ret=ret*10+(c-'0');
    ret*=sgn;
    return 1;
}
inline void out(long long x) {
    if(x>9) out(x/10);
    putchar(x%10+'0');
}
int main()
{
    int n,m;
    int T;
    scanf("%d",&T);
    int iCase = 0;
    while(T--){
        iCase++;
        init();
        scan_d(n);
        scan_d(m);
        assert(n >= 1 && n <= 100000 && m >= 1 && m <= 100000);
        memset(a,0,sizeof(a));
        int u,v,w;
        for(int i = 1;i < n;i++){
            scan_d(u);
            scan_d(v);
            addedge(u,v,i);
            addedge(v,u,i);
        }
        char op[20];
        init2();
        while(m--){
            scanf("%s",op);
            scan_d(u);
            scan_d(v);
            scan_d(w);
            assert(u >= 1 && u <= n);
            assert(v >= 1 && v <= n);
            assert(abs(w) <= 100000);
            if(op[3] == '1'){
                if(u == v)a[u] += w;
                else {
                    add_query(u,v,1,w);
                    add_query(v,u,1,w);
                }
            }
            else {
                if(u == v)continue;
                else {
                    add_query(u,v,2,w);
                    add_query(v,u,2,w);
                }
            }
        }
        memset(PF,0,sizeof(PF));
        memset(EF,0,sizeof(EF));
        memset(F,-1,sizeof(F));
        memset(vis,false,sizeof(vis));
        dfs1(1,-1);
        dfs2(1,-1);
        printf("Case #%d:\n",iCase);
        for(int i = 1;i <= n;i++){
            out(ans1[i]);
            if(i < n)printf(" ");
            else printf("\n");
        }
        for(int i = 1;i < n;i++){
            out(ans2[i]);
            if(i < n-1)printf(" ");
        }
        printf("\n");
    }
    return 0;
}
