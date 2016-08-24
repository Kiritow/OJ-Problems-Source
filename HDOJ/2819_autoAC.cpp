#include <map>
#include <set>
#include <stack>
#include <queue>
#include <cmath>
#include <ctime>
#include <vector>
#include <cstdio>
#include <cctype>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
using namespace std;
#define eps 1e-15
#define MAXN 105
#define INF 1000000007
#define MAX(a,b) (a > b ? a : b)
#define MIN(a,b) (a < b ? a : b)
#define mem(a) memset(a,0,sizeof(a))
bool G[MAXN][MAXN],vis[MAXN];
int Left[MAXN],N,M,T,a[MAXN],b[MAXN];
bool DFS(int u)
{
    for(int v=0;v<=N;v++) if(G[u][v] && !vis[v])
    {
        vis[v] = true;
        if(!Left[v] || DFS(Left[v]))
        {
            Left[v] = u;
            return true;
        }
    }
    return false;
}
int main()
{
    while(~scanf("%d", &N))
    {
        mem(G); mem(Left);
        int x,ans = 0;
        for(int i=1;i<=N;i++) for(int j=1;j<=N;j++)
        {
            scanf("%d", &x);
            if(x)G[i][j] = true;
        }
        for(int i=1;i<=N;i++)
        {
            mem(vis);
            if(DFS(i)) ans ++;
        }
        if(ans < N){printf("-1\n");continue;}
        int tot = 0,j;
        for(int i=1;i<=N;i++)
        {
            for(j=1;j<=N && Left[j]!=i ;j++);
            if(i != j)
            {
                a[tot] = i;  b[tot] = j; tot ++;
                int t = Left[i]; Left[i] = Left[j]; Left[j] = t;
            }
        }
        printf("%d\n",tot);
        for(int i=0;i<tot;i++) printf("C %d %d\n", a[i],b[i]);
    }
    return 0;
}
