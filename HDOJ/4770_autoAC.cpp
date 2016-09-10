#include <iostream>
#include <string.h>
#include <stdio.h>
#include <algorithm>
using namespace std;
int getnum(int x)
{
    int sum=0;
    while(x)
    {
        sum+=x%2;
        x/=2;
    }
    return sum;
}
int dir[4][2]={-1,0,0,1,1,0,0,-1};
char map[210][210];
int vis[210][210];
int po[20][2];
int num,n,m;
int check(int x,int y)
{
    if(x<1||y<1||x>n||y>m)
    return 0;
    return 1;
}
int isok(int flag,int limit)
{
    int i;
    for(i=0;i<num;i++)
    {
        int x=po[i][0],y=po[i][1];
        if(vis[x][y]==limit)
        continue;
        vis[x][y]=0;
    }
    for(i=0;i<num;i++)
    {
        if((flag>>i)&1)
        {
            int x=po[i][0],y=po[i][1];
            if(check(x-1,y)&&map[x-1][y]=='#')
            return 0;
            if(!vis[x-1][y])
            vis[x-1][y]=1;
            if(check(x,y+1)&&map[x][y+1]=='#')
            return 0;
            if(!vis[x][y+1])
            vis[x][y+1]=1;
            if(!vis[x][y])
            vis[x][y]=1;
        }
    }
    for(i=0;i<num;i++)
    {
        int x=po[i][0],y=po[i][1];
        if(vis[x][y]==0)
        return 0;
    }
    return 1;
}
int main()
{
    while(scanf("%d%d",&n,&m)&&(n+m))
    {
        memset(vis,0,sizeof(vis));
        int i,j,k;
        for(i=1;i<=n;i++)
        {
            scanf("%s",map[i]+1);
        }
        num=0;
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=m;j++)
            {
                if(map[i][j]=='.')
                {
                    po[num][0]=i;
                    po[num++][1]=j;
                }
            }
        }
        if(num==0)
        {
            printf("0\n");
            continue;
        }
        int limit=1<<num,sum=10000;
        int ans=2100000000;
        for(i=0;i<num;i++)
        {
            int x=po[i][0],y=po[i][1],tmp=0;
            for(j=0;j<4;j++)
            {
                for(k=0;k<num;k++)
                {
                    int xx=po[k][0],yy=po[k][1];
                    vis[xx][yy]=0;
                }
                if((check(dir[j][0]+x,dir[j][1]+y)&&map[dir[j][0]+x][dir[j][1]+y]=='#')||(check(dir[(j+1)%4][0]+x,dir[(j+1)%4][1]+y)&&map[dir[(j+1)%4][0]+x][dir[(j+1)%4][1]+y]=='#'))
                continue;
                sum++;
                vis[dir[j][0]+x][dir[j][1]+y]=sum;
                vis[dir[(j+1)%4][0]+x][dir[(j+1)%4][1]+y]=sum;
                vis[x][y]=sum;
                for(k=0;k<limit;k++)
                {
                    if((k>>i)&1)
                    continue;
                    if(isok(k,sum))
                    {
                        ans=min(ans,1+getnum(k));
                    }
                }
            }
        }
        if(ans==2100000000)
        printf("-1\n");
        else
        printf("%d\n",ans);
    }
    return 0;
}
