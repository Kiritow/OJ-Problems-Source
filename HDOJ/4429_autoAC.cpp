#include<stdio.h>
#include<math.h>
#include<string.h>
#include<algorithm>
#define maxn 2220
using namespace std;
struct node{
    int xl,yl;
    int xr,yr;
    int num;
    int deep;
    int flag;
    int l;
    int r;
    int fat;
    void output()
    {
        printf("%d %d %d %d\n",xl,yl,xr,yr);
        printf("l = %d r = %d %d\n",l,r,fat);
    }
    bool inside(int x,int y)
    {
        return (xl<x && x<xr && yl<y&&y<yr);
    }
    bool in(int x,int y)
    {
        return (xl<=x && x<=xr && yl<=y&&y<=yr);
    }
}seq[maxn];
int tot;
int total;
void build(int xl,int yl,int xr,int yr,int root,int fat)
{
    seq[root].xl = xl;
    seq[root].yl = yl;
    seq[root].xr = xr;
    seq[root].yr = yr;
    seq[root].deep = 0;
    seq[root].l = 0;
    seq[root].r = 0;
    seq[root].flag = 0;
    seq[root].fat = fat;
    seq[root].num = 0;
    return ;
}
int n,m;
int get(int xl,int yl,int xr,int yr)
{
    for (int i=tot;i>=1;i--)
        if (seq[i].flag == 0 && seq[i].in(xl,yl) && seq[i].in(xr,yr))
            return i;
    return 0;
}
void update(int xl,int yl,int xr,int yr)
{
    int root = get(xl,yl,xr,yr);
    int xxl = seq[root].xl;
    int yyl = seq[root].yl;
    int xxr = seq[root].xr;
    int yyr = seq[root].yr;
    seq[root].flag = 1;
    if (xl == xxl){
        build(xxl,yyl,xr,yr,++tot,root);
        seq[root].l = tot;
        build(xl,yl,xxr,yyr,++tot,root);
        seq[root].r = tot;
    }else{
        build(xxl,yyl,xr,yr,++tot,root);
        seq[root].l = tot;
        build(xl,yl,xxr,yyr,++tot,root);
        seq[root].r = tot;
    }
    return ;
}
int find(int x,int y)
{
    for (int i=tot;i>=1;i--)
        if (seq[i].flag==0 && seq[i].inside(x,y))
            return i;
    return 0;
}
bool fff[maxn][maxn];
void dfs(int root,int niuniu)
{
    fff[niuniu][root] = true;
    if (seq[root].l > 0)
        dfs(seq[root].l,niuniu);
    if (seq[root].r > 0)
        dfs(seq[root].r,niuniu);
    return ;
}
void dfs1(int root,int deep)
{
    int l = seq[root].l;
    int r = seq[root].r;
    seq[root].deep = deep;
    if (l > 0){
        dfs1(l,deep+1);
        seq[root].num += seq[l].num;
    }
    if (r > 0){
        dfs1(r,deep+1);
        seq[root].num += seq[r].num;
    }
    return ;
}
void init()
{
    total = 0;
    for (int i=1;i<=tot;i++)
        if (seq[i].flag==0){
            seq[i].num = 1;
            total++;
        }
    memset(fff,0,sizeof(fff));
    dfs1(1,1);
    for (int i=1;i<=tot;i++)
        dfs(i,i);
    return ;
}
int solve(int u,int v)
{
    for (int i=tot;i>=1;i--)
    {
        if (fff[i][u] && fff[i][v]){
            int res = total - seq[i].num + 1;
            return res;
        }
    }
    return 0;
}
int main()
{
    int xl,yl,xr,yr;
    while (scanf("%d%d%d%d",&xl,&yl,&xr,&yr)==4)
    {
        tot = 0;
        build(xl,yl,xr,yr,++tot,0);
        scanf("%d%d",&n,&m);
        for (int i=1;i<=n;i++)
        {
            scanf("%d%d%d%d",&xl,&yl,&xr,&yr);
            if (xl == xr)
            {
                if (yl > yr)
                {
                    swap(yl,yr);
                }
            }
            if (yl==yr)
            {
                if (xl > xr)
                {
                    swap(xl,xr);
                }
            }
            update(xl,yl,xr,yr);
        }
        init();
        for (int i=1;i<=m;i++)
        {
            scanf("%d%d%d%d",&xl,&yl,&xr,&yr);
            int p1 = find(xl,yl);
            int p2 = find(xr,yr);
            int ans = solve(p1,p2);
            printf("%d\n",ans);
        }
    }
    return 0;
}
