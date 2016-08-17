#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
const int maxn=1e4+10;
int n,m,map[maxn][3],color[maxn];
bool vis[maxn];
bool DFS(int x)
{
    for(int i=0;i<2;i++)
    {
    int ita=map[x][i];
    if(!vis[ita])
    {
        vis[ita]=1;
        if(color[ita]==-1||DFS(color[ita]))
        {
        color[ita]=x;
        return true;
        }
    }
    }
    return false;
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
    memset(color,-1,sizeof(color));
    scanf("%d%d",&m,&n);
    for(int i=0;i<m;i++)
        scanf("%d%d",&map[i][0],&map[i][1]);
    int flag=0;
    for(int i=0;i<m;i++)
    {
        memset(vis,0,sizeof(vis));
        if(!DFS(i))
        {
        flag=1;
        break;
        }
    }
    if(flag)
        printf("rehash necessary\n");
    else
        printf("successful hashing\n");
    }
    return 0;
}
