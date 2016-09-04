#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <functional>
#include <vector>
#include <map>
#include <cstring>
#include <string>
#include <list>
#include <set>
#include <bitset>
#include <cctype>
#include <cmath>
#include <ctime>
#include <numeric>
#include <utility>
#include <stack>
#include <queue>
#include <deque>
#include <iomanip>
#include <cassert>
#define pb push_back
#define mp make_pair
#define Maxn 1100
#define fi first
#define se second
using namespace std;
typedef pair<double, double> pii;
const double eps=1e-8;
const double inf=1e300;
int n;
double dp[Maxn][2];
pii seg[Maxn][2];
inline double getdis(pii a, pii b)
{
    return sqrt((a.fi-b.fi)*(a.fi-b.fi)+(a.se-b.se)*(a.se-b.se));
}
inline int sign(double x)
{
    return x<-eps?-1:x>eps;
}
pii intersert(pii A, pii B, double y)
{
    double dx = A.fi - B.fi;
    double dy = A.se - B.se;
    return mp(A.fi + (y-A.se)*dx/dy, y);
}
bool leftturn(pii p, pii a, pii b)
{
    double x1 = (a.fi-p.fi), y1 = (a.se-p.se);
    double x2 = (b.fi - p.fi), y2 = (b.se-p.se);
    return sign(x1*y2-x2*y1)>0;
}
bool noRightTurn(pii p, pii a, pii b)
{
    double x1 = (a.fi-p.fi), y1 = (a.se-p.se);
    double x2 = (b.fi - p.fi), y2 = (b.se-p.se);
    return sign(x1*y2 - x2*y1)>=0;
}
int main()
{
    double a, b, c;
    while (~scanf("%d", &n), n)
    {
        scanf("%lf%lf", &a, &b);
        seg[0][0] = mp(a, b);
        for (int i=1; i<=n; i++)
        {
            scanf("%lf%lf%lf", &c, &a, &b);
            seg[i][0] = mp(a, c);
            seg[i][1] = mp(b, c);
        }
        dp[n][0] = dp[n][1] = 0;
        int j;
        for (int i=n-1; i>=0; i--)
        {
            for (int side=0; side<2; side++)
            {
                dp[i][side] = inf;
                pair<pii,pii> next = mp(seg[i+1][0], seg[i+1][1]);
                pii pt = seg[i][side];
                for (j=i+1; j<=n; j++)
                {
                    if (leftturn(pt, seg[j][1], next.fi) || leftturn(pt, next.se, seg[j][0])) break;
                    if (noRightTurn(pt, next.fi, seg[j][0]))
                    {
                        next.fi = seg[j][0];
                        dp[i][side] = min(dp[i][side], getdis(pt, next.fi)+dp[j][0]);
                    }
                    if (noRightTurn(pt, seg[j][1], next.se))
                    {
                        next.se = seg[j][1];
                        dp[i][side] = min(dp[i][side], getdis(pt, next.se)+dp[j][1]);
                    }
                }
                if (j > n)
                {
                    double y = seg[n][0].se;
                    next.fi = intersert(pt, next.fi,y);
                    next.se = intersert(pt, next.se, y);
                    if (pt.fi < next.fi.fi) dp[i][side] = min(dp[i][side], getdis(pt, next.fi));
                    else if (pt.fi > next.se.fi) dp[i][side] = min(dp[i][side], getdis(pt, next.se));
                    else dp[i][side] = min(dp[i][side], pt.se - y);
                }
                if (i == 0) break;
            }
        }
        printf("%.10f\n", dp[0][0]);
    }
    return 0;
}
