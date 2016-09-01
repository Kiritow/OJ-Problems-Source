#include<iostream>
#include<cstring>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
#define N 300
int t, n, m, k, ans[N], match[N], num, match2[N];
bool vst[N][N], re[N], tmp[N];
vector<int> jeo[N];
bool find(int id, int limit)
{
    if (id <= limit) return false;
    for(int i = 0; i < jeo[id].size(); i++)
        if (!tmp[jeo[id][i]])
        {
            tmp[jeo[id][i]] = 1;
            if (match[jeo[id][i]] == -1 || find(match[jeo[id][i]], limit))
            {
                match[jeo[id][i]] = id;
                return true;
            }
        }
    return false;
}
bool solve()
{
    memset(match, -1, sizeof(int) * (n + 1));
    for(int i = 1; i <= n; i++)
    {
        memset(tmp, 0, sizeof(bool) * (n + 1));
        if (!find(i, 0)) return false;
    }
    return true;
}
bool check(int id, int tar)
{
    if(match[tar] == id) return true;
    int key = 0;
    for(int i = 1; i <= n; i++)
        if ((match2[i] = match[i]) == id) key = i;
    int t = match[tar]; match[tar] = id; match[key] = -1;
    memset(tmp, 0, sizeof(bool) * (n + 1));
    if (find(t, id)) return true;
    else for(int i = 1; i <= n; i++)
        match[i] = match2[i];
    return false;
}
bool dfs(int deep)
{
    if (deep == n + 1)
    {
        num++; if (num == k)
            return true;
        return false;
    }
    for(int i = 0; i < jeo[deep].size(); i++)
        if (!re[jeo[deep][i]] && check(deep, jeo[deep][i]))
        {
            ans[deep] = jeo[deep][i];
            re[jeo[deep][i]] = 1;
            if (dfs(deep + 1)) return true;
            re[jeo[deep][i]] = 0;
        }
    return false;
}
int main()
{
    scanf("%d", &t);
    for(int ca = 1; ca <= t; ca++)
    {
        scanf("%d%d%d", &n, &m, &k);
        for(int i = 1; i <= n; i++)
            for(int j =1; j <= n; j++) vst[i][j] = 0;
        for(int i = 0; i < m; i++)
            for(int j = 1; j <= n; j++)
            {
                int x;scanf("%d", &x);vst[j][x] = 1;
            }
        for(int i = 1; i <= n; i++)
        {
            jeo[i].clear();
            for(int j = 1; j <= n; j++)
                if (!vst[i][j]) jeo[i].push_back(j);
            sort(jeo[i].begin(), jeo[i].end());
        }
        memset(re, 0, sizeof(bool) * (n + 1)); num = 0;
        printf("Case #%d:", ca);
        if (solve() && dfs(1))
        {
            for(int i = 1; i <= n; i++) printf(" %d", ans[i]);
            putchar('\n');
        }
        else printf(" -1\n");
    }
    return 0;
}
