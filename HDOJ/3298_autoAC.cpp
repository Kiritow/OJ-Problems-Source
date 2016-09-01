#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <cmath>
using namespace std;
#include <queue>
#include <stack>
#include <vector>
#include <deque>
#include <set>
#include <map>
#include <time.h>;
#define cler(arr, val)    memset(arr, val, sizeof(arr))
typedef long long  LL;
const int MAXN = 200010;
const int MAXM = 200006;
const int INF = 0x3f3f3f3f;
const int mod = 10000007;
LL point[MAXN],num[MAXN];
vector<int>edge[MAXN];
bool vis[MAXN];
LL abs1(LL a)
{
    if(a>0) return a;
    else return -a;
}
void dfs(int u)
{
    vis[u]=true;
    for(int i=0;i<edge[u].size();i++)
    {
        int v=edge[u][i];
        if(!vis[v])
        {
            dfs(v);
            point[u]+=point[v];
        }
    }
}
int main()
{
    int m,n,cas=0;
    while(scanf("%d%d",&n,&m),m+n)
    {
        LL sum=0;
        cler(point,0);
        cler(num,0);
        for(int i=1;i<=n;i++)
        {
            edge[i].clear();
            scanf("%I64d",&point[i]);
            sum+=point[i];
        }
        for(int i=1;i<=m;i++)
        {
            int a,b;
            scanf("%d%d",&a,&b);
            edge[a].push_back(b);
            edge[b].push_back(a);
        }
        LL ans=9999999999999;
        cler(vis,false);
        dfs(1);
        for(int i=1;i<=n;i++)
            ans=min(ans,abs1(sum-2*point[i]));
        printf("Case %d: %I64d\n",++cas,ans);
    }
}
