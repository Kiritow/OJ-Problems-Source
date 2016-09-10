#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <math.h>
#include <stdlib.h>
#include <time.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const int MAXN = 1010;
struct Nodey
{
    int l,r;
    int Max,Min;
};
int locy[MAXN],locx[MAXN];
struct Nodex
{
    int l,r;
    Nodey sty[MAXN*4];
    void build(int i,int _l,int _r)
    {
        sty[i].l = _l;
        sty[i].r = _r;
        sty[i].Max = -INF;
        sty[i].Min = INF;
        if(_l == _r)
        {
            locy[_l] = i;
            return;
        }
        int mid = (_l + _r)/2;
        build(i<<1,_l,mid);
        build((i<<1)|1,mid+1,_r);
    }
    int queryMin(int i,int _l,int _r)
    {
        if(sty[i].l == _l && sty[i].r == _r)
            return sty[i].Min;
        int mid = (sty[i].l + sty[i].r)/2;
        if(_r <= mid)return queryMin(i<<1,_l,_r);
        else if(_l > mid)return queryMin((i<<1)|1,_l,_r);
        else return min(queryMin(i<<1,_l,mid),queryMin((i<<1)|1,mid+1,_r));
    }
    int queryMax(int i,int _l,int _r)
    {
        if(sty[i].l == _l && sty[i].r == _r)
            return sty[i].Max;
        int mid = (sty[i].l + sty[i].r)/2;
        if(_r <= mid)return queryMax(i<<1,_l,_r);
        else if(_l > mid)return queryMax((i<<1)|1,_l,_r);
        else return max(queryMax(i<<1,_l,mid),queryMax((i<<1)|1,mid+1,_r));
    }
}stx[MAXN*4];
int n;
void build(int i,int l,int r)
{
    stx[i].l = l;
    stx[i].r = r;
    stx[i].build(1,1,n);
    if(l == r)
    {
        locx[l] = i;
        return;
    }
    int mid = (l+r)/2;
    build(i<<1,l,mid);
    build((i<<1)|1,mid+1,r);
}
void Modify(int x,int y,int val)
{
    int tx = locx[x];
    int ty = locy[y];
    stx[tx].sty[ty].Min = stx[tx].sty[ty].Max = val;
    for(int i = tx;i;i >>= 1)
        for(int j = ty;j;j >>= 1)
        {
            if(i == tx && j == ty)continue;
            if(j == ty)
            {
                stx[i].sty[j].Min = min(stx[i<<1].sty[j].Min,stx[(i<<1)|1].sty[j].Min);
                stx[i].sty[j].Max = max(stx[i<<1].sty[j].Max,stx[(i<<1)|1].sty[j].Max);
            }
            else
            {
                stx[i].sty[j].Min = min(stx[i].sty[j<<1].Min,stx[i].sty[(j<<1)|1].Min);
                stx[i].sty[j].Max = max(stx[i].sty[j<<1].Max,stx[i].sty[(j<<1)|1].Max);
            }
        }
}
int queryMin(int i,int x1,int x2,int y1,int y2)
{
    if(stx[i].l == x1 && stx[i].r == x2)
        return stx[i].queryMin(1,y1,y2);
    int mid = (stx[i].l + stx[i].r)/2;
    if(x2 <= mid)return queryMin(i<<1,x1,x2,y1,y2);
    else if(x1 > mid)return queryMin((i<<1)|1,x1,x2,y1,y2);
    else return min(queryMin(i<<1,x1,mid,y1,y2),queryMin((i<<1)|1,mid+1,x2,y1,y2));
}
int queryMax(int i,int x1,int x2,int y1,int y2)
{
    if(stx[i].l == x1 && stx[i].r == x2)
        return stx[i].queryMax(1,y1,y2);
    int mid = (stx[i].l + stx[i].r)/2;
    if(x2 <= mid)return queryMax(i<<1,x1,x2,y1,y2);
    else if(x1 > mid)return queryMax((i<<1)|1,x1,x2,y1,y2);
    else return max(queryMax(i<<1,x1,mid,y1,y2),queryMax((i<<1)|1,mid+1,x2,y1,y2));
}
int main()
{
    int T;
    scanf("%d",&T);
    int iCase = 0;
    while(T--)
    {
        iCase++;
        printf("Case #%d:\n",iCase);
        scanf("%d",&n);
        build(1,1,n);
        for(int i = 1;i <= n;i++)
            for(int j = 1;j <= n;j++)
            {
                int a;
                scanf("%d",&a);
                Modify(i,j,a);
            }
        int q;
        int x,y,L;
        scanf("%d",&q);
        while(q--)
        {
            scanf("%d%d%d",&x,&y,&L);
            int x1 = max(x - L/2,1);
            int x2 = min(x + L/2,n);
            int y1 = max(y - L/2,1);
            int y2 = min(y + L/2,n);
            int Max = queryMax(1,x1,x2,y1,y2);
            int Min = queryMin(1,x1,x2,y1,y2);
            int t = (Max+Min)/2;
            printf("%d\n",t);
            Modify(x,y,t);
        }
    }
    return 0;
}
