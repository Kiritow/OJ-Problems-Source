#include<stdio.h>
#include<string.h>
#include<queue>
using namespace std;
int n;
int s_x,s_y;
int map[111][111];
int flag[111][111];
int dir[8][2]={1,0, -1,0, 0,1, 0,-1, -1,-1, -1,1, 1,-1, 1,1};
struct node
{
    int x,y;
};
int judge(int x,int y)
{
    int tot=0;
    int i;
    int t_x,t_y;
    for(i=0;i<8;i++)
    {
        t_x=x+dir[i][0];
        t_y=y+dir[i][1];
        if(t_x<0 || t_x>=n || t_y<0 || t_y>=n)    continue;
        if(map[t_x][t_y]==-2)    tot++;
    }
    return tot;
}
void BFS()
{
    queue<node>q;
    node cur,next;
    int i;
    int temp;
    cur.x=s_x;
    cur.y=s_y;
    flag[cur.x][cur.y]=1;
    q.push(cur);
    while(!q.empty())
    {
        cur=q.front();
        q.pop();
        temp=judge(cur.x,cur.y);
        map[cur.x][cur.y]=temp;
        if(temp)    continue;
        for(i=0;i<8;i++)
        {
            next.x=cur.x+dir[i][0];
            next.y=cur.y+dir[i][1];
            if(next.x<0 || next.x>=n || next.y<0 || next.y>=n)    continue;
            if(!flag[next.x][next.y])
            {
                q.push(next);
                flag[next.x][next.y]=1;
            }
        }
    }
}
int main()
{
    int i,l;
    char str[111];
    while(scanf("%d",&n)!=-1)
    {
        for(i=0;i<n;i++)
        {
            scanf("%s",str);
            for(l=0;l<n;l++)
            {
                if(str[l]=='O')        map[i][l]=-1;
                else if(str[l]=='X')map[i][l]=-2;
            }
        }
        scanf("%d%d",&s_x,&s_y);
        if(map[s_x][s_y]==-2)    {printf("it is a beiju!\n\n");continue;}
        memset(flag,0,sizeof(flag));
        BFS();
        for(i=0;i<n;i++)
        {
            for(l=0;l<n;l++)
            {
                if(map[i][l]<0)    printf(".");
                else            printf("%d",map[i][l]);
            }
            printf("\n");
        }
        printf("\n");
    }
    return 0;
}
