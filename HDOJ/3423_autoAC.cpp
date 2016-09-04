#include <iostream>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <queue>
#include <ctime>
#include <vector>
#include <algorithm>
#define ll long long
#define L(rt) (rt<<1)
#define R(rt)  (rt<<1|1)
using namespace std;
const int INF = 1e9;
const int maxn = 50005;
struct Edge{
    int v, w, next;
}et[maxn * 4];
struct node{
    int u, v, l, id;
}ed[maxn * 10];
int eh[maxn], fa[maxn], son[maxn], ans[maxn];
ll dis1[maxn], dis2[maxn];
int n, m, num;
ll Min;
void init(){
    memset(eh, -1, sizeof(eh));
    for(int i = 1; i <= n; i++) fa[i] = i;
    num = 0;
}
void add(int u, int v, int w){
    Edge e = {v, w, eh[u]};
    et[num] = e;
    eh[u] = num++;
}
int find(int x){
    return x == fa[x] ? x : fa[x] = find(fa[x]);
}
bool cmp(node a, node b){
    if(a.l != b.l) return a.l < b.l;
    return a.id < b.id;
}
void dfs1(int u, int pre){
    son[u] = 1;
    dis1[u] = 0;
    for(int i = eh[u]; i != -1; i = et[i].next)
    {
        int v = et[i].v, w = et[i].w;
        if(v == pre) continue;
        dfs1(v, u);
        son[u] += son[v];
        dis1[u] += son[v] * w + dis1[v];
    }
}
void dfs2(int u, int pre, int pedge){
    if(pre == -1) dis2[u] = 0;
    else dis2[u] = dis2[pre] + dis1[pre] - dis1[u] - son[u] * pedge + ((ll)n - son[u]) * pedge;
    for(int i = eh[u]; i != -1; i = et[i].next)
    {
        int v = et[i].v, w = et[i].w;;
        if(v == pre) continue;
        dfs2(v, u, w);
    }
    if(Min > dis1[u] + dis2[u]) Min = dis1[u] + dis2[u];
}
int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d%d", &n, &m);
        init();
        for(int i = 0; i < m; i++)
        {
            scanf("%d%d%d", &ed[i].u, &ed[i].v, &ed[i].l);
            ed[i].id = i;
        }
        sort(ed, ed + m, cmp);
        ll ans1 = 0;
        for(int i = 0; i < m; i++)
        {
            int u = ed[i].u, v = ed[i].v, l = ed[i].l;
            int ru = find(u), rv = find(v);
            if(ru == rv) continue;
            fa[ru] = rv;
            add(u, v, l);
            add(v, u, l);
            ans1 += l;
        }
        int cnt = 0;
        for(int i = 1; i <= n; i++)
        if(i == find(i)) cnt++;
        if(cnt > 1)
        {
            printf("Poor mayor.\n");
            continue;
        }
        Min = 0x7fffffffffffffffLL;
        dfs1(1, -1);
        dfs2(1, -1, 0);
        printf("%I64d\n", ans1);
        cnt = 0;
        for(int i = 1; i <= n; i++)
        if(dis1[i] + dis2[i] == Min)
        ans[cnt++] = i;
        for(int i = 0; i < cnt - 1; i++)
        printf("%d ", ans[i]);
        printf("%d\n", ans[cnt - 1]);
        printf("%I64d\n", 2 * Min);
    }
    return 0;
}
