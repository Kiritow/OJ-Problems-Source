#include <set>
#include <queue>
#include <stack>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <limits.h>
#include <string.h>
#include <string>
#include <algorithm>
#define MID(x,y) ( ( x + y ) >> 1 )
#define L(x) ( x << 1 )
#define R(x) ( x << 1 | 1 )
#define BUG puts("here!!!")
using namespace std;
const int MAX = 100010;
int X;
struct circle{ int w,x,y,r;};
circle c[MAX];
double yy(int id,int flag)
{
    double d = sqrt(c[id].r*1.0*c[id].r - (X-c[id].x)*1.0*(X-c[id].x));
    if( flag == 1 ) return c[id].y + d;
    return c[id].y - d;
}
struct Sline{
    int flag,id;
    bool operator<(const Sline a)const
    {
        double y1 = yy(id, flag);
        double y2 = yy(a.id, a.flag);
        return y1 > y2 || y1 == y2 && flag > a.flag;        
    }
};
set<Sline> s;
set<Sline>::iterator pre,suc,it;
struct event{ int x,id,flag;};
event l[MAX];
bool cmp(event a,event b)
{
    if( a.x == b.x )
        return c[a.id].y > c[b.id].y;
    return a.x < b.x;
}
void add_line(circle c, int &cnt ,int id)
{
    l[cnt].id = id;
    l[cnt].x = c.x - c.r;
    l[cnt++].flag = 1;
    l[cnt].id = id;
    l[cnt].x = c.x + c.r;
    l[cnt++].flag = -1;
}
void solve(int n)
{
    s.clear();
    Sline node;
    for(int i=0; i<n; i++)
    {
        X = l[i].x;
        if( l[i].flag == 1 )
        {
            node.id = l[i].id; node.flag = 1;
            it = s.insert(node).first;
            suc = pre = it;
            suc++;
            if( it == s.begin() || suc == s.end() )
                c[it->id].w = 1;
            else
            {
                pre--;
                if( pre->id == suc->id )
                    c[it->id].w = c[pre->id].w + 1;
                else
                    c[it->id].w = max( c[pre->id].w, c[suc->id].w);
            }
            node.flag = -1;
            s.insert(node);
        }
        else
        {
            node.id = l[i].id; node.flag = 1;
            s.erase(node);
            node.flag = -1;
            s.erase(node);
        }
    }
}
int main()
{
    int ncases,n;
    int x1,x2,y1,y2,xx,yy,r;
    while( ~scanf("%d",&n) )
    {
        int cnt = 0;
        for(int i=0; i<n; i++)
        {
            scanf("%d%d%d",&c[i].x, &c[i].y, &c[i].r);
            c[i].w = 0;
            add_line(c[i],cnt,i);
        }
        sort(l,l+cnt,cmp);
        solve(cnt);
        int ans = 0;
        for(int i=0; i<n; i++)
            ans = max(ans, c[i].w);
        printf("%d\n",ans);
    }
return 0;
}
