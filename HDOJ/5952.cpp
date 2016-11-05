#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;

#define MAXN 105
#define MAXM 2050

int G[MAXN][MAXN];/// G: map
int pec[MAXN];/// pec: Point Edge Counter
int ec;/// ec: Edge Counter

int vec[MAXN];
int lec;/// lec: Loop Edge Counter
int ans;/// ans: Answer Counter

int _global_s; /// Global S

struct _edge
{
    int target_point;
    int last_edge_id;
}edge[MAXM];


void dfs(int EdgeStartPoint)
{
    if(lec==_global_s)
    {
        ++ans;
        return;
    }

    for(int i=pec[EdgeStartPoint];i!=-1;i=edge[i].last_edge_id)
    {
        int v=edge[i].target_point;
        int flag=1;

        for(int j=1;j<=lec;j++)
        {
            if(!G[v][vec[j]])
            {
                flag=0;break;
            }
        }

        if(flag)
        {
            lec++;
            vec[lec]=v;
            dfs(v);
            lec--;
        }
    }
}

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        /// init
        memset(pec,-1,sizeof(pec));
        memset(G,0,sizeof(G));
        ec=0;

        /// Input
        int N,M,S;
        scanf("%d %d %d",&N,&M,&S);
        _global_s=S;
        for(int i=0;i<M;i++)
        {
            int u,v;
            scanf("%d %d",&u,&v);
            G[u][v]=G[v][u]=1;
            int uu=min(u,v);
            int vv=max(u,v);
            edge[ec].target_point=vv;
            edge[ec].last_edge_id=pec[uu];
            pec[uu]=ec++;
        }

        ans=0;
        for(int i=1;i<=N;i++)
        {
            lec=1;
            vec[1]=i;
            dfs(i);
        }
        printf("%d\n",ans);
    }
    return 0;
}
