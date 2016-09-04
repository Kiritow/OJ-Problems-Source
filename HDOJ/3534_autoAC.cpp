#include <iostream>
#include <cstdio>
#include <memory.h>
using namespace std;
const int inf = 1 << 29;
const int maxn = 10002;
struct node
{
    int v,w;
    int next;
}edge[maxn << 1];
struct A
{
    int path,num;
    int dep1,dep2;
    int num1,num2;
}ans[maxn];
int head[maxn];
int n,idx;
void init()
{
    memset(head,-1,sizeof(head));
    idx = 0;
    return;
}
void addedge(int u,int v,int w)
{
    edge[idx].v = v;
    edge[idx].w = w;
    edge[idx].next = head[u];
    head[u] = idx++;
    edge[idx].v = u;
    edge[idx].w = w;
    edge[idx].next = head[v];
    head[v] = idx++;
    return;
}
void read()
{
    int u,v,w;
    for(int i=1;i<n;i++)
    {
        scanf("%d %d %d",&u,&v,&w);
        addedge(u,v,w);
    }
    return;
}
void dfs(int st,int pre)
{
    ans[st].dep1 = ans[st].dep2 = -inf;
    ans[st].num1 = ans[st].num2 = ans[st].num = 0;
    bool leaf = true;
    for(int i=head[st];i != -1;i=edge[i].next)
    {
        if(edge[i].v == pre) continue;
        dfs(edge[i].v , st);
        leaf = false;
        int tmp = ans[edge[i].v].dep1 + edge[i].w;
        if(tmp > ans[st].dep1)
        {
            ans[st].dep2 = ans[st].dep1;
            ans[st].num2 = ans[st].num1;
            ans[st].dep1 = tmp;
            ans[st].num1 = ans[edge[i].v].num1;
        }
        else if(tmp == ans[st].dep1)
        {
            ans[st].num1 += ans[edge[i].v].num1;
        }
        else if(tmp > ans[st].dep2)
        {
            ans[st].dep2 = tmp;
            ans[st].num2 = ans[edge[i].v].num1;
        }
        else if(tmp == ans[st].dep2)
        {
            ans[st].num2 += ans[edge[i].v].num1;
        }
    }
    if(leaf)
    {
        ans[st].dep1 = ans[st].path = 0;
        ans[st].num1 = ans[st].num = 1;
        return;
    }
    int c1 = 0,c2 = 0;
    for(int i=head[st];i != -1;i=edge[i].next)
    {
        if(edge[i].v == pre) continue;
        int tmp = ans[edge[i].v].dep1 + edge[i].w;
        if(tmp == ans[st].dep1) c1++;
        else if(tmp == ans[st].dep2) c2++;
    }
    int type; 
    if(c1 > 1) type = 1;
    else if(c2 > 0) type = 2;
    else type = 3;
    if(type == 1)
    {
        ans[st].path = ans[st].dep1 * 2;
        int sum = 0;
        for(int i=head[st];i != -1;i=edge[i].next)
        {
            if(edge[i].v == pre) continue;
            if(ans[edge[i].v].dep1 + edge[i].w == ans[st].dep1)
            {
                ans[st].num += sum * ans[edge[i].v].num1;
                sum += ans[edge[i].v].num1;
            }
        }
    }
    else if(type == 2)
    {
        ans[st].path = ans[st].dep1 + ans[st].dep2;
        for(int i=head[st];i != -1;i=edge[i].next)
        {
            if(edge[i].v == pre) continue;
            if(ans[edge[i].v].dep1 + edge[i].w == ans[st].dep2)
            {
                ans[st].num += ans[st].num1 * ans[edge[i].v].num1;
            }
        }
    }
    else
    {
        ans[st].path = ans[st].dep1;
        ans[st].num = ans[st].num1;
    }
    return;
}
void solve()
{
    dfs(1,0);
    int res = -inf,num = 0;
    for(int i=1;i<=n;i++)
    {
        if(ans[i].path > res)
        {
            res = ans[i].path;
            num = ans[i].num;
        }
        else if(ans[i].path == res)
        {
            num += ans[i].num;
        }
    }
    printf("%d %d\n",res,num);
    return;
}
int main()
{
    while(~scanf("%d",&n))
    {
        init();
        read();
        solve();
    }
    return 0;
}
