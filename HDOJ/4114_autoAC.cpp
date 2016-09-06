#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
#define INF 0x3f3f3f3f
typedef long long LL;
const int N=55;
int adj[N][N];
int pos[N],T[N],FT[N],pass[N];
int dis[N][1<<8][1<<8];
int n,m,K;
void floyed()
{
    for(int k=1;k<=n;k++)
    {
        for(int i=1;i<=n;i++) if(i!=k)
        {
            for(int j=1;j<=n;j++) if(j!=i&&j!=k)
            {
                adj[i][j]=min(adj[i][j],adj[i][k]+adj[k][j]);
            }
        }
    }
}
int fun()
{
    int ans=INF;
    dis[1][0][0]=0;
    for(int s1=0;s1<(1<<K);s1++)
    {
        for(int s2=0;s2<(1<<K);s2++)
        {
            for(int i=1;i<=n;i++)
            {
                int now=dis[i][s1][s2];
                if(now==INF) continue;
                if(s2==((1<<K)-1)) ans=min(ans,now+adj[i][1]);
                for(int j=0;j<K;j++) if((s2&(1<<j))==0)
                {
                    int &nxt=dis[pos[j]][ s1|pass[ pos[j] ] ][s2^(1<<j)];
                    int add=adj[i][pos[j]];
                    if(s1&(1<<j)) add+=FT[j];
                    else add+=T[j];
                    nxt=min(nxt,now+add);
                }
                for(int j=1;j<=n;j++)
                {
                    int &nxt=dis[j][s1|pass[j]][s2];
                    int add=adj[i][j];
                    nxt=min(nxt,now+add);
                }
            }
        }
    }
    return ans;
}
int main()
{
    int t,t_cnt=0;
    scanf("%d",&t);
    while(t--)
    {
        memset(dis,0x3f,sizeof(dis));
        memset(adj,0x3f,sizeof(adj));
        memset(pass,0,sizeof(pass));
        for(int i=0;i<N;i++) adj[i][i]=0;
        scanf("%d%d%d",&n,&m,&K);
        for(int i=0;i<m;i++)
        {
            int a,b,c; scanf("%d%d%d",&a,&b,&c);
            adj[a][b]=adj[b][a]=c;
        }
        floyed();
        for(int i=0;i<K;i++)
        {
            scanf("%d%d%d",&pos[i],&T[i],&FT[i]);
            int num; scanf("%d",&num);
            for(int j=0;j<num;j++)
            {
                int tmp; scanf("%d",&tmp);
                pass[tmp]|=(1<<i);
            }
        }
        printf("Case #%d: %d\n",++t_cnt,fun());
    }
    return 0;
}
