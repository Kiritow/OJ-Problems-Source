#include<iostream>
#include<algorithm>
#include<queue>
#include<bitset>
#define N 8
using namespace std;
bitset<20000010> vis1,vis2;
int dir[4][2]={{0,1},{0,-1},{1,0},{-1,0}};  
bool map[N][N],flag;
struct point 
{
    int x,y;
};
struct node
{
    point p[4];
};
node start,end1;
queue<node> Q1,Q2;
bool cmp(point a,point b)
{
    if(a.x!=b.x)
        return a.x<b.x;
    return a.y<b.y;
}
void get_map(point p[])
{
    memset(map,0,sizeof(map));
    for(int i=0;i<4;i++)
        map[p[i].x][p[i].y]=1;
}
int get_hash(point p[])
{
    sort(p,p+4,cmp);
    int a=0,j=7;
    for(int i=0;i<4;i++)
    {
        a|=(p[i].x<<(j*3));
        a|=(p[i].y<<(j-1)*3);
        j-=2;
    }
    return a;
}
void BFS1()
{
    int a;
    int size=Q1.size();
    while(size--)
    {
            node q=Q1.front(),temp;
            Q1.pop();
            get_map(q.p);
            for(int i=0;i<4;i++)
                for(int k=0;k<4;k++)
                {
                    temp=q;
                    int x=q.p[i].x+dir[k][0];
                    int y=q.p[i].y+dir[k][1];
                    if(x<0 ||x>=N || y<0 || y>=N)
                        continue;
                    temp.p[i].x=x;
                    temp.p[i].y=y;   
                    if(map[x][y])
                    {
                        int x1=x+dir[k][0];
                        int y1=y+dir[k][1];
                        if(x1<0 || x1>=N || y1<0 || y1>=N || map[x1][y1])
                            continue;
                        temp.p[i].x=x1;temp.p[i].y=y1;
                    }
                    a=get_hash(temp.p);
                    if(vis1[a]) continue;
                    if(vis2[a]) {
                        flag=true;
                        return ;
                    }
                    vis1[a]=true;
                    Q1.push(temp);
                }
        }
}
void BFS2()
{
    int a;
    int size=Q2.size();
    while(size--)
    {
            node q=Q2.front(),temp;
            Q2.pop();
            get_map(q.p);
            for(int i=0;i<4;i++)
                for(int k=0;k<4;k++)
                {
                    temp=q;
                    int x=temp.p[i].x+dir[k][0];
                    int y=temp.p[i].y+dir[k][1];
                    if(x<0 ||x>=N || y<0 || y>=N)
                        continue;
                    temp.p[i].x=x;
                    temp.p[i].y=y;
                    if(map[x][y])
                    {
                        int x1=x+dir[k][0];
                        int y1=y+dir[k][1];
                        if(x1<0 || x1>=N || y1<0 || y1>=N || map[x1][y1])
                            continue;
                        temp.p[i].x=x1;temp.p[i].y=y1;
                    }
                    a=get_hash(temp.p);
                    if(vis2[a]) continue;
                    if(vis1[a]) {
                        flag=true; return ;
                    }
                    vis2[a]=true;
                    Q2.push(temp);
                }
    }
}
int main()
{
    while(scanf("%d %d",&start.p[0].x,&start.p[0].y)==2)
    {
        start.p[0].x--;
        start.p[0].y--;
        for(int i=1;i<4;i++)
        {
            scanf("%d %d",&start.p[i].x,&start.p[i].y);
            start.p[i].x--;start.p[i].y--;
        }
        for(int i=0;i<4;i++)
        {
            scanf("%d %d",&end1.p[i].x,&end1.p[i].y);
            end1.p[i].x--;
            end1.p[i].y--;
        }
        while(!Q1.empty())
            Q1.pop();
        while(!Q2.empty())
            Q2.pop();
        vis1.reset();
        vis2.reset();
        int a;
        a=get_hash(start.p);
        vis1[a]=true;
        int b=get_hash(end1.p);
        if(a==b) {
            printf("YES\n");
                continue;
        }
        vis2[b]=true;
        Q1.push(start);Q2.push(end1);
        int step=8;
        flag=false;
        while(step--)
        {
            if(Q1.size()<=Q2.size())
                BFS1();
            else BFS2();
            if(flag) break;
        }
        if(flag) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
