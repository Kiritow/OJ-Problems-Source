#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
using namespace std;
const int maxn=2505;
const int maxc=55;
vector<int>e[maxn];
int vis[maxn],pre[maxn];
int map[maxc][maxc];
int dir[12][2]={{-1,-2},{-2,-1},{-2,1},{-1,2},{1,2},{2,1},{2,-1},{1,-2},{-1,0},{0,1},{1,0},{0,-1}};
int find(int u)
{
    int i,j,v;
    for(i=0;i<e[u].size();i++)
    {
        v=e[u][i];
        if(!vis[v])
        {
            vis[v]=1;
            if(pre[v]==-1||find(pre[v]))
            {
                pre[v]=u;
                return 1;
            }
        }
    }
    return 0;
}
string a[maxn],b[maxn];
int main()
{
    int n,m,tt=0;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        if(n==0&&m==0)break;
        int i,j,k;
        for(i=1;i<=n*m;i++)
            e[i].clear();
        for(i=1;i<=n;i++)
            for(j=1;j<=m;j++)
            cin>>map[i][j];
        int x,y,ans=0,t;
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=m;j++)
            {
                t=(i+j)%2;
                if(map[i][j]==-1)continue;
                for(k=0;k<12;k++)
                {
                    if(!(map[i][j]&(1<<k)))continue;
                    x=i+dir[k][0];
                    y=j+dir[k][1];
                    if(x<=0||y<=0||x>n||y>m||map[x][y]==-1)continue;
                    if(t)e[(i-1)*m+j].push_back((x-1)*m+y);
                    else e[(x-1)*m+y].push_back((i-1)*m+j);
                }
            }
        }
        memset(pre,-1,sizeof(pre));
        for(i=1;i<=n*m;i++)
        {
            memset(vis,0,sizeof(vis));
            ans+=find(i);
        }
        printf("%d. %d\n",++tt,ans);
    }
    return 0;
}
