#include<cstdio>
#include<cstring>
#include<iostream>
#include<vector>
#include<string>
#include<set>
#include<algorithm>
#include<map>
#include<iostream>
using namespace std;
const int inf = 100000;
const int maxn = 101;
vector<int> edge[maxn];
int a[maxn],b[maxn];
int f[maxn][2],g[maxn][2];
void dfs(int u,int fa)
{
    f[u][0]=0;
    g[u][0]=0;
    int sz=edge[u].size();
    int m1=inf,m2=inf;
    bool leaf=true;
    for(int i=0;i<sz;i++)
    {
        int v=edge[u][i];
        if(v==fa) continue;
        dfs(v,u);
        leaf=false;
        int tmp=min(f[v][0],g[v][1]);
        f[u][0]+=tmp;
        m1=min(m1,f[v][1]-tmp);
        tmp=min(g[v][0],f[v][1]);
        g[u][0]+=tmp;
        m2=min(m2,g[v][1]-tmp);
    }
    if(leaf)
    {
        f[u][1]=a[u];
        f[u][0]=a[u]/2;
        g[u][1]=b[u];
        g[u][0]=b[u]/2;
    }
    else 
    {
        f[u][1]=f[u][0] + min(a[u],m1+a[u]/2);
        f[u][0]+=a[u]/2;
        g[u][1]=g[u][0] + min(b[u],m2+b[u]/2);
        g[u][0]+=b[u]/2;
    }
}
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        for(int i=0;i<=n;i++) edge[i].clear();
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        for(int i=1;i<=n;i++) scanf("%d",&b[i]);
        for(int i=1,u,v;i<n;i++)
        {
            scanf("%d%d",&u,&v);
            edge[u].push_back(v);
            edge[v].push_back(u);
        }
        dfs(1,0);
        printf("%d\n",min(f[1][1],g[1][1]));
    }
    return 0;
}
