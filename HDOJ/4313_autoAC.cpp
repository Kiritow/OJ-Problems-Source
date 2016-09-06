#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;
const int maxn = 100010;
int t, n, k;
int mach[maxn], father[maxn];
struct Edge {
    int u, v, c;
}edge;
vector<Edge> vv;
bool cmp(Edge a, Edge b)
{
    return a.c > b.c;
}
void initSet()
{
    for (int i = 0; i < maxn; ++i) {
        father[i] = i;
        mach[i] = 0;
    }
}
int find(int x)
{
    if (x != father[x]) {
        father[x] = find(father[x]);
    }
    return father[x];
}
void merge(int a, int b)
{
    a = find(a);
    b = find(b);
    if (a == b) return ;
    if (a < b) {
        father[b] = a;
        mach[a] += mach[b];
    } else {
        father[a] = b;
        mach[b] += mach[a];
    }
}
int main()
{
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d", &n, &k);
        vv.clear();
        initSet();
        int u, v, c;
        __int64 ans = 0;
        for (int i = 0; i < n - 1; ++i) {
            scanf("%d%d%d", &u, &v, &c);
            edge.u = u; edge.v = v; edge.c = c;
            vv.push_back(edge);
            ans += c;
        }
        for (int i = 0; i < k; ++i) {
            scanf("%d", &u);
            mach[u] = 1;
        }
        sort(vv.begin(), vv.end(), cmp);
        for (int i = 0; i < n - 1; ++i) {
            u = find(vv[i].u);
            v = find(vv[i].v);
            if (mach[u] + mach[v] <= 1) {
                merge(u, v);
                ans -= vv[i].c;
            }
        }
        printf("%I64d\n", ans);
    }
    return 0;
}
