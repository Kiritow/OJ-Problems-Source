#include <cstdio>
#include <cstring>
struct EDGE
{
    int v, next;
}edge[2010010];
struct NODE
{
    int p;
    long long t;
}node[1010];
const long long inf = 1ll<<60;
long long map[105][105];
bool usedif[1005];
int link[1005];
int head[1010];
int cnt, gx, gy;
bool cmp(NODE a, NODE b)
{
    return a.t < b.t;
}
void addedge(int u, int v)
{
    edge[cnt].v = v;
    edge[cnt].next = head[u];
    head[u] = cnt++;
}
bool can(int t)
{
    for(int p = head[t]; p != -1; p = edge[p].next)
    {
        int i = edge[p].v;
        if(usedif[i]==0)
        {
            usedif[i]=1;
            if(link[i]==-1||can(link[i]))
            {
                link[i]=t;
                return true;
            }
        }
    }
    return false;
}
int MaxMatch()
{
    int num=0;
    memset(link,-1,sizeof(link));
    for(int i=0; i< gx; i++)
    {
        memset(usedif,0,sizeof(usedif));
        if(can(i))  num++;
    }
    return num;
}
int main()
{
    int T;
    scanf("%d", &T);
    int cas = 1;
    while(T--)
    {
        int n, m, q;
        scanf("%d%d%d", &n, &m, &q);
        int d = 1<< 30;
        for(int i = 0; i < n; i++)
          for(int j = 0; j < n; j++)
          if(i != j)  map[i][j] = inf;
         else map[i][j] = 0;
        while(m--)
        {
            int a, b;
            long long c;
            scanf("%d%d%I64d", &a, &b, &c);
            if(map[a][b] > c)
            {
                map[a][b] = map[b][a] = c;
            }
        }
        for(int k = 0; k < n; k++)
          for(int i = 0; i < n; i++)
          {
            if(i == k) continue;
            if(map[i][k] == inf)  continue;
            for(int j = 0; j < n; j++)
            if(map[k][j] != inf && map[i][k] + map[k][j] < map[i][j])
            {
                map[i][j] = map[i][k] + map[k][j];
            }
          }
        for(int i = 0; i < q; i++)
        {
            scanf("%d%d", &node[i].p, &node[i].t);
        }
        gx = q;
        cnt = 0;
        memset(head, -1, sizeof(head));
        for(int i = 0; i < q; i++)
        {
            for(int j = 0; j < q; j++)
            if(i != j && node[j].t - node[i].t >= map[node[i].p][node[j].p])
            {
                addedge(i, j);
            }
        }
        int ans = gx - MaxMatch();
        printf("Case %d: %d\n", cas++, ans - 1);
    }
    return 0;
}
