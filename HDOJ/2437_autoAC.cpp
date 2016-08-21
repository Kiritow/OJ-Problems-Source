#include <cstdio>
#include <cmath>
#include <iostream>
#include <cstring>
# define MAX 1111
# define INF 0x7FFFFFFF
using namespace std;
char a[MAX];
struct node {
    int s,e,v,next;
} ed[22222];
int head[MAX],num = 0,n,m,k,st;
int dp[MAX],vis[MAX][MAX]; 
void add(int s,int e,int v) {
    ed[num].s = s;
    ed[num].e = e;
    ed[num].v = v;
    ed[num].next = head[s];
    head[s] = num++;
}
void init() {
    memset(vis,0,sizeof(vis));
    memset(head,-1,sizeof(head));
    num = 0;
}
int dfs(int v0,int u0,int cur) {
    if(a[v0 - 1] == 'P' && cur % k == 0) return dp[v0] = min(dp[v0],cur);
    if(dp[v0] != INF) return dp[v0];
    for(int i = head[v0]; i != -1; i = ed[i].next) {
        int e = ed[i].e;
        int v = ed[i].v + cur;
        if(vis[e][v%k] == 0 || v < vis[e][v % k]) {
            vis[e][v%k] = v;
            dfs(e,u0,v);
        }
    }
}
int main() {
    int T;
    cin >> T;
    int casee = 1;
    while(T --) {
        init();
        cin >> n >> m >> st >> k;
        for(int i=1; i<=n; i++)
             dp[i] = INF;
        getchar();
        int aa,bb,cc;
        scanf("%s",a);
        for(int i=1; i<=m; i++) {
            scanf("%d%d%d",&aa,&bb,&cc);
            add(aa,bb,cc);
        }
        printf("Case %d: ",casee++);
        dfs(st,st,0);
        int flag = 0,ind,ans = INF;
        for(int i=1; i<=n; i++) {
            if(dp[i] != INF) {
                flag = 1;
                if(ans > dp[i]) {
                    ans = dp[i];
                    ind = i;
                }
            }
        }
        if(flag) printf("%d %d\n",ans,ind);
        else printf("-1 -1\n");
    }
    return 0;
}
