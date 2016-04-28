#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int map[90][90];
int vis[90][90];
void reset_map(int incmaxx,int incmaxy)
{
    memset(map,0,sizeof(int)*90*90);
    memset(vis,0,sizeof(int)*90*90);
    int i;
    for(i=0;i<incmaxx+2;i++)
    {
        vis[i][0]=1;
        vis[i][incmaxy+1]=1;
    }
    for(i=0;i<incmaxy+2;i++)
    {
        vis[0][i]=1;
        vis[incmaxx+1][i]=1;
    }
}
 
void dfs(int x,int y)
{
    if(map[x][y]==0||vis[x][y]==1) return;
    vis[x][y]=1;
    dfs(x-1,y);
    dfs(x+1,y);
    dfs(x,y-1);
    dfs(x,y+1);
}
 
void deal(int incmaxx,int incmaxy)
{
    int i,j;
    int count=0;
    for(i=1;i<incmaxx+1;i++)
    {
        for(j=1;j<incmaxy+1;j++)
        {
            if(map[i][j]==1&&vis[i][j]==0)
            {
                count++;
                dfs(i,j);
            }
        }
    }
    printf("%d\n",count);
}
char buff[128];
int main()
{
    int all,maxx,maxy,i,j;
#ifndef __GNUC__
    freopen("D:\\std.txt","r",stdin);
#endif
    scanf("%d",&all);
    for(;all>0;all--)
    {
        scanf("%d %d%*c",&maxx,&maxy);
        reset_map(maxx,maxy);
        for(i=0;i<maxx;i++)
        {
            memset(buff,0,128);
            gets(buff);
            for(j=0;j<maxy;j++)
            {
                if(buff[j]=='0')
                {
                    map[i+1][j+1]=0;
                }
                else
                {
                    map[i+1][j+1]=1;
                }
            }
        }
        deal(maxx,maxy);
    }
    return 0;
}
 
Enter file contents here
