#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define inf (1<<29)
const int maxn = 105;
int g[maxn][maxn],a[maxn][maxn],p[maxn];
bool vis[maxn],combine[maxn],par[maxn];
int d[maxn],node[maxn],st[maxn],k,s,t;
vector <int> vst[maxn];
vector <int> pa , pb;
int prim(int n) {
    memset(vis,0,sizeof(vis));
    memset(d,0,sizeof(d));
    int mincut = 0 , tmp = -1;
    s = t = -1;
    int top = 0;
    for(int i=0;i<k;i++) {
        int maxi = -inf;
        for(int j=0;j<k;j++) {
            int u = node[j];
            if(!combine[u]&&!vis[u]&&d[u]>maxi) {
                tmp = u;
                maxi = d[u];
            }
        }
        st[top++] = tmp;
        vis[tmp] = true;
        if(i == k-1)
            mincut = d[tmp];
        for(int j=0;j<k;j++) {
            int u = node[j];
            if(!combine[u]&&!vis[u])
                d[u] += g[tmp][u];
        }
    }
    s = st[top-2];
    t = st[top-1];
    for(int i=0;i<top;i++) node[i] = st[i];
    return mincut;
}
int stoer_wagner(int n) {
    for(int i=0;i<n;i++) {
        vst[i].clear();
        vst[i].push_back(i);
    }
    int ans = inf;
    memset(combine,0,sizeof(combine));
    for(int i=0;i<n;i++) node[i] = i;
    for(int i=1;i<n;i++) {
        k = n - i + 1;
        int cur = prim(n);
        if(cur < ans) {
            ans = cur;
            for(int j=0;j<n;j++) par[j] = 0;
            for(int j=0;j<vst[t].size();j++) par[ vst[t][j] ] = 1;
        }
        combine[t] = true;
        for(int j=0;j<vst[t].size();j++) vst[s].push_back(vst[t][j]);
        for(int j=0;j<n;j++) {
            if(j == s) continue;
            if(!combine[j]) {
                g[s][j] += g[t][j];
                g[j][s] += g[j][t];
            }
        }
    }
    pa.clear(); pb.clear();
    for(int i=0;i<n;i++)
        if(par[i]) pa.push_back(i);
        else pb.push_back(i);
    return ans;
}
int K;
int dfs(vector <int> t) {
    int n = t.size();
    for(int i=0;i<n;i++) for(int j=0;j<n;j++) g[i][j] = a[t[i]][t[j]];
    if(stoer_wagner(n) >= K) return 1;
    vector <int> x , y;
    for(int i=0;i<pa.size();i++) x.push_back(t[pa[i]]);
    for(int i=0;i<pb.size();i++) y.push_back(t[pb[i]]);
    return dfs(x) + dfs(y);
}
int main() {
    int n , m;
    while(~scanf("%d%d%d",&n,&m,&K)) {
        memset(a , 0 ,sizeof(a));
        while(m--) {
            int u , v;
            scanf("%d%d",&u,&v);
            u --; v --;
            a[u][v] += 1;
            a[v][u] += 1;
        }
        vector <int> t;
        for(int i=0;i<n;i++) t.push_back(i);
        printf("%d\n" , dfs(t));
    }
    return 0;
}
