#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;
const int maxn=110;
const int oo=0x3fffffff;
int S[maxn], C[maxn];
int mp[maxn], visit[maxn][3*maxn];
int map[maxn][maxn], cap[maxn][maxn], dis[maxn][3*maxn];
int n, m, V, T, st, sd, ss, dd;
struct node
{
    int u, t;
};
void floyd()
{
    ss=n, dd=n+1, S[dd]=0;
    for(int k=0; k<n; k++)
        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++)
                if(map[i][j]>map[i][k]+map[k][j]) map[i][j]=map[i][k]+map[k][j];
    for(int i=0; i<n; i++)
        for(int j=i+1; j<n; j++)
        {
            if(map[i][j]!=oo)
            {
                if(S[i]<S[j]) cap[i][j]=map[i][j]+C[j];
                if(S[j]<S[i]) cap[j][i]=map[i][j]+C[i];
            }
        }
    cap[ss][st]=C[st];
    for(int i=0; i<n; i++)
        if(i!=st&&map[st][i]!=oo) cap[ss][i]=map[st][i]+C[i];
    for(int i=0; i<n; i++)
        if(i!=sd&&map[i][sd]!=oo) cap[i][dd]=map[i][sd];
}
int spfa()
{
    queue<node>q;
    for(int i=0; i<=n+1; i++)
        for(int j=0; j<=V; j++) dis[i][j]=-oo, visit[i][j]=0;
    node s, p;
    s.u=ss, s.t=0;
    q.push(s);
    dis[ss][0]=0;
    visit[ss][0]=1;
    while(!q.empty())
    {
        p=q.front();
        q.pop();
        visit[p.u][p.t]=0;
        for(int i=0; i<=n+1; i++)
        {
            if(p.u!=i&&cap[p.u][i]!=oo)
            {
                int tp=p.t+cap[p.u][i];
                if(tp<=V&&dis[i][tp]<dis[p.u][p.t]+S[i])
                {
                    dis[i][tp]=dis[p.u][p.t]+S[i];
                    s.u=i, s.t=tp;
                    if(!visit[s.u][s.t]) visit[s.u][s.t]=1,q.push(s);
                }
            }
        }
    }
    int maxx=0;
    for(int i=0; i<=V; i++)
    {
        maxx=max(maxx,dis[sd][i]);
        maxx=max(maxx,dis[dd][i]);
    }
    return maxx;
}
int main()
{
    cin >> T;
    for(int tcase=1; tcase<=T; tcase++)
    {
        scanf("%d%d%d%d%d",&n,&m,&V,&st,&sd);
        for(int i=0; i<=n+1; i++)
            for(int j=0; j<=n+1; j++)
            {
                  map[i][j]=oo, cap[i][j]=oo;
                  if(i==j) map[i][j]=cap[i][j]=0;
            }
        for(int i=0; i<n; i++) scanf("%d",C+i);
        for(int i=0; i<n; i++) scanf("%d",S+i);
        while(m--)
        {
            int u, v, val;
            scanf("%d%d%d",&u,&v,&val);
            map[u][v]=min(map[u][v],val);
            map[v][u]=min(map[v][u],val);
        }
        floyd();
        int ans=spfa();
        printf("Case #%d:\n%d\n",tcase,ans);
    }
    return 0;
}
