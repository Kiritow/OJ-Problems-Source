#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>
using namespace std;
#define N  10010
vector<int>G[N];
int n,len;
char value[N],an[N];
int dis[N];
int f[N];
bool visit[N];
void init() {
    for(int i = 1; i <= n; i++) G[i].clear();
    memset(dis,0,sizeof(dis));
    memset(visit,0,sizeof(visit));
}
void dfs(int u) {
    int ma = -10000000;
    visit[u] = 1;
    for(int i = 0; i < G[u].size(); i++)
      if(!visit[G[u][i]]) {
          dfs(G[u][i]);
          f[G[u][i]] = u;
          ma = max(ma,dis[G[u][i]]);
      }
    if(ma == -10000000)
      dis[u] = 1;
    else
      dis[u] = ma+1;
}
bool dfs1(int u,int x,int len1) {
    visit[u] = 1;
    if(x > len) return 1;
    if(dis[u] > len1)
    for(int i = 0; i < G[u].size(); i++) {
        if(value[G[u][i]] == an[x] && !visit[G[u][i]]) {
            if(dfs1(G[u][i],x+1,len1-1)) return 1;
        }
    }
    else {
        if(value[f[u]] == an[x] && !visit[f[u]]) {
            return dfs1(f[u],x+1,len1-1);
        }
    }
    return 0;
}
int main() {
    int t;scanf("%d",&t);
    int ca = 1;
    while(t--) {
        scanf("%d",&n);
        init();
        int x,y;
        for(int i = 1; i < n; i++) {
            scanf("%d%d",&x,&y);
            G[x].push_back(y);
            G[y].push_back(x);
        }
        scanf("%s",value+1);
        scanf("%s",an+1);
        dfs(1); bool flag = 0;
        len = strlen(an+1);
        for(int i = 1; i <= n; i++)
          if(value[i] == an[1]) {
              memset(visit,0,sizeof(visit));
              if(dfs1(i,2,len-1)) {
                  printf("Case #%d: Find\n",ca++);
                  flag = 1;
                  break;
              }
          }
        if(!flag) printf("Case #%d: Impossible\n",ca++);
    }
    return 0;
}
