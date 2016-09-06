#include<iostream>
#include<sstream>
#include<fstream>
#include<vector>
#include<list>
#include<deque>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<bitset>
#include<algorithm>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cctype>
#include<cmath>
#include<ctime>
#include<iomanip>
using namespace std;
const double eps(1e-8);
typedef long long lint;
#define maxn 100010
int N, K, root;
int w[maxn];
bool select[maxn];
vector<int> G[maxn];
int f[maxn];
void dfs(int now)
{
    int nex;
    int mx = -1e9;
    for(int i = 0, sz = G[now].size(); i < sz; i++)
    {
        nex = G[now][i];
        dfs(G[now][i]);
        f[now] = max(f[now], max(f[nex], w[nex] + mx));
        w[now] = max(w[now], w[nex]);
        mx = max(mx, w[nex]);
    }
    return;
}
void solve()
{
    memset(select, 0, sizeof(select));
    priority_queue<pair<int, int> > Q;
    Q.push(make_pair(w[root], root));
    int ret = 0;
    while(K)
    {
        if(Q.empty())
        {
            puts("0");
            return;
        }
        int u = Q.top().second;
        Q.pop();
        if(select[u])
        {
            K++;
            select[u] = 0;
            ret -= w[u];
            for(int i = 0, sz = G[u].size(); i < sz; i++) Q.push(make_pair(w[G[u][i]], G[u][i]));
        }
        else
        {
            K--;
            select[u] = 1;
            ret += w[u];
            Q.push(make_pair(f[u] - w[u], u));
        }
    }
    printf("%d\n", ret);
    return;
}
int main()
{
    while(scanf("%d %d", &N, &K), N || K)
    {
        for(int i = 1; i <= N; i++) G[i].clear();
        int p;
        for(int i = 1; i <= N; i++)
        {
            f[i] = -1e9;
            scanf("%d %d", &p, w + i);
            if(p == 0) root = i;
            else G[p].push_back(i);
        }
        dfs(root);
        solve();
    }
    return 0;
}
