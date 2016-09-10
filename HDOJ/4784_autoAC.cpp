#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#include<cmath>
#include<vector>
#include<queue>
using namespace std;
typedef long long ll;
const int maxn=100+10;
const int maxm=200+10;
struct Edge
{
    int v,tm,cost;
    int next;
};
Edge edges[maxm<<1];
int head[maxn],nEdge=-1;
int n,m,B,K,R,T;
int d[maxn][210][6][6];
bool inq[maxn][210][6][6];
int prices[6][maxn];
void AddEdge(int u,int v,int tm,int cost)
{
    nEdge++;
    edges[nEdge].v=v;
    edges[nEdge].tm=tm;
    edges[nEdge].cost=cost;
    edges[nEdge].next=head[u];
    head[u]=nEdge;
}
struct Node
{
    int u,times,k,b;
    bool operator < (const Node &a) const
    {
        return times>a.times;
    }
};
int bfs()
{
    memset(d,0xff,sizeof(d));
    memset(inq,0,sizeof(inq));
    d[1][0][0][0]=R;
    Node node,tmp;
    priority_queue<Node>q;
    node.u=1;node.times=0;
    node.k=0;node.b=0;
    inq[1][0][0][0]=true;
    q.push(node);
    bool flag=false;
    while(!q.empty())
    {
        node=q.top();q.pop();
        if(node.times>T) break;
        int u=node.u;
        if(u==n) continue;
        for(int i=head[u];i!=-1;i=edges[i].next)
        {
            int v=edges[i].v;
            int cost,tim;
            cost=d[u][node.times][node.k][node.b]-edges[i].cost;
            tim=node.times+edges[i].tm;
            if(tim>T||cost<0) continue;
            if(v==n&&node.k!=0) continue;
            if(v==n) flag=true;
            tmp.u=v;tmp.times=tim;
            tmp.k=node.k;
            if(u!=1&&u!=n)
            {
                if(node.b+1<=B&&cost-prices[node.k][u]>d[v][tim][node.k][node.b+1])
                {
                    d[v][tim][node.k][node.b+1]=cost-prices[node.k][u];
                    tmp.b=node.b+1;
                    if(!inq[tmp.u][tmp.times][tmp.k][tmp.b])
                    {q.push(tmp);inq[tmp.u][tmp.times][tmp.k][tmp.b]=true;}
                }
                if(node.b>0&&cost+prices[node.k][u]>d[v][tim][node.k][node.b-1])
                {
                    d[v][tim][node.k][node.b-1]=cost+prices[node.k][u];
                    tmp.b=node.b-1;
                    if(!inq[tmp.u][tmp.times][tmp.k][tmp.b])
                    {q.push(tmp);inq[tmp.u][tmp.times][tmp.k][tmp.b]=true;}
                }
            }
            if(cost>d[v][tim][node.k][node.b])
            {
                d[v][tim][node.k][node.b]=cost;
                tmp.b=node.b;
                if(!inq[tmp.u][tmp.times][tmp.k][tmp.b])
                {q.push(tmp);inq[tmp.u][tmp.times][tmp.k][tmp.b]=true;}
            }
        }
        if(u!=1&&u!=n)
        {
            int cost=d[u][node.times][node.k][node.b];
            tmp.u=u;tmp.k=(node.k+1)%K;
            tmp.times=node.times+1;
            if(tmp.times>T) continue;
            if(node.b+1<=B&&cost-prices[node.k][u]>d[u][tmp.times][tmp.k][node.b+1])
            {
                d[u][tmp.times][tmp.k][node.b+1]=cost-prices[node.k][u];
                tmp.b=node.b+1;
                if(!inq[tmp.u][tmp.times][tmp.k][tmp.b])
                {q.push(tmp);inq[tmp.u][tmp.times][tmp.k][tmp.b]=true;}
            }
            if(node.b>0&&cost+prices[node.k][u]>d[u][tmp.times][tmp.k][node.b-1])
            {
                d[u][tmp.times][tmp.k][node.b-1]=cost+prices[node.k][u];
                tmp.b=node.b-1;
                if(!inq[tmp.u][tmp.times][tmp.k][tmp.b])
                {q.push(tmp);inq[tmp.u][tmp.times][tmp.k][tmp.b]=true;}
            }
            tmp.b=node.b;
            if(cost>d[u][tmp.times][tmp.k][tmp.b])
            {
                d[u][tmp.times][tmp.k][tmp.b]=cost;
                if(!inq[tmp.u][tmp.times][tmp.k][tmp.b])
                {q.push(tmp);inq[tmp.u][tmp.times][tmp.k][tmp.b]=true;}
            }
        }
    }
    if(!flag) return -1;
    int ans=0;
    for(int i=0;i<=T;++i)
      for(int j=0;j<=B;++j)
        ans=max(ans,d[n][i][0][j]);
    return ans;
}
int main()
{
    int t,tcase=0;
    scanf("%d",&t);
    while(t--)
    {
        tcase++;
        scanf("%d%d%d%d%d%d",&n,&m,&B,&K,&R,&T);
        memset(head,0xff,sizeof(head));
        nEdge=-1;
        int u,v,tm,cost;
        for(int i=0;i<K;++i)
          for(int j=1;j<=n;++j)
            scanf("%d",&prices[i][j]);
        for(int i=0;i<m;++i)
        {
            scanf("%d%d%d%d",&u,&v,&tm,&cost);
            AddEdge(u,v,tm,cost);
        }
        int ans=bfs();
        printf("Case #%d: ",tcase);
        if(ans!=-1) printf("%d\n",ans);
        else printf("Forever Alone\n");
    }
    return 0;
}
