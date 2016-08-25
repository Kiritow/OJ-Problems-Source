#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
const int SIZE = 10010;
const int INF = 0xfffffff;
int u[5*SIZE], v[5*SIZE], w[5*SIZE], nex[5*SIZE], h[5*SIZE];
int first[SIZE], d[SIZE];
int n, m, cnt;
int s, e;
void read_graph(int u1, int v1, int w1, int h1)
{
    u[cnt] = u1; v[cnt] = v1; w[cnt] = w1; h[cnt] = h1;
    nex[cnt] = first[u[cnt]];
    first[u[cnt]] = cnt++;
}
int spfa(int src, int mid)
{
    queue<int> q;
    bool inq[SIZE] = {0};
    for(int i = 1; i <= n; i++) d[i] = (i == src)?0:INF;
    q.push(src);
    while(!q.empty())
    {
        int x = q.front(); q.pop();
        inq[x] = 0;
        for(int e = first[x]; e!=-1; e = nex[e]) if(d[v[e]] > d[x]+w[e] && mid <= h[e])
        {
            d[v[e]] = d[x] + w[e];
            if(!inq[v[e]])
            {
                inq[v[e]] = 1;
                q.push(v[e]);
            }
        }
    }
    if(d[e] == INF) return 0;
        return 1;
}
void init()
{
    memset(first, -1, sizeof(first));
    cnt = 0;
}
int main()
{
    int times = 0;
    while(~scanf("%d%d", &n, &m), n, m)
    {
        init();
        while(m--)
        {
            int u1, v1, w1, h1;
            scanf("%d%d%d%d", &u1, &v1, &h1, &w1);
            if(h1 == -1) h1 = INF;
            read_graph(u1, v1, w1, h1);
            read_graph(v1, u1, w1, h1);
        }
        int x = 0, y, ans = INF, mid, h;
        scanf("%d%d%d", &s, &e, &y);
        while(x <= y)
        {
            mid = (x+y)>>1;
            if(spfa(s, mid))
            {
                x = mid+1;
                ans = d[e];
                h = mid;          
            }
            else y = mid-1;
        }
        if(times) printf("\n");
        printf("Case %d:\n", ++times);
        if(ans != INF)
        {
            printf("maximum height = %d\n", h);
            printf("length of shortest route = %d\n", ans);
        }
        else
        {
            printf("cannot reach destination\n");
        }
    }
}
