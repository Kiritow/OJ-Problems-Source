#include<iostream>
#include<algorithm>
#include<cstring>
#include<string>
#include<stdio.h>
#include<math.h>
#define N 20000
#define inf 0x7ffffff
#define eps 1e-9
#define pi acos(-1.0)
using namespace std;
struct node
{
    int x,y,flag;
}s[2*N+5];
bool cmp(node a,node b)
{
    if(a.x != b.x)  return a.x < b.x;
    return  a.flag > b.flag;
}
struct tree
{
    int l,r,flag,maxx;
}tree[4*2*N];
void build(int o,int l,int r)
{
    tree[o].l = l;
    tree[o].r = r;
    tree[o].maxx = tree[o].flag = 0;
    if(l == r)  return ;
    int m = (l+r)/2;
    build(2*o,l,m);
    build(2*o+1,m+1,r);
}
void pushup(int o)
{
    tree[o].maxx = max(tree[2*o].maxx, tree[2*o+1].maxx );
}
void pushdown(int o)
{
    if(tree[o].flag != 0)
    {
        tree[2*o].flag += tree[o].flag;
        tree[2*o+1].flag += tree[o].flag;
        tree[2*o].maxx += tree[o].flag;
        tree[2*o+1].maxx += tree[o].flag;
        tree[o].flag = 0;
    }
}
void update(int o,int x,int y,int v)
{
    if(x <= tree[o].l && tree[o].r <= y)
    {
        tree[o].flag += v;
        tree[o].maxx += v;
        return;
    }
    pushdown(o);
    int m = (tree[o].l + tree[o].r)/2;
    if(x <= m)  update(2*o,x,y,v);
    if(y > m)   update(2*o+1,x,y,v);
    pushup(o);
}
int main()
{
    int n,w,h;
    while(scanf("%d",&n))
    {
        if(n < 0)  break;
        scanf("%d%d",&w,&h);
        int i;
        for(i = 0; i < n; i++)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            x += N;
            y += N;
            s[2*i].x = x;
            s[2*i].y = y;
            s[2*i].flag = 1;
            s[2*i+1].x = x+w;
            s[2*i+1].y = y;
            s[2*i+1].flag = -1;
        }
        sort(s,s+2*n,cmp);
        build(1,1,2*N+1);
        int ans = 0;
        for(i = 0; i < 2*n; i++)
        {
            update(1,s[i].y, s[i].y+h ,s[i].flag);
            ans = max(ans,tree[1].maxx);
        }
        printf("%d\n",ans);
    }
    return 0;
}
