#pragma comment(linker, "/STACK:1024000000,1024000000")
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <math.h>
#include <stdlib.h>
#include <time.h>
using namespace std;
const int MAXN = 110;
int color[MAXN];
int head[MAXN];
struct Edge
{
    int to,next;
}edge[MAXN*MAXN];
int tot;
void addedge(int u,int v)
{
    edge[tot].to = v;
    edge[tot].next = head[u];
    head[u] = tot++;
}
void init()
{
    tot = 0;
    memset(head,-1,sizeof(head));
}
bool dfs(int u,int col)
{
    color[u] = col;
    for(int i = head[u];i != -1;i = edge[i].next)
    {
        int v = edge[i].to;
        if(color[v] != -1)
        {
            if(color[v]==col)return false;
            continue;
        }
        if(!dfs(v,!col))return false;
    }
    return true;
}
int g[MAXN][MAXN];
int main()
{
    int n;
    while(scanf("%d",&n) == 1)
    {
        memset(g,0,sizeof(g));
        int t;
        for(int i = 1;i <= n;i++)
        {
            while(scanf("%d",&t) && t)
            {
                g[i][t] = 1;
            }
        }
        init();
        for(int i = 1;i <= n;i++)
            for(int j = i+1;j <= n;j++)
                if(g[i][j] == 0 || g[j][i] == 0)
                {
                    addedge(i,j);
                    addedge(j,i);
                }
        memset(color,-1,sizeof(color));
        bool flag = true;
        for(int i = 1;i <= n;i++)
            if(color[i] == -1 && dfs(i,0) == false)
            {
                flag = false;
                break;
            }
        if(flag)printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
