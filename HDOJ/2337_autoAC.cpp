#include <iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;
const int N = 1001;
const int M = 1000004;
const int NM = 10001;
struct node
{
    int x,y,step;
}que[M],ss,now;
int n,m,nm,sx,sy,ex,ey,maxans,minans,minlen;
int pt[NM][2];
bool flag[N][N];
int dist[N][N];
int dir[4][2] = {{-1,0},{0,-1},{0,1},{1,0}};
int dis(int a,int b,int c,int d)
{
    return (abs(a - c) + abs(b - d));
}
void Bfs(int id)
{
    ss.x = pt[id][0];
    ss.y = pt[id][1];
    ss.step = 0;
    int i,head,tail;
    head = tail = 0;
    que[tail ++] = ss;
    memset(flag,false,sizeof(flag));
    flag[ss.x][ss.y] = true;
    while(head != tail)
    {
        now = que[head ++];
        if(head == M)
            head = 0;
        if(now.step > maxans)
            return;
        dist[now.x][now.y] = min(dist[now.x][now.y],now.step);
        ss = now;
        ss.step ++;
        for(i = 0;i < 4;i ++)
        {
            ss.x = now.x + dir[i][0];
            ss.y = now.y + dir[i][1];
            if(ss.x >= 0 && ss.y >= 0 && ss.x < n && ss.y < m && !flag[ss.x][ss.y])
            {
                flag[ss.x][ss.y] = true;
                que[tail ++] = ss;
                if(tail == M)
                    tail = 0;
            }
        }
    }
}
void init()
{
    scanf("%d%d%d",&nm,&n,&m);
    scanf("%d%d%d%d",&sx,&sy,&ex,&ey);
    maxans = 0x3f3f3f3f;
    memset(dist,0x3f,sizeof(dist));
    for(int i = 0;i < nm;i ++)
        scanf("%d%d",&pt[i][0],&pt[i][1]),maxans = min(maxans,dis(sx,sy,pt[i][0],pt[i][1]));
    for(int i = 0;i < nm;i ++)
        Bfs(i);
}
bool isok(int x,int y,int cmp)
{
    if(x < 0 || y < 0 || x >= n || y >= m)
        return false;
    else
    {
        return dist[x][y] >= cmp; 
    }
}
bool bfs(int lim)
{
    ss.x = sx;
    ss.y = sy;
    ss.step = 0;
    memset(flag,false,sizeof(flag));
    flag[sx][sy] = true;
    int head,tail,i;
    head = tail = 0;
    que[tail ++] = ss;
    while(head != tail)
    {
        now = que[head ++];
        if(head == M)
            head = 0;
        ss = now;
        ss.step ++;
        for(i = 0;i < 4;i ++)
        {
            ss.x = now.x + dir[i][0];
            ss.y = now.y + dir[i][1];
            if(isok(ss.x,ss.y,lim) && !flag[ss.x][ss.y])
            {
                if(ss.x == ex && ss.y == ey)
                {
                    minlen = ss.step;
                    return true;
                }
                flag[ss.x][ss.y] = true;
                que[tail ++] = ss;
                if(tail == M)
                    tail = 0;
            }
        }
    }
    return false;
}
void fun()
{
    init();
    int l,r,mid;
    l = 0;r = maxans;
    minans = maxans;minlen = dis(ex,ey,sx,sy);
    while(l <= r)
    {
        mid = (l + r)>>1;
        if(bfs(mid))
        {
            minans = mid;
            l = mid + 1;
        }
        else
            r = mid - 1;
    }
    printf("%d %d\n",minans,minlen);
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t --)
    {
        fun();
    }
    return 0;
}
