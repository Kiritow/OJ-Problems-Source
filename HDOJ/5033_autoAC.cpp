#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
#include<cmath>
#include<cctype>
#include<string>
#include<algorithm>
#include<iostream>
#include<ctime>
#include<map>
#include<set>
using namespace std;
#define MP(x,y) make_pair((x),(y))
#define PB(x) push_back(x)
typedef __int64 LL;
const int INF = 1000111222;
const double INFF = 1e100;
const double eps = 1e-8;
const int mod = 1000000007;
const int NN = 100010;
const int MM = 400010;
struct node
{
    double h;
    double x;
    bool operator<(const node &tt)const
    {
        return x < tt.x;
    }
}a[NN];
struct Q
{
    int l,r,id;
    double x;
    bool operator<(const Q &tt)const
    {
        return x < tt.x;
    }
}line[NN];
int q[NN];
double ans[NN];
const double pi = acos(-1.0);
int main()
{
    int cas, ee = 0;
    int i, n, m, j, j1, j2, tail;
    double t, t1, t2;
    scanf("%d", &cas);
    while (cas--)
    {
        scanf("%d",&n);
        for (i = 1; i <= n; i ++)
        {
            scanf("%lf%lf", &a[i].x, &a[i].h);
        }
        sort(a+1, a+1+n);
        scanf("%d", &m);
        for (i = 1; i <= m; i ++)
        {
            scanf("%lf", &line[i].x);
            line[i].id = i;
        }
        sort(line+1, line+1+m);
        q[tail = 1] = 1;
        j = 2;
        for (i = 1; i <= m; i ++)
        {
            while (j <= n && a[j].x < line[i].x)
            {
                while (tail > 0 && a[j].h >= a[ q[tail] ].h)
                    tail--;
                while (tail > 1)
                {
                    j2 = q[tail-1];
                    j1 = q[tail];
                    if( (a[j1].h - a[j].h) * (a[j1].x - a[j2].x) <=
                       (a[j2].h-a[j1].h) * (a[j].x - a[j1].x) )
                        tail--;
                    else
                        break;
                }
                q[++tail] = j;
                j++;
            }
            while (tail > 1)
            {
                j1 = q[tail-1];
                j2 = q[tail];
                if(a[j1].h/(line[i].x - a[j1].x) >=
                   a[j2].h/(line[i].x - a[j2].x))
                    tail--;
                else
                    break;
            }
            line[i].l = q[tail];
        }
        q[tail = 1] = n;
        j = n-1;
        for (i = m; i >= 1; i --)
        {
            while (j >= 1 && a[j].x > line[i].x)
            {
                while (tail > 0 && a[j].h >= a[ q[tail] ].h)
                    tail--;
                while (tail > 1)
                {
                    j1 = q[tail];
                    j2 = q[tail-1];
                    if( (a[j1].h - a[j].h) * (a[j2].x - a[j1].x) <=
                       (a[j2].h-a[j1].h) * (a[j1].x - a[j].x) )
                        tail--;
                    else
                        break;
                }
                q[++tail] = j;
                j--;
            }
            while (tail > 1)
            {
                j1 = q[tail-1];
                j2 = q[tail];
                if(a[j1].h/(a[j1].x - line[i].x) >=
                   a[j2].h/(a[j2].x - line[i].x))
                    tail--;
                else
                    break;
            }
            line[i].r = q[tail];
        }
        for (i = 1; i <= m; i ++)
        {
            t1 = a[ line[i].l ].h/( line[i].x - a[ line[i].l ].x + 0.0 );
            t2 = a[ line[i].r ].h/( line[i].x - a[ line[i].r ].x + 0.0 );
            t2 = -t2;
            t = pi - atan(t1) - atan(t2);
            ans[ line[i].id ] = t*180.0/pi;
        }
        printf("Case #%d:\n", ++ee);
        for (i = 1; i <= m; i ++)
        {
            printf("%.10lf\n", ans[i]);
        }
    }
    return 0;
}
