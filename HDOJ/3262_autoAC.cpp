#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=33;
struct rec
{
    int x,y,d;
}ans[MAXN*2];
struct node
{
    int h,m,dat,num;
}a[MAXN*2];
int n,m,k;
int map[MAXN][MAXN];
bool b[MAXN][MAXN];
bool cmp(node a,node b)
{
    if (a.h<b.h || (a.h==b.h && a.m<b.m)) return 1; else return 0;
}
bool Init()
{
    scanf("%d%d%d",&n,&m,&k);
    if (!n && !m && !k) return 0;
    for (int i=1;i<=n;++i)
        for (int j=1;j<=m;++j)
            scanf("%d",&map[i][j]);
    for (int i=1;i<=k;++i)
        scanf("%d:%d %d",&a[i].h,&a[i].m,&a[i].dat),a[i].num=i;
    sort(a+1,a+k+1,cmp);
    return 1;
}
bool Cleck(int x,int y,int z)
{
    for (int i=y;i<=y+z-1;++i)
        if (b[x][i]) return 0;
    return 1;
}
bool GF(int h)
{
    rec Max;
    Max.x=Max.y=Max.d=0;
    for (int i=1;i<=n;++i)
        for (int j=1;j<=m-a[h].dat+1;++j)
            if (Cleck(i,j,a[h].dat))
                if (map[i][j]>Max.d) 
                    Max.x=i,Max.y=j,Max.d=map[i][j];
    if (Max.x && Max.y) 
    {
        ans[a[h].num]=Max;
        for (int i=Max.y;i<=Max.y+a[h].dat-1;++i) b[Max.x][i]=1;
        return 1;
    }
    return 0;
}
bool GM(int h)
{
    rec Max;
    Max.x=Max.y=Max.d=0;
    for (int i=1;i<=n;++i)
        for (int j=1;j<=m;++j)
            if (!b[i][j] && Max.d<map[i][j]) Max.x=i,Max.y=j,Max.d=map[i][j];
    if (Max.x && Max.y) 
    {
        ans[a[h].num]=Max,b[Max.x][Max.y]=1;
        return 1;
    }
    return 0;
}
void Solve()
{
    memset(ans,0,sizeof(ans));
    memset(b,0,sizeof(b));
    for (int i=1;i<=k;++i)
    {
        if (GF(i)) continue;
        if (GM(i)) continue;
        ans[a[i].num].d=-1;
    }
    for (int i=1;i<=k;++i)
        if (ans[i].d!=-1) printf("%d %d\n",ans[i].x,ans[i].y); else printf("-1\n");
}
int main()
{
    while (Init()) Solve();
    return 0;
}
