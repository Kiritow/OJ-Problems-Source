#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <cmath>
#include <ctime>
#define INF 2000000000
#define MAXN 10005
#define L(x) x<<1
#define R(x) x<<1|1
using namespace std;
int n, m, q;
int father[MAXN],  num[MAXN];
long long out[MAXN];
struct node
{
    int u, v, w;
    bool operator <(const node &a)const
    {
        return w < a.w;
    }
}edge[MAXN * 10];
struct wen
{
    int l, id;
    bool operator <(const wen &a)const
    {
        return l < a.l;
    }
}p[MAXN];
void init()
{
    for(int i = 1; i <= n; i++)
    {
        father[i] = i;
        num[i] = 1;
    }
}
int find(int x)
{
    if(father[x] == x) return x;
    int t = find(father[x]);
    father[x] = t;
    return t;
}
int join(int x, int y)
{
    int fx = find(x);
    int fy = find(y);
    if(fx == fy) return 0;
    int t = num[fx] * num[fy];
    num[fx] += num[fy];
    num[fy] = 0;
    father[fy] = fx;
    return t;
}
int main()
{
    while(scanf("%d%d%d", &n, &m, &q) != EOF)
    {
        init();
        for(int i = 1; i <= m; i++)
            scanf("%d%d%d", &edge[i].u, &edge[i].v, &edge[i].w);
        sort(edge + 1, edge + m + 1);
        for(int i = 1; i <= q; i++)
        {
            scanf("%d", &p[i].l);
            p[i].id = i;
        }
        sort(p + 1, p + q + 1);
        int pos = 1;
        long long ans = 0;
        for(int i = 1; i <= q; i++)
        {
            while(pos <= m && edge[pos].w <= p[i].l)
            {
                ans += join(edge[pos].u, edge[pos].v);
                pos ++;
            }
            out[p[i].id] = ans;
        }
        for(int i = 1; i <= q; i++)
        printf("%I64d\n", out[i]);
    }
    return 0;
}
