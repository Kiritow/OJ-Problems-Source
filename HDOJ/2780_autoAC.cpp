#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<string>
#include<algorithm>
#include<memory.h>
#include<queue>
using namespace std;
int cnt,mark;
char vis[12][12];
int map[12][12];
struct Node
{
    int x,y;
}node[102];
int Judge(int x,int y,int z)
{
    int i,j,n,m;
    for(i=0;i<9;i++)
    {
        if(map[i][y]==z && i!=x)
            return 1;
    }
    for(j=0;j<9;j++)
    {
        if(map[x][j]==z && j!=y)
            return 1;
    }
    for(n=0,i=x/3*3;n<3;n++,i++)
        for(m=0,j=y/3*3;m<3;m++,j++)
        {
            if(i==x && j==y)
                continue;
            if(map[i][j]==z)
                return 1;
        }
        return 0;
}
int judge()
{
    int i,j;
    for(i=0;i<9;i++)
        for(j=0;j<9;j++)
        {
            if(!map[i][j])
                continue;
            if(Judge(i,j,map[i][j]))
                return 1;
        }
        return 0;
}
void dfs(int n)
{
    int i;
    if(n==cnt)
    {
        mark=1;
        return;
    }
    if(mark)
        return;
    for(i=1;i<=9;i++)
    {
        if(Judge(node[n].x,node[n].y,i))
            continue;
        map[node[n].x][node[n].y]=i;
        dfs(n+1);
        if(mark)
            return;
        map[node[n].x][node[n].y]=0;
    }
}
void clear()
{
    cnt=0;
    memset(map,0,sizeof(map));
    memset(vis,0,sizeof(vis));
    memset(node,0,sizeof(node));
}
int main()
{
    int k,i,j;
    bool f=false;
    scanf("%d",&k);
    while(k--)
    {
        if(f)
            printf("\n");
        f=true;
        clear();
        for(i=0;i<9;i++)
        {
            scanf("%s",vis[i]);
        }
        for(i=0;i<9;i++)
        {
            for(j=0;j<9;j++)
            {
                map[i][j]=vis[i][j]-'0';
                if(!map[i][j])
                {
                    node[cnt].x=i;
                    node[cnt].y=j;
                    cnt++;
                }
            }
        }
        if(judge())
        {
            printf("Could not complete this grid.\n");
            continue;
        }
        mark=0;
        dfs(0);
        if(mark)
        {
            for(i=0;i<9;i++)
            {
                for(j=0;j<9;j++)
                    printf("%d",map[i][j]);
                printf("\n");
            }
        }
        else
        {
            printf("Could not complete this grid.\n");
        }
    }    
    return 0;
}
