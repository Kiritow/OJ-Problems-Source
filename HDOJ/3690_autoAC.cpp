#include <iostream>
#include <cstdio>
#include <memory.h>
#include <queue>
#include <set>
#include <utility>
#define MAX(a , b) ((a) > (b) ? (a) : (b))
#define sqr(x) ((x) * (x))
#define mp make_pair
typedef long long ll;
using namespace std;
const int maxn = 12;
const int maxm = 400000;
const int kr = 1;
const int prime = 999997;
struct ddd
{
    int x,y;
    int step;
};
struct node
{
    int x,y;
    int next;
}edge[maxm];
int head[prime],vec[maxn][2];
queue <ddd> Q;
int sx,sy,tx,ty,a,b,c,d,n,idx;
void init()
{
    memset(head,-1,sizeof(head));
    idx = 0;
    return;
}
int ha(int x,int y)
{
    return (((x << 15) ^ y) % prime + prime) % prime;
}
bool addedge(int key,int x,int y)
{
    for(int i=head[key];i != -1;i=edge[i].next)
    {
        if(edge[i].x == x && edge[i].y == y) return false;
    }
    edge[idx].x = x;
    edge[idx].y = y;
    edge[idx].next = head[key];
    head[key] = idx++;
    return true;
}
void read()
{
    d = 0;
    scanf("%d %d %d %d",&sx,&sy,&tx,&ty);
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d %d",&vec[i][0],&vec[i][1]);
        d = MAX(d , sqr(vec[i][0]) + sqr(vec[i][1]));
    }
    a = ty - sy;
    b = sx - tx;
    c = sy * tx - sx * ty;
    return;
}
bool IsValid(int x,int y)
{
    if(sqr(x - sx) + sqr(y - sy) <= sqr(kr) * d) return true;
    if(sqr(x - tx) + sqr(y - ty) <= sqr(kr) * d) return true;
    if((tx - sx) * (x - sx) + (ty - sy) * (y - sy) < 0) return false;
    if((sx - tx) * (x - tx) + (sy - ty) * (y - ty) < 0) return false;
    if(sqr(ll(a) * x + b * y + c) <= ll(d) * (sqr(a) + sqr(b))) return true;
    return false;
}
void bfs()
{
    while(!Q.empty()) Q.pop();
    ddd cur,tmp;
    tmp.x = sx;
    tmp.y = sy;
    tmp.step = 0;
    Q.push(tmp);
    addedge(ha(sx , sy) , sx , sy);
    while(!Q.empty())
    {
        cur = Q.front();
        Q.pop();
        if(cur.x == tx && cur.y == ty)
        {
            printf("%d\n",cur.step);
            return;
        }
        for(int i=0;i<n;i++)
        {
            int xx = cur.x + vec[i][0];
            int yy = cur.y + vec[i][1];
            if(IsValid(xx , yy) && addedge(ha(xx , yy) , xx , yy))
            {
                tmp.x = xx;
                tmp.y = yy;
                tmp.step = cur.step + 1;
                Q.push(tmp);
            }
        }
    }
    puts("IMPOSSIBLE");
    return;
}
int main()
{
    int cas;
    scanf("%d",&cas);
    while(cas--)
    {
        init();
        read();
        bfs();
    }
    return 0;
}
