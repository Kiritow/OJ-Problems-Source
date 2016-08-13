#include<iostream>
#include<cstdio>
#include<queue>
#include<algorithm>
#define v 21
#include<cstring>
using namespace std;
char mapp[21][21];
int x1,x2,y1,y2;
int dir[4][2]={{1,0},{0,-1},{-1,0},{0,1}};
int used2[21][21];
int m,n;
int ans;int used[21][21];
int check(int y,int x)
{
    if(y>m||y<1||x>n||x<1)
    {
        return 1;
    }
    if(mapp[y][x]=='*'||used[y][x]==1)
    return 1;
    return 0;
}
struct node{
    int x,y,time;
    bool friend operator<(node n1,node n2)
    {
        return n1.time>n2.time;
    }
};
int bfs()
{
    priority_queue<node>q;
    node pre;
    int i,X,Y;
    pre.x=x1;pre.y=y1;
    pre.time=0;
    q.push(pre);
    while(!q.empty())
    {
        pre=q.top();
        q.pop();
        if(pre.x==x2&&pre.y==y2)
        {
            return pre.time;
        }
         node next;
         if(mapp[pre.y][pre.x]=='.'||mapp[pre.y][pre.x]=='S')
         {
                if(!used2[pre.y][pre.x])
                {
                    used2[pre.y][pre.x]=1;
                    next.x=pre.x;next.y=pre.y;next.time=pre.time+1;
                    q.push(next);
                }
         }
        for(i=0;i<4;i++)
        {
            X=pre.x+dir[i][0];Y=pre.y+dir[i][1];
            if(check(Y,X))
            continue;
            if(mapp[Y][X]=='.')
            {
                next.x=X;next.y=Y;next.time=pre.time+1;
                used[Y][X]=1;
                q.push(next);
            }
           else if(mapp[Y][X]=='|')
           {
               if(pre.time%2==0&&(dir[i][1]==1||dir[i][1]==-1))
               {
                   if(check(Y+dir[i][1],X))
                   continue;
                   Y+=dir[i][1];
                   used[Y][X]=1;
                   next.x=X;next.y=Y;next.time=pre.time+1;
                   q.push(next);
               }
               if(pre.time%2==1&&(dir[i][0]==1||dir[i][0]==-1))
               {
                   if(check(Y,X+dir[i][0]))
                    continue;
                    X+=dir[i][0];used[Y][X]=1;
                    next.x=X;next.y=Y;next.time=pre.time+1;
                    q.push(next);
               }
           }
           else if(mapp[Y][X]=='-')
           {
               if(pre.time%2==0&&(dir[i][0]==1||dir[i][0]==-1))
               {
                   X+=dir[i][0];
                   if(check(Y,X))
                   continue;
                   used[Y][X]=1;
                  next.x=X;next.y=Y;next.time=pre.time+1;
                   q.push(next);
               }
               else if(pre.time%2==1&&(dir[i][1]==1||dir[i][1]==-1))
               {
                   Y+=dir[i][1];
                   if(check(Y,X))continue;used[Y][X]=1;
                   next.x=X;next.y=Y;next.time=pre.time+1;
                   q.push(next);
               }
           }
        }
    }
    return -1;
}
int main()
{
    while(scanf("%d%d",&m,&n)!=EOF)
    {
        int i,j;
        memset(used,0,sizeof(used));
        memset(used2,0,sizeof(used2));
        for(i=1;i<=m;i++)
        for(j=1;j<=n;j++)
        {
            cin>>mapp[i][j];
            if(mapp[i][j]=='T')
            {
                y2=i;x2=j;
                mapp[i][j]='.';
            }
            if(mapp[i][j]=='S')
            {
                mapp[i][j]='.';
                y1=i;x1=j;
            }
        }
        ans=bfs();
        printf("%d\n",ans);
    }
    return 0;
}
