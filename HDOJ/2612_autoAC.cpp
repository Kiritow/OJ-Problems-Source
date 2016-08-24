#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>
#include <iostream>
#include <queue> 
#include <set>
#include <vector>
using namespace std;
struct node
{
    int x,y;
    int time;
};
    int n,m;
queue<node> qq;
char tm[205][205];     
char vis[205][205];
int kfc[2005][2];
int ans1[505][505];
int ans2[505][505];
int ans[505][505][3];
 int dir[][2]={0,-1, 0,1, -1,0, 1,0};           
    int y11,y2;
    int m1,m2;
int bfs(int f,int c)
{
    while(!qq.empty()) qq.pop();
    int i;
    node tmp;
    tmp.x=f;
    tmp.y=c;
    tmp.time=0;
    qq.push(tmp);
    vis[f][c]=1;
    while(!qq.empty())
    {
        node t=qq.front();
        qq.pop();
        node k=t;
        for (i=0;i<4;i++)
        {
            t=k;
            t.x+=dir[i][0];
            t.y+=dir[i][1];
            if ((tm[t.x][t.y]=='.'||tm[t.x][t.y]=='@')&&vis[t.x][t.y]==0&& t.x>=1 &&t.y<=m&&t.y>=1&&t.x<=n)
            {
                            vis[t.x][t.y]=1;
                t.time++;
                {  
                    if ( f==y11 && c==y2 )
                    { 
                         ans[t.x][t.y][0]=t.time;
                    }
                    else
                    { 
                      ans[t.x][t.y][1]=t.time;
                    }
                } 
                qq.push(t);
            }
        }
    }
    return 0;
}
int main()
{  
    int i,j;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        getchar();
        int ok=0; 
        for (i=1;i<=n;i++)
        {
            for (j=1;j<=m;j++)
            {
                scanf("%c",&tm[i][j]);
                if (tm[i][j]=='Y')
                {
                    y11=i;
                    y2=j;
                }    
                if (tm[i][j]=='M')
                {
                    m1=i;
                    m2=j; 
                }
                if (tm[i][j]=='@')
                {
                    kfc[++ok][0]=i;
                    kfc[ok][1]=j;
                }
            }
            getchar();
        } 
            int  max=0x7f7f7f7f;
        int h;
         memset(vis,0,sizeof(vis));
        bfs(y11,y2);
    memset(vis,0,sizeof(vis));
        bfs(m1,m2);
        for (h=1;h<=ok;h++)
        {  
            int q1=kfc[h][0];
            int q2=kfc[h][1];
                     max=__min(ans[q1][q2][0]+ans[q1][q2][1],max);
        } 
        __int64 ans=max*11;
        printf("%I64d\n",ans);
    }
    return 0;
}
