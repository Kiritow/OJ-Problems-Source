#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;
const int maxn = (1 << 17), oo = 1000000000, nil = 0;
int N, M, tim[105], reqt[105], reqf[105], rest[105], resf[105];
int e, pnt[maxn], nxt[maxn << 2], u[maxn << 2], v[maxn << 2], w[maxn << 2];
int d[maxn];
bool vis[maxn];
struct node
{
    int n, dis;
    node(int n = 0, int dis = 0) :n(n), dis(dis) {}
    bool operator < (const node& b) const
    {
        return dis > b.dis;
    }
};
void addedge(int a, int b, int c)
{
    u[++e] = a; v[e] = b; w[e] = c;
    nxt[e] = pnt[a]; pnt[a] = e;
}
void init()
{
    char ch[25];
    scanf("%d%d", &N, &M);
    for(int i = 1; i <= M; ++i)
    {
        scanf("%d", &tim[i]);
        scanf("%s", &ch);
        for(int j = 0; j < N; ++j)
        {
            if(ch[j] == '+')
            {
                reqt[i] |= (1 << j);
            }
            if(ch[j] == '-')
            {
                reqf[i] |= (1 << j);
            }
        }
        scanf("%s", &ch);
        for(int j = 0; j < N; ++j)
        {
            if(ch[j] == '+')
            {
                rest[i] |= (1 << j);
            }
            if(ch[j] == '-')
            {
                resf[i] |= (1 << j);
            }
        }
    }
    for(int i = (1 << N) - 1; i >= 0; --i)
    {
        for(int j = 1; j <= M; ++j)
        {
            if(((i & reqt[j]) == reqt[j]) && ((i & reqf[j]) == 0))
            {
                addedge(i, (i & (~resf[j]) | rest[j]), tim[j]);
            }
        }
    }
}
void work()
{
    int S = (1 << N) - 1, T = 0;
    memset(d, 0x3f, sizeof(d));
    memset(vis, 0, sizeof(vis));
    priority_queue <node> Q;
    d[S] = 0;
    Q.push(node(S, 0));
    while(!Q.empty())
    {
        node tmp = Q.top();
        Q.pop();
        vis[tmp.n] = true;
        for(int j = pnt[tmp.n]; j != nil; j = nxt[j])
        {
            if((!vis[v[j]]) && d[v[j]] > tmp.dis + w[j])
            {
                d[v[j]] = tmp.dis + w[j];
                Q.push(node(v[j], d[v[j]]));
            }
        }
    }
    if(d[T] > oo)
    {
        puts("0");
    }
    else
    {
        printf("%d\n", d[T]);
    }
}
int main()
{
    init();
    work();
    return 0;
}   
