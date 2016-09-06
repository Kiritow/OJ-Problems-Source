#include<iostream>
#include<cstdio>
#include<map>
#include<cstring>
#include<cmath>
#include<vector>
#include<algorithm>
#include<set>
#include<string>
#include<queue>
#define inf 1<<30
#define M 60005
#define N 10005
#define maxn 300005
#define eps 1e-10
#define zero(a) fabs(a)<eps
#define Min(a,b) ((a)<(b)?(a):(b))
#define Max(a,b) ((a)>(b)?(a):(b))
#define pb(a) push_back(a)
#define mem(a,b) memset(a,b,sizeof(a))
#define LL long long
#define lson step<<1
#define rson step<<1|1
#define MOD 1000000009
using namespace std;
int maze[10][10];
int n;
int way[4][2]={0,1,0,-1,1,0,-1,0};
int vis[10][10];
bool check(int x,int y)
{
    if(x<0||y<0||x>=n||y>=n) return false;
    return true;
}
void floodfill(int x,int y,int c)
{
    vis[x][y]=1;
    for(int i=0;i<4;i++)
    {
        int tx=x+way[i][0];
        int ty=y+way[i][1];
        if(!check(tx,ty)) continue;
        if(vis[tx][ty]==1) continue;
        if(maze[tx][ty]==c) floodfill(tx,ty,c);
        else vis[tx][ty]=2;
    }
}
int get_cnt(int col)
{
    int cnt=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(maze[i][j]==col&&vis[i][j]==2)
            {
                cnt++;
                floodfill(i,j,maze[i][j]);
            }
        }
    }
    return cnt;
}
int get_h()
{
    bool flag[6];mem(flag,false);
    int cnt=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(vis[i][j]!=1&&!flag[maze[i][j]])
            {
                cnt++;
                flag[maze[i][j]]=true;
            }
        }
    }
    return cnt;
}
int depth;
bool IDAstar(int dep)
{
    if(depth==dep) return get_h()==0;
    if(dep+get_h()>depth) return false;
    for(int i=0;i<6;i++)
    {
        int tmp[10][10];
        memcpy(tmp,vis,sizeof(vis));
        if(get_cnt(i)==0) continue;
        if(IDAstar(dep+1)) return true;
        memcpy(vis,tmp,sizeof(vis));
    }
    return false;
}
int main()
{
    while(scanf("%d",&n)!=EOF&&n)
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                scanf("%d",&maze[i][j]);
            }
        }
        mem(vis,0);
        floodfill(0,0,maze[0][0]);
        depth=get_h();
        while(true)
        {
            if(IDAstar(0)) break;
            depth++;
        }
        printf("%d\n",depth);
    }
    return 0;
}
