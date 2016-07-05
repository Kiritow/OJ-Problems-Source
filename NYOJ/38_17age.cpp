#include<iostream>
#include<algorithm>
#include<stdio.h>
#include<string.h>
#include<math.h>
using namespace std;
const int maxn=505;
const int INF=0x3f3f3f3f;
int map[maxn][maxn];
int dis[maxn];
int vis[maxn];
int N;//N组测试数据
int V;//点的数量
int E;//边的数量
int min_num;//最小外接花费
void init()
{
    scanf("%d%d",&V,&E);
    for(int i=0; i<=V; i++)//初始化图
        for(int j=0; j<=V; j++)
            i==j?map[i][j]=0:map[i][j]=INF;
    while(E--)//建图
    {
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        map[a][b]=c;//无向图
        map[b][a]=c;
    }
    min_num=INF;
    for(int i=1; i<=V; i++)
    {
        int x;
        scanf("%d",&x);
        min_num=min(min_num,x);//生成树连接到外界的最小花费
        dis[i]=map[i][1];//从1开始构造最小生成树
    }
    memset(vis,0,sizeof(vis));
    vis[1]=1;//0代表是外界
}
void Prim()
{
    int min_cost=0;//初始化最小花费
    for(int i=1; i<V; i++)
    {
        int minn=INF;
        int point_minn;
        for(int j=1; j<=V; j++)
            if(vis[j]==0&&minn>dis[j])
            {
                point_minn=j;
                minn=dis[j];
            }
        if(minn==INF)
            break;
        min_cost+=dis[point_minn];
        vis[point_minn]=1;
        for(int j=1; j<=V; j++)
            if(vis[j]==0&&dis[j]>map[point_minn][j])
                dis[j]=map[point_minn][j];
    }
    printf("%d\n",min_cost+min_num);
}
int main()
{
    scanf("%d",&N);
    while(N--)
    {
        init();
        Prim();
    }
    return 0;
}
