#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <vector>
#include <functional>
#define snuke(it,x) for (__typeof((x).begin()) it = (x).begin(); it != (x).end(); ++ it)
const int N = 500 + 5;
const int D = 5;
const int INF = 0x3f3f3f3f;
std::vector<std::pair<int,int> > edges[N];
int n,drop_cost,dp[N][D],tmp[D][D];
inline void toMin(int &a,int b) {
    if (a>b) a = b;
}
void dfs(int u,int fa) {
    dp[u][0] = 0;
    snuke(it,edges[u]) {
        int v = it->first;
        int w = it->second;
        if (v==fa) continue;
        dfs(v,u);
        for (int j = 0; j < D; ++ j) {
            for (int k = 0; k < D; ++ k) {
                tmp[j][k] = INF;
            }
        }
        for (int j = 0; j < D; ++ j) {
            for (int k = 1; j+k < D; ++ k) {
                toMin(tmp[j+k][std::min(j,k)],dp[u][j]+dp[v][k]+k*w);
            }
        }
        for (int j = D-1; j >= 2; -- j) {
            for (int k = j>>1; k >= 1; -- k) {
                toMin(tmp[j-2][k-1],tmp[j][k]+drop_cost);
            }
        }
        for (int j = D-1; j >= 0; -- j) {
            dp[u][j] = INF;
            if (j!=D-1) toMin(dp[u][j],dp[u][j+1]+drop_cost);
            for (int k = 0; k < D; ++ k) {
                toMin(dp[u][j],tmp[j][k]);
            }
        }
    }
    toMin(dp[u][1],dp[u][0]);
}
inline void read(int &x) {
    char c; bool sign = false;
    for (c = getchar(); c<'0' || c>'9'; c = getchar()) if (c=='-') sign = true;
    for (x = 0; c>='0' && c<='9'; c = getchar()) x = x*10+c-'0';
    sign && (x=-x);
}
int main() {
    int cas,ca = 0;
    read(cas);
    while (cas--) {
        read(n); read(drop_cost);
        std::fill(edges,edges+n,std::vector<std::pair<int,int> >());
        for (int i = 0; i < n-1; ++ i) {
            int a,b,c;
            read(a),read(b),read(c);
            edges[a].push_back(std::make_pair(b,c));
            edges[b].push_back(std::make_pair(a,c));
        }
        memset(dp,INF,sizeof(dp));
        dfs(0,-1);
        printf("Case #%d: ",++ca);
        if (n==1) {
            puts("0");
            continue;
        }
        int answer = INF;
        for (int i = 0; i < D; ++ i) {
            toMin(answer,dp[0][i]+i*drop_cost);
        }
        printf("%d\n",answer);
    }
    return 0;
}
