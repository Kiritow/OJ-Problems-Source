#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cctype>
#include <climits>
#include <deque>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <vector>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <algorithm>
#include <bitset>
#include <complex>
#include <string>
#include <utility>
using namespace std;
typedef long long LL;
typedef pair<int, int> Pii;
typedef pair<LL, LL> Pll;
#define foreach(it,s) for(__typeof(s.begin()) it=s.begin();it!=s.end();it++)
const int maxn = 50 + 5;
const int maxe = 500 + 5;
int n, m, s, t;
struct Tedge {
    int u, v;
    string w;
    Tedge(int u = 0, int v = 0, string w = ""):u(u), v(v), w(w){};
};
vector<Tedge> edge[maxn];
string dis[maxn];
bool vis[maxn];
string bf()
{
    int clk = 0;
    memset(vis, false, sizeof(vis));
    dis[t] = ""; vis[t] = true;
    while (1) {
        bool update = false;
        for (int ii=0;ii<n;ii++) {
            foreach(i, edge[ii]) 
                if (vis[i->v]) {
                    int u = i->u, v = i->v;
                    string tmp = i->w + dis[v];
                    if (!vis[u] || tmp < dis[u]) {
                        dis[u] = tmp;
                        update = vis[u] = true;
                        if (clk >= n - 1 && u == s) return "Tough way!";
                    }
                }
        }
        if (!update || ++clk > n * 6) break;
    }
    return vis[s] ? dis[s]: "Tough way!";
}
int main()
{
    int cas = 0;
    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d%d%d", &n, &m, &s, &t);
        for (int i=0;i<n;i++) edge[i].clear();
        printf("Case #%d:\n", ++cas);
        for (int i=0;i<m;i++) {
            int u, v;
            char st[8];
            scanf("%d%d%s", &u, &v, st);
            edge[u].push_back(Tedge(u, v, st));
        }
        puts(bf().c_str());
    }
    return 0;
}
