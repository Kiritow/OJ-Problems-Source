#include<iostream>
#include<algorithm>
#include<vector>
#include<string.h>
using namespace std;
const int N = 1001;
struct node
{
    int v,w;
    node(){}
    node(int v,int w):v(v),w(w){}
};
vector<node> g[N];
int n,dist[N][2],cnt[N][2];
bool vis[N][2];
void Dijkstra(int s)
{
    for(int i=1;i<=n;i++)
    {
        dist[i][0]=INT_MAX;
        dist[i][1]=INT_MAX;
    }
    memset(vis,false,sizeof(vis));
    dist[s][0]=0;
    cnt[s][0]=1;
    for(int i=0;i<2*n;i++)
    {
        int temp=INT_MAX,u=-1,k;
        for(int j=1;j<=n;j++)
            if(!vis[j][0] && dist[j][0]<temp)
            {
                k=0;
                temp=dist[j][0];
                u=j;
            }
            else if(!vis[j][1] && dist[j][1]<temp)
            {
                k=1;
                temp=dist[j][1];
                u=j;
            }
        if(u==-1)
            break;
        vis[u][k]=true;
        vector<node>::iterator it=g[u].begin();
        for(;it!=g[u].end();it++)
        {
            int newdis=dist[u][k]+it->w;
            int v=it->v;
            if(newdis<dist[v][0])
            {
                dist[v][1]=dist[v][0];
                cnt[v][1]=cnt[v][0];
                dist[v][0]=newdis;
                cnt[v][0]=cnt[u][k];
            }
            else if(newdis==dist[v][0])
                cnt[v][0]+=cnt[u][k];
            else if(newdis<dist[v][1])
            {
                dist[v][1]=newdis;
                cnt[v][1]=cnt[u][k];
            }
            else if(newdis==dist[v][1])
                cnt[v][1]+=cnt[u][k];
        }
    }
}
int main()
{
    int T,m,a,b,c;
    int s,t;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d %d",&n,&m);
        for(int i=1;i<=n;i++)
            g[i].clear();
        for(int i=0;i<m;i++)
        {
            scanf("%d %d %d",&a,&b,&c);
            g[a].push_back(node(b,c));
        }
        scanf("%d %d",&s,&t);
        Dijkstra(s);
        int ans=cnt[t][0];
        if(dist[t][1]==dist[t][0]+1)
            ans+=cnt[t][1];
        printf("%d\n",ans);
    }
    return 0;
}
