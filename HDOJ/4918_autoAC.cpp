#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#include<map>
#include<queue>
#include<stack>
#include<cmath>
#include<vector>
#define inf 0x3f3f3f3f
#define Inf 0x3FFFFFFFFFFFFFFFLL
#define eps 1e-9
#define pi acos(-1.0)
using namespace std;
typedef long long ll;
const int maxn = 100000 + 10;
const int M = 40;
int pool[maxn*M];
int pool_size;
struct BIT
{
    int *C,n;
    void Init(int n)
    {
        this -> n = n;
        C = pool + pool_size;
        for(int i = 0;i < n;++i)
            C[i] = 0;
        pool_size += n;
    }
    void add(int x,int v)
    {
        for(;x < n; x += x & -x)
            C[x] += v;
    }
    int sum(int x)
    {
        if(x >= n) x = n - 1;
        int res = 0;
        for(;x > 0; x -= x & -x)
            res += C[x];
        return res;
    }
}tree[maxn<<1];
struct Node
{
    int root,subtree,dis;
    Node(int root = 0,int subtree = 0,int dis = 0):root(root),subtree(subtree),dis(dis){}
};
vector<Node>vt[maxn];
struct Edge
{
    int v,next;
    Edge(int v = 0,int next = 0):v(v),next(next){}
}edges[maxn<<1];
int head[maxn],w[maxn],id[maxn<<1],cnt,nEdge;
int q[maxn],dp[maxn],fa[maxn],flag[maxn],d[maxn];
void AddEdges(int u,int v)
{
    edges[++nEdge] = Edge(v,head[u]);
    head[u] = nEdge;
    edges[++nEdge] = Edge(u,head[v]);
    head[v] = nEdge;
}
void Init(int n)
{
    pool_size = cnt = 0;
    memset(head,0xff,sizeof(head));
    memset(flag,0,sizeof(flag));
    nEdge = -1;
    for(int i = 1;i <= n;++i)
        vt[i].clear();
}
int getroot(int x,int & tot)
{
    int tail = 0,u,v;
    q[tail++] = x;
    fa[x] = -1;
    for(int i = 0;i < tail;++i)
    {
        u = q[i];
        for(int k = head[u];k != -1;k = edges[k].next)
        {
            v = edges[k].v;
            if(v != fa[u] && !flag[v])
            {
                fa[v] = u;
                q[tail++] = v;
            }
        }
    }
    int minv = inf,root = x,mx;
    for(int i = tail - 1;i >= 0;--i)
    {
        u = q[i];
        dp[u] = 1;
        mx = 0;
        for(int k = head[u];k != -1;k = edges[k].next)
        {
            v = edges[k].v;
            if(v != fa[u] && !flag[v])
            {
                mx = max(mx,dp[v]);
                dp[u] += dp[v];
            }
        }
        mx = max(mx,tail - dp[u]);
        if(mx < minv) minv = mx,root = u;
    }
    tot = tail;
    return root;
}
void cal(int x,int pa,int subtree)
{
    int tail = 0,u,v;
    q[tail++] = x;
    d[x] = 1;
    fa[x] = pa;
    for(int i = 0;i < tail;++i)
    {
        u = q[i];
        vt[u].push_back(Node(id[pa],subtree,d[u]));
        tree[id[pa]].add(d[u]+1,w[u]);
        tree[subtree].add(d[u],w[u]);
        for(int k = head[u];k != -1;k = edges[k].next)
        {
            v = edges[k].v;
            if(v != fa[u] && !flag[v])
            {
                d[v] = d[u] + 1;
                fa[v] = u;
                q[tail++] = v;
            }
        }
    }
}
void solve(int x)
{
    int num;
    int rt = getroot(x,num);
    flag[rt] = 1;
    id[rt] = ++cnt;
    vt[rt].push_back(Node(cnt,-1,0));
    tree[cnt].Init(num + 2);
    tree[cnt].add(1,w[rt]);
    for(int k = head[rt];k != -1;k = edges[k].next)
        if(!flag[edges[k].v])
        {
            ++cnt;
            tree[cnt].Init(dp[edges[k].v] + 2);
            cal(edges[k].v,rt,cnt);
        }
    for(int k = head[rt];k != -1;k = edges[k].next)
        if(!flag[edges[k].v]) solve(edges[k].v);
}
char s[20];
int main()
{
    int n,q;
    while(~scanf("%d%d",&n,&q))
    {
        Init(n);
        for(int i = 1;i <= n;++i)
            scanf("%d",&w[i]);
        int u,v;
        for(int i = 1;i < n;++i)
        {
            scanf("%d%d",&u,&v);
            AddEdges(u,v);
        }
        solve(1);
        Node node;
        while(q--)
        {
            scanf("%s%d%d",s,&u,&v);
            if(s[0] == '!')
            {
                int d = v - w[u];
                for(int i = 0;i < (int)vt[u].size();++i)
                {
                    node = vt[u][i];
                    tree[node.root].add(node.dis + 1,d);
                    if(node.subtree != -1)
                        tree[node.subtree].add(node.dis , d);
                }
                w[u] += d;
            }
            else
            {
                int d = v,ans = 0;
                for(int i = 0;i < (int)vt[u].size();++i)
                {
                    node = vt[u][i];
                    ans += tree[node.root].sum(d - node.dis + 1);
                    if(node.subtree != -1)
                        ans -= tree[node.subtree].sum(d - node.dis);
                }
                printf("%d\n",ans);
            }
        }
    }
    return 0;
}
