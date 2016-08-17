#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
using namespace std;
const int MAX_N = 2 * 5000 + 10;
struct TwoSAT {
    int n;
    vector<int> G[2 * MAX_N];
    bool mark[2 * MAX_N];
    int S[2 * MAX_N], c;
    void Init(int n)
    {
        this->n = n;
        for (int i = 0; i <= 2 * n; ++i)
            G[i].clear();
        memset(mark, 0, sizeof(mark));
    }
    bool Dfs(int x)
    {
        if (mark[x ^ 1])  return false;
        if (mark[x])      return true;
        mark[x] = true;
        S[c++] = x;
        for (int i = 0; i < G[x].size(); ++i)
        {
            if (!Dfs(G[x][i]))
                return false;
        }
        return true;
    }
    void AddClause(int x, int y)
    {
        int a = 2 * x;
        int b = 2 * y;
        G[a ^ 1].push_back(b);
        G[b ^ 1].push_back(a);
    }
    void AddClauseTeam(int i, int j, int k)
    {
        int a = 2 * i;
        int b = 2 * j;
        int c = 2 * k;
        G[a].push_back(b ^ 1);
        G[a].push_back(c ^ 1);
        G[b].push_back(a ^ 1);
        G[b].push_back(c);
        G[c].push_back(a ^ 1);
        G[c].push_back(b);
        G[a ^ 1].push_back(b);
        G[a ^ 1].push_back(c);
        G[b ^ 1].push_back(a);
        G[b ^ 1].push_back(c ^ 1);
        G[c ^ 1].push_back(a);
        G[c ^ 1].push_back(b ^ 1);
    }
    bool Solve()
    {
        for (int i = 0; i < 2 * n; i += 2)
        {
            if (!mark[i] && !mark[i + 1])
            {
                c = 0;
                if (!Dfs(i))
                {
                    while (c > 0) mark[S[--c]] = false;
                    if (!Dfs(i + 1))
                        return false;
                }
            }
        }
        return true;
    }
};
TwoSAT sat;
int main()
{
    int n, m;
    while (scanf("%d %d", &n, &m) != EOF)
    {
        int a, b, c;
        sat.Init(3 * n);
        for (int i = 0; i < n; ++i)
        {
            scanf("%d %d %d", &a, &b, &c);
            sat.AddClauseTeam(a, b, c);
        }
        for (int i = 0; i < m; ++i)
        {
            scanf("%d %d", &a, &b);
            sat.AddClause(a, b);
        }
        bool ok = sat.Solve();
        if (ok)
            printf("yes\n");
        else
            printf("no\n");
    }
    return 0;
}
