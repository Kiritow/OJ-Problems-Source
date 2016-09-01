#include <iostream>
#include <cstring>
#include <cstdio>
#include <string>
#include <map>
using namespace std;
#define maxn 105
#define type int
const int inf = ~0u >> 1;
struct edge
{
    int u,v;
    type cost;
    edge(){}
    edge(int _u,int _v,type _c):u(_u),v(_v),cost(_c){}
}e[maxn * maxn];
int pre[maxn],id[maxn],vis[maxn];
type in[maxn];
type dirmst(int root,int nv,int ne)
{
    type ret = 0;
    while(1)
    {
        fill(in,in + nv,inf);
        for(int i = 0;i < ne;i++)
        {
            int u = e[i].u;
            int v = e[i].v;
            if(e[i].cost < in[v] && u != v)
            {
                pre[v] = u;
                in[v] = e[i].cost;
            }
        }
        for(int i = 0;i < nv;i++)
        {
            if(i == root)
                continue;
            if(in[i] == inf)
                return -1;
        }
        int cntnode = 0;
        fill(id,id + nv,-1);
        fill(vis,vis + nv,-1);
        in[root] = 0;
        for(int i = 0;i < nv;i++)
        {
            ret += in[i];
            int v = i;
            while(vis[v] != i && id[v] == -1 && v != root)
            {
                vis[v] = i;
                v = pre[v];
            }
            if(v != root && id[v] == -1)
            {
                for(int u = pre[v]; u != v;u = pre[u])
                    id[u] = cntnode;
                id[v] = cntnode++;
            }
        }
        if(cntnode == 0)
            break;
        for(int i = 0;i < nv;i++)
            if(id[i] == -1)
                id[i] = cntnode++;
        for(int i = 0;i < ne;i++)
        {
            int v = e[i].v;
            e[i].u = id[e[i].u];
            e[i].v = id[e[i].v];
            if(e[i].u != e[i].v)
                e[i].cost -= in[v];
        }
        nv = cntnode;
        root = id[root];
    }
    return ret;
}
int main()
{
    int n;
    while(scanf("%d",&n) == 1 && n)
    {
        map <string,int> M;
        M["THE_WINDY"] = 2;
        int cnt = 3;
        string a,b;
        int w1,w2;
        int m = 0;
        int tot = 0;
        for(int i = 0;i < n;i++)
        {
            cin >> a >> w1 >> b >> w2;
            if(M[a] == 0)
                M[a] = cnt++;
            if(M[b] == 0)
                M[b] = cnt++;
            e[m++] = edge(1,M[a],w1);
            tot += w1;
            if(M[a] != M[b])
            {
                e[m++] = edge(M[b],M[a],w2);
                tot += w2;
            }
        }
        e[m++] = edge(0,1,tot + 1);
        e[m++] = edge(0,2,tot + 1);
        int ans = dirmst(0,cnt,m);
        printf("%d\n",ans - (tot + 1) * 2);
    }
}
