#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include <iostream>
#include<climits>
using namespace std;
const int N = 1000;
const int M = 100000;
int n;
int ecnt, head[N], nx[M], to[M], va[M], cur_edge[N];
int source, target, flow, pre[N], lev[N], qu[N], sign;
void addedge(int u, int v, int w) {
    to[ecnt] = v;
    nx[ecnt] = head[u];
    va[ecnt] = w;
    head[u] = ecnt++;
}
bool bfs(int s, int t) {
    std::fill(lev, lev + n, -1);
    sign = t;
    lev[t] = 0;
    int st = 0, ed = 0;
    qu[ed++] = t;
    while (st != ed && lev[s] == -1) {
        int u = qu[st++];
        for (int i = head[u]; i != -1; i = nx[i]) {
            if (va[i ^ 1] > 0 && lev[to[i]] == -1) {
                lev[to[i]] = lev[u] + 1;
                qu[ed++] = to[i];
            }
        }
    }
    return lev[s] != -1;
}
void push() {
    int delta = INT_MAX, u, p;
    for (u = target; u != source; u = to[p ^ 1]) {
        p = pre[u];
        delta = std::min(delta, va[p]);
    }
    for (u = target; u != source; u = to[p ^ 1]) {
        p = pre[u];
        va[p] -= delta;
        if (!va[p]) {
            sign = to[p ^ 1];
        }
        va[p ^ 1] += delta;
    }
    flow += delta;
}
void dfs(int u) {
    if (u == target)
        push();
    else {
        for (int i = cur_edge[u]; i != -1; i = nx[i]) {
            if (va[i] > 0 && lev[u] == lev[to[i]] + 1) {
                pre[to[i]] = i;
                dfs(to[i]);
                if (lev[sign] > lev[u]) {
                    return;
                }
                sign = target;
            }
        }
        lev[u] = -1;
    }
}
int nc, pc, tc;
int lx[M], ly[M], lv[M];
void dinic(int s, int t, int node_cnt) {
    source = s;
    target = t;
    n = node_cnt;
    flow = 0;
    while (bfs(source, target)) {
        for (int i = 0; i < n; ++i) {
            cur_edge[i] = head[i];
        }
        dfs(source);
    }
}
int in[500],out[500];
void solve() {
    int n,m;
    memset(in,0,sizeof(in));
    memset(out,0,sizeof(out));
    scanf("%d%d",&n,&m);
    fill(head,head+n+10,-1);
    ecnt=0;
    for(int i=0;i<m;++i)
    {
        int u,v,x,y;
        scanf("%d%d%d%d",&u,&v,&x,&y);
        in[v]+=x;
        in[u]-=x;
        addedge(u,v,y);
        addedge(v,u,0);
    }
    int s,t;
    s=0;t=n+1;
    int sum=0;
    for(int i=1;i<=n;++i)
    {
        if(in[i]>0)
        {
            sum+=in[i];
            addedge(s,i,in[i]);
            addedge(i,s,0);
        }
        else
        {
            addedge(i,t,-in[i]);
            addedge(t,i,0);
        }
    }
    dinic(s,t,t+2);
    if(flow==sum)puts("happy");
    else puts("unhappy");
}
int main() {
    int ri=0,tt;
    scanf("%d",&tt);
    while(tt--)
    {
        printf("Case #%d: ",++ri);
        solve();
    }
    return 0;
}
