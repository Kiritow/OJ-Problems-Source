#include<iostream>
#include<stdio.h>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;
const int N = 10010;
struct node
{
    int v;
    int w;
    node(){};
    node(int x,int y):v(x),w(y){}
    bool operator <(const node &cp)const
    {
        return w > cp.w;
    }
};
vector<node>map[N];
priority_queue<node>que;
int dist[N],visit[N];
int n,m;
void input()
{
    scanf("%d%d",&n,&m);
    for(int i = 0;i <= n;i ++)
        map[i].clear();
    for(int i = 0;i < n;i ++)
        scanf("%d",&dist[i]);
    int u,v,a,b;
    while(m --)
    {
        scanf("%d%d%d%d",&u,&v,&a,&b);
        map[u].push_back(node(v,a));
        map[v].push_back(node(u,b));
    }
    for(int i = 0;i < n;i ++)
       visit[i] = 0;
    while(!que.empty())
          que.pop();
    for(int i = 0;i < n;i ++)
        que.push(node(i,dist[i]));
}
void solve()
{
    int x,y;
    while(!que.empty())
    {
        node tmp = que.top();
        que.pop();
        if(visit[tmp.v])
           continue;
        visit[tmp.v] = 1;
        dist[tmp.v] = tmp.w;
        for(int i = 0;i < map[tmp.v].size();i ++)
        {
            x = map[tmp.v][i].v;
            y = map[tmp.v][i].w;
            if(dist[x] > tmp.w+y)
            {
                dist[x] = tmp.w+y;
                que.push(node(x,dist[x]));
            }
        }
    }
}
int main()
{
    int t,cas=0;
    scanf("%d",&t);
    while(t --)
    {
        cas ++;
        input();
        solve();
        int ans = 0;
        for(int i = 1;i < n;i ++)
        {
            if(dist[ans] < dist[i])
                 ans = i;
        }
        printf("Scenario #%d:\n",cas);
        printf("%d\n\n",ans);
    }
    return 0;
}
