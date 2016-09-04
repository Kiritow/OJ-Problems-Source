#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <climits>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <list>
#include <queue>
#include <stack>
#include <deque>
#include <algorithm>
using namespace std;
typedef long long ll;
const int maxa = 20;
const int maxc = 40;
const int maxn = 60;
double dp[2][maxn][3][maxa][maxc];
double b[2][3], d[2][3];
inline double P(int i, int j, int n)
{
    return max(0.0, min(1.0, b[i][j] - n * d[i][j]));
}
double f(int id, int n, int m, int a, int c)
{
    double &ret = dp[id][n][m][a][c];
    if (ret >= 0) return ret;
    if (a == 0 && c == 0) return ret = 0;
    int n0 = n, a0 = a;
    if (m == 0) n++;
    if (m == 2) a++;
    m = (m + 1) % 3;
    ret = 0;
    if (a0 > 0)
    {
        ret = max(ret, P(id, 0, n0) * (1.0 - f(1-id, n, m, a-1, c)));
        ret = max(ret, P(id, 1, n0) * (1.0 - f(1-id, n, m, a-1, c+1)));
    }
    if (c > 0)
    {
        ret = max(ret, P(id, 2, n0) * (1.0 - f(1-id, n, m, a, c-1)));
    }
    return ret;
}
int main()
{
    int T, n;
    scanf("%d", &T);
    while (T--)
    {
        for (int i=0;i<2;i++)
            for (int n=0;n<maxn;n++)
                for (int m=0;m<3;m++)
                    for (int a=0;a<maxa;a++)
                        for (int c=0;c<maxc;c++)
                            dp[i][n][m][a][c] = -1;
        scanf("%d", &n);
        for (int i=0;i<2;i++)
            for (int j=0;j<3;j++)
                scanf("%lf%lf", &b[i][j], &d[i][j]);
        printf("%.4lf\n", f(0, n, 0, n-1, 0));
    }
    return 0;
}
