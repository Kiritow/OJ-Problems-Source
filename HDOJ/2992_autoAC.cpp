#include <iostream>
#include <cstdio>
#include <map>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn=10005;
const int INF=0x3fffffff;
int que[maxn];
int st[110];
int g[110][110];
int inque[maxn];
int dis[maxn];
int n, num;
struct Node
{
    int v, cost;
    Node(int v_,int cost_)
    {
        v=v_, cost=cost_;
    }
};
map<int,int>mp;
vector<Node>vt[maxn];
void spfa(int start)   
{
    int h=0, t=0;
    for(int i=1; i<=n; i++)
    {
        dis[i]=INF;
        inque[i]=0;
    }
    dis[start]=0;
    inque[start]=1;
    que[t++]=start;
    while(h!=t)
    {
        int u=que[h++];
        inque[u]=0; 
        if(h==maxn) h=0;  
        for(int i=0; i<vt[u].size(); i++)
        {
            int v=vt[u][i].v, cost=vt[u][i].cost;
            if(dis[v]>dis[u]+cost)
            {
                dis[v]=dis[u]+cost;  
                if(!inque[v])   
                {
                    inque[v]=1;
                    que[t++]=v;
                    if(t==maxn) t=0;  
                }
            }
        }
    }
    for(int i=1; i<=n; i++)
    {
        if(dis[i]<=600)
        {
            g[mp[start]][mp[i]]=1;
        }
    }
}
void floyd()
{
    for(int k=0; k<=num+1; k++)
        for(int i=0; i<=num+1; i++)
           for(int j=0; j<=num+1; j++)
           {
               if(g[i][j]>g[i][k]+g[k][j])
                    g[i][j]=g[i][k]+g[k][j];
           }
}
int main()
{
    int h, m, u, v, cost;
    while(cin >> n, n)
    {
        cin >> num;
        mp.clear();
        for(int i=0; i<=n; i++)
            vt[i].clear();
        for(int i=0; i<=num+2; i++)
            for(int j=0; j<=num+2; j++)
            {
                g[i][j]=INF;
                if(i==j) g[i][j]=0;
            }
        for(int i=1; i<=num; i++)
        {
            scanf("%d",st+i);
            mp[st[i]]=i;
        }
        st[0]=1;
        mp[1]=0;
        st[num+1]=n;
        mp[n]=num+1;
        cin >> m;
        for(int i=0; i<m; i++)
        {
            scanf("%d%d%d",&u,&v,&cost);
            vt[u].push_back(Node(v,cost));
            vt[v].push_back(Node(u,cost));
        }
        for(int i=0; i<=num; i++)
            spfa(st[i]);
        floyd();
        if(g[0][num+1]==INF)
            cout << -1 <<endl;
        else
            cout << g[0][num+1]-1 <<endl;
    }
    return 0;
}
