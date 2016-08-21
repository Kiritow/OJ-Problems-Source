#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
vector<int> g[4000];
struct node
{
    int x,y,s;
}PEO[4000];
int mx[4000],my[4000],n1,n2,dx[4000],dy[4000];
bool use[4000];
bool find(int u)
{
    for(int i=0;i<g[u].size();i++)
    {
        int v=g[u][i];
        if(!use[v]&&dy[v]==dx[u]+1)
        {
            use[v]=true;
            if(!my[v]||find(my[v]))
            {
                mx[u]=v;
                my[v]=u;
                return true;
            }
        }
    }
    return false;
}
int HKmatch()
{
    memset(mx,0,sizeof(mx));
    memset(my,0,sizeof(my));
    int ans=0;
    while(true)
    {
        bool flag=false;
        queue<int> q;
        memset(dx,0,sizeof(dx));
        memset(dy,0,sizeof(dy));
        for(int i=1;i<=n1;i++)
        {
            if(!mx[i]) q.push(i);
        }
        while(!q.empty())
        {
            int u=q.front(); q.pop();
            for(int i=0;i<g[u].size();i++)
            {
                int v=g[u][i];
                if(!dy[v])
                {
                    dy[v]=dx[u]+1;
                    if(my[v])
                    {
                        dx[my[v]]=dy[v]+1;
                        q.push(my[v]);
                    }
                    else flag=true;
                }
            }
        }
        if(!flag) break;
        memset(use,0,sizeof(use));
        for(int i=1;i<=n1;i++)
            if(!mx[i]&&find(i))
                 ans++;
    }
    return ans;
}
int main()
{
    int T,cas=1;
    scanf("%d",&T);
    while(T--)
    {
        memset(g,0,sizeof(g));
        int time;
        scanf("%d",&time);
        scanf("%d",&n1);
        for(int i=1;i<=n1;i++)
        {
            int x,y,s;
            scanf("%d%d%d",&x,&y,&s);
            PEO[i].x=x;PEO[i].y=y;PEO[i].s=s;
        }
        scanf("%d",&n2);
        for(int i=1;i<=n2;i++)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            for(int j=1;j<=n1;j++)
            {
                int dist1=(PEO[j].x-x)*(PEO[j].x-x)+(PEO[j].y-y)*(PEO[j].y-y);
                int dist2=(PEO[j].s*time)*(PEO[j].s*time);
                if(dist2>=dist1)
                {
                    g[j].push_back(i);
                }
            }
        }
        printf("Scenario #%d:\n%d\n\n",cas++,HKmatch());
    }
}
