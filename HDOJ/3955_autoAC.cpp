# include<stdio.h>
# include<string.h>
# include<stdlib.h>
# include<queue>
# define N 105 
using namespace std; 
int n,m,MP; 
bool map[N][N][10]; 
bool visit[N][N]; 
int x0,y0,endx,endy; 
int dir1[6][2]={-1,1, 0,1, 1,1, 1,0, 0,-1, -1,0};
int dir2[6][2]={-1,0, 0,1, 1,0, 1,-1, 0,-1, -1,-1};
struct node{
    int x,y;
    int sum;
    bool operator<(const node &b) const
    {
        return b.sum <  sum; 
    } 
};
int MIN(int a,int b)
{
    return a<b?a:b;
}
bool is(int xx,int yy)
{
    if(xx<0 || xx>=n || yy<0 || yy>=m) return 0;
    return 1; 
} 
bool is1(int xx,int yy)
{
    int i,x1,y1; 
    if(xx%2==1)
    {
        for(i=0;i<6;i++)
        {
            x1=xx+dir1[i][0];
            y1=yy+dir1[i][1];
            if(is(x1,y1) && map[x1][y1][3]) return 1; 
        } 
        return 0; 
    } 
    else
    {
        for(i=0;i<6;i++)
        {
            x1=xx+dir2[i][0];
            y1=yy+dir2[i][1];
            if(is(x1,y1) && map[x1][y1][3]) return 1; 
        } 
        return 0;
    } 
} 
int bfs()
{
    priority_queue<node>q;
    node cur,next;
    int i,cost,remain;
    cur.x=x0;
    cur.y=y0;
    cur.sum=0;
    while(!q.empty()) q.pop(); 
    q.push(cur); 
    while(!q.empty())
    {
        cur=q.top();
        q.pop();
        remain=MP-cur.sum%MP;
        if(cur.x==endx && cur.y==endy) 
        {
            if(remain==MP) return cur.sum/MP;
            else return cur.sum/MP+1; 
        } 
        if(visit[cur.x][cur.y]) continue;
        visit[cur.x][cur.y]=1; 
        for(i=0;i<6;i++)
        {
            if(cur.x%2==1)
            {
                next.x=cur.x+dir1[i][0];
                next.y=cur.y+dir1[i][1]; 
            } 
            else
            {
                next.x=cur.x+dir2[i][0];
                next.y=cur.y+dir2[i][1]; 
            } 
            if(!(is(next.x,next.y)) || map[next.x][next.y][3]) continue;
            if(is1(cur.x,cur.y) && is1(next.x,next.y)) 
            {
                next.sum=cur.sum+remain;
                q.push(next);
            }
            else if(map[cur.x][cur.y][2] && map[next.x][next.y][2])
            {
                next.sum=cur.sum+1;
                q.push(next);
            }
            else if(map[cur.x][cur.y][i+4])
            {
                next.sum=cur.sum+remain;
                q.push(next);
            }
            else 
            {
                if(map[next.x][next.y][0]) cost=1;
                else cost=2;
                cost *=4;
                next.sum=cur.sum+MIN(cost,remain);
                q.push(next);
            }
        } 
    } 
    return -1;
} 
int main()
{
    int i,j,ncase,t,k;
    int a[10],ans;
    a[0]=1;
    for(i=1;i<10;i++)
    a[i]=a[i-1]*2; 
    scanf("%d",&ncase);
    for(t=1;t<=ncase;t++)
    {
        scanf("%d%d%d",&n,&m,&MP);
        MP*=4;
        memset(map,0,sizeof(map)); 
        for(i=0;i<n;i++)
        for(j=0;j<m;j++)
        { 
            scanf("%d",&ans); 
            for(k=9;k>=0;k--)
            if(ans>=a[k])
            {
                map[i][j][k]=1;
                ans-=a[k]; 
            }  
        } 
        scanf("%d%d%d%d",&x0,&y0,&endx,&endy); 
        memset(visit,0,sizeof(visit)); 
        printf("Case %d: %d\n",t,bfs()); 
    } 
    return 0; 
}
