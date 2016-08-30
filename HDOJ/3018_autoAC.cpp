#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
using namespace std;
const int maxn = 100005;
int n, m;
int fa[maxn];
int deg[maxn];
int used[maxn];
int odd[maxn];
vector<int> v;
void init()
{
    v.clear();
    for (int i=1; i<=n; i++) fa[i] = i, deg[i] = 0, used[i] = 0, odd[i] = 0;
}
int find(int x)
{
    while (x != fa[x]) x = fa[x];
    return x;
}
int main()
{
    while (scanf("%d %d", &n, &m) != EOF)
    {
        init();
        int i;
        for (i=0; i<m; i++)
        {
            int a, b;
            scanf("%d %d", &a, &b);
            int faa = find(a);
            int fab = find(b);
            deg[a] ++;
            deg[b] ++;
            fa[fab] = faa;
        }
        for (i=1; i<=n; i++)
        {
            int f = find(i);
            if (!used[f])
            {
                v.push_back(f);
                used[f] = 1;
            }
            if (deg[i] & 1)
                odd[f] ++;
        }
        int sum = 0;
        for (i=0; i<v.size(); i++)
        {
            int k = v[i];
            if (deg[k] == 0) continue;
            if (odd[k] == 0) sum ++;
            else sum += odd[k] / 2;
        }
        printf("%d\n", sum);
    }
    return 0;
}
