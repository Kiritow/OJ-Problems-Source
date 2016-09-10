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
using namespace std;
const int MAXN = 100010;
const int INF = 0x3f3f3f3f;
struct Edge{
    int to,next,w;
}edge[MAXN*2];
int head[MAXN],tot;
void init(){
    tot = 0;
    memset(head,-1,sizeof(head));
}
inline void addedge(int u,int v,int w){
    edge[tot].to = v;
    edge[tot].w = w;
    edge[tot].next = head[u];
    head[u] = tot++;
}
int size[MAXN],vis[MAXN],fa[MAXN],que[MAXN];
int TT;
inline int getroot(int u){
    int Min = MAXN, root = 0;
    int l,r;
    que[l = r = 1] = u;
    fa[u] = 0;
    for(;l <= r;l++)
        for(int i = head[que[l]]; i != -1;i = edge[i].next){
            int v = edge[i].to;
            if(v == fa[que[l]] || vis[v] == TT)continue;
            que[++r] = v;
            fa[v] = que[l];
        }
    for(l--;l;l--){
        int x = que[l], Max = 0;
        size[x] = 1;
        for(int i = head[x];i != -1;i = edge[i].next){
            int v = edge[i].to;
            if(v == fa[x] || vis[v] == TT)continue;
            Max = max(Max,size[v]);
            size[x] += size[v];
        }
        Max = max(Max,r - size[x]);
        if(Max < Min){
            Min = Max; root = x;
        }
    }
    return root;
}
int ans[MAXN];
pair<int,int>pp[MAXN];
pair<int,int>np[MAXN];
int dis[MAXN];
int type[MAXN];
inline void go(int u,int pre,int w,int tt){
    int l,r;
    que[l = r = 1] = u;
    fa[u] = pre; dis[u] = w;
    for(;l <= r;l++)
        for(int i = head[que[l]];i != -1;i = edge[i].next){
            int v = edge[i].to;
            if(v == fa[que[l]] || vis[v] == TT)continue;
            que[++r] = v;
            fa[v] = que[l];
            dis[v] = dis[que[l]] + edge[i].w;
        }
    int cnt = 0;
    for(int i = 1;i <= r;i++){
        int x = que[i];
        pp[cnt++] = make_pair(np[x].first-dis[x],np[x].second);
    }
    sort(pp,pp+cnt);
    for(int i = 1;i <= r;i++){
        int x = que[i];
        if(type[x])continue;
        int id = lower_bound(pp,pp+cnt,make_pair(dis[x],x)) - pp;
        ans[x] += (cnt-id)*tt;
    }
}
void solve(int u){
    int root = getroot(u);
    vis[root] = TT;
    go(root,0,0,1);
    for(int i = head[root];i != -1;i = edge[i].next){
        int v = edge[i].to;
        if(vis[v] == TT)continue;
        go(v,root,edge[i].w,-1);
    }
    for(int i = head[root];i != -1;i = edge[i].next){
        int v = edge[i].to;
        if(vis[v] == TT)continue;
        solve(v);
    }
}
bool ff[MAXN];
int main()
{
    int n;
    memset(vis,0,sizeof(vis));
    TT = 0;
    while(scanf("%d",&n) == 1){
        init();
        int u,v,w;
        for(int i = 1;i < n;i++){
            scanf("%d%d%d",&u,&v,&w);
            addedge(u,v,w);
            addedge(v,u,w);
        }
        for(int i = 1;i <= n;i++)scanf("%d",&type[i]);
        queue<int>q;
        for(int i = 1;i <= n;i++){
            if(type[i]){
                np[i] = make_pair(0,i);
                ff[i] = true;
                q.push(i);
            }
            else{
                np[i] = make_pair(INF,0);
                ff[i] = false;
            }
        }
        while(!q.empty()){
            u = q.front();
            q.pop();
            ff[u] = false;
            for(int i = head[u];i != -1;i = edge[i].next){
                v = edge[i].to;
                pair<int,int>tmp = make_pair(np[u].first+edge[i].w,np[u].second);
                if(tmp < np[v]){
                    np[v] = tmp;
                    if(!ff[v]){
                        ff[v] = true;
                        q.push(v);
                    }
                }
            }
        }
        TT++;
        for(int i = 1;i <= n;i++)ans[i] = 0;
        solve(1);
        int ret = 0;
        for(int i = 1;i <= n;i++)ret = max(ret,ans[i]);
        printf("%d\n",ret);
    }
    return 0;
}
