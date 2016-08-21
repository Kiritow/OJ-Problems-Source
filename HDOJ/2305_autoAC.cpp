#include <iostream>
#include<algorithm>
using namespace std;
#define maxn 50010
int n, m;
struct point
{
    int year, r;
}pt[maxn];
struct Tree
{
    int Max;
    int l, r;
}T[maxn*4];
int MMax(int a, int b)
{
    return a > b ? a : b;
}
void Build(int p, int l, int r)
{
    T[p].l = l;
    T[p].r = r;
    if(l == r)
    {
        T[p].Max = pt[l].r;
        return ;
    }
    int mid = (l + r) >> 1;
    Build(p<<1, l, mid);
    Build(p<<1|1, mid+1, r);
    T[p].Max = max(T[p<<1].Max, T[p<<1|1].Max);
}
int Query(int p, int l, int r)
{
    if(r < T[p].l || l > T[p].r)
        return 0;
    if(l <= T[p].l && T[p].r <= r)
        return T[p].Max;
    return max(Query(p<<1, l, r), Query(p<<1|1, l, r));
}
int Binary(int val, int l, int r)
{
    int ans = 0;
    while(l <= r) {
        int m = (l + r) >> 1;
        if(pt[m].year <= val)
        {
            l = m + 1;
            ans = m;
        }else
            r = m - 1;
    }
    return ans;
}
int Coces[maxn];
int main()
{
    int i;
    int t = 0;
    while(scanf("%d", &n) != EOF)
    {
        if(t++ && n)
        {
            puts("");
        }
        for(i = 1; i <= n; i++)
        {
            scanf("%d %d", &pt[i].year, &pt[i].r);
            if(i == 1)
            {
                Coces[i] = 1;
            }
            else
            {
                if(pt[i].year - pt[i-1].year == 1)
                    Coces[i] = Coces[i-1];
                else
                    Coces[i] = Coces[i-1] + 1;
            }
        }
        if(n)
            Build(1, 1, n);
        scanf("%d", &m);
        int bufM = m;
        while(bufM--)
        {
            int Y, X;
            int ans; 
            scanf("%d %d", &Y, &X);
            int fY = Binary(Y, 1, n);
            int fX = Binary(X, 1, n);
            if(pt[fY].year == Y && pt[fX].year == X)
            {
                int Yr = Query(1, fY, fY);
                int Zr = Query(1, fY+1, fX-1);
                int Xr = Query(1, fX, fX);
                if(Coces[fY] == Coces[fX])
                {
                    if(Yr >= Xr && Zr < Xr)
                    {
                        ans = 0;
                    }
                    else
                        ans = 2;
                }
                else
                {
                    if(Yr >= Xr && Zr < Xr)
                    {
                        ans = 1;
                    }
                    else
                        ans = 2;
                }
            }
            else if(pt[fX].year == X)
            {
                if(Y + 1 == X)
                {
                    ans = 1;
                }else
                {
                    int Zr = Query(1, fY+1, fX-1);
                    int Xr = Query(1, fX, fX);
                    if(Zr < Xr)
                        ans = 1;
                    else
                        ans = 2;
                }
            }
            else if(pt[fY].year == Y)
            {
                int Yr = Query(1, fY, fY);
                int Zr = Query(1, fY+1, fX);
                if(Yr > Zr)
                {
                    ans = 1;
                }else
                    ans = 2;
            }
            else
            {
                ans = 1;
            }
            if(!ans)
                puts("true");
            else if(ans == 1)
                puts("maybe");
            else
                puts("false");
        }
        if(!n && !m)
        {
            break;
        }
    }
    return 0;
}
