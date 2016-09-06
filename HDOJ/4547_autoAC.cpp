#include <iostream>
#include <cstdio>
#include <string>
#include <map>
#include <cstring>
using namespace std;
const int MAX_ = 400010;
map<string,int>mp;
struct point {
    int to,next, num;
} edge[MAX_], qedge[MAX_];
struct query {
    int u,v,lca;
} q[MAX_];
int V[MAX_], head[MAX_], d[MAX_], fa[MAX_], ind[MAX_];
bool vis[MAX_];
int M,L, T;
int n, m;
void adde(int from,int to,int c) {
    edge[M].to = to;
    edge[M].num = c;
    edge[M].next = V[from];
    V[from] = M++;
}
void addq(int from,int to,int c) {
    qedge[L].to = to;
    qedge[L].num = c;
    qedge[L].next = head[from];
    head[from] = L++;
}
int find(int x) {
    if(fa[x] == x)return fa[x];
    else return fa[x] = find(fa[x]);
}
void dfs(int k,int pri,int x) {
    d[x] = k;
    for(int i = V[x]; i != -1; i = edge[i].next) {
        if(edge[i].to != pri) {
            dfs(k+1,x,edge[i].to);
        }
    }
}
void tarjan(int x) {
    fa[x] = x;
    vis[x] = 1;
    for(int i = V[x]; i != -1; i = edge[i].next) {
        if(!vis[edge[i].to]) {
            tarjan(edge[i].to);
            fa[edge[i].to] = x;
        }
    }
    for(int i = head[x]; i != -1; i = qedge[i].next) {
        if(vis[qedge[i].to]) {
            q[qedge[i].num].lca = find(qedge[i].to);
        }
    }
}
void solve() {
    for(int i = 1; i <= n; i++) {
        if(ind[i] == 0) {
            dfs(0,-1,i);
            tarjan(i);
            break;
        }
    }
}
int capture(char s[]) {
    if(mp.find(s) == mp.end()) {
        return mp[s] = ++T;
    } else return mp[s];
}
void init() {
    memset(V,-1,sizeof(V));
    memset(head,-1,sizeof(head));
    memset(ind,0,sizeof(ind));
    memset(vis,0,sizeof(vis));
    M = L = T = 0;
    mp.clear();
    for(int i = 0; i <= n; i++) {
        fa[i] = i;
    }
}
void read() {
    int s,t;
    char c1[50],c2[50];
    for(int i = 1; i < n; i++) {
        scanf("%s",c1);
        scanf("%s",c2);
        t = capture(c1);
        s = capture(c2);
        adde(s,t,1);
        adde(t,s,1);
        ind[t]++;
    }
    for(int i = 0; i < m; i++) {
        scanf("%s",c1);
        scanf("%s",c2);
        t = capture(c1);
        s = capture(c2);
        addq(s,t,i);
        addq(t,s,i);
        q[i].u = t;
        q[i].v = s;
    }
}
void print_ans() {
    for(int i = 0; i < m; i++) {
        int t;
        t = d[q[i].u] - d[q[i].lca];
        if(q[i].v != q[i].lca) {
            t++;
        }
        if(q[i].u == q[i].v) t = 0;
        printf("%d\n",t);
    }
}
int main() {
    int Case;
    scanf("%d",&Case);
    while(Case--) {
        scanf("%d%d",&n,&m);
        init();
        read();
        solve();
        print_ans();
    }
    return 0;
}
