#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cmath>
#include <string>
#include <set>
using namespace std;
typedef long long ll;
const int MAXN = 55;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
struct Mat  {
    int m[MAXN][MAXN];
    Mat () {
        memset (m, 0, sizeof (m));
    }
    void init(void) {
        for (int i=0; i<MAXN; ++i)  m[i][i] = 1;
    }
};
int n, m;
int a[MAXN];
int dp[MAXN][MAXN];
bool judge(int x, int y)    {
    char p[15], q[15];
    sprintf (p, "%d", x);
    sprintf (q, "%d", y);
    int lenp =  strlen (p), lenq = strlen (q);
    for (int i=0; i<lenp; ++i)  {
        int k = 0;
        while (i + k < lenp && k < lenq && p[i+k] == q[k])  k++;
        if (i + k == lenp && k >= 2)    return true;
    }
    return false;
}
Mat operator * (Mat &a, Mat &b) {
    Mat ret;
    for (int k=1; k<=n; ++k)    {
        for (int i=1; i<=n; ++i)    {
            for (int j=1; j<=n; ++j)    {
                ret.m[i][j] = (ret.m[i][j] + 1LL * a.m[i][k] * b.m[k][j] % MOD) % MOD;
            }
        }
    }
    return ret;
}
Mat operator ^ (Mat x, int n)   {
    Mat ret;    ret.init ();
    while (n)   {
        if (n & 1)  ret = ret * x;
        x = x * x;
        n >>= 1;
    }
    return ret;
}
Mat work(void)  {
    Mat ret;
    for (int i=1; i<=n; ++i)    {
        for (int j=1; j<=n; ++j)    {
            if (judge (a[i], a[j]))   ret.m[i][j] = 1;
        }
    }
    return ret;
}
void brute_force(void)  {
    memset (dp, 0, sizeof (dp));
    for (int i=1; i<=n; ++i)    dp[1][i] = 1;
    for (int i=2; i<=m; ++i)    {
        for (int j=1; j<=n; ++j)    {
            for (int k=1; k<=n; ++k)    if (judge (a[j], a[k])) {
                dp[i][k] += dp[i-1][j];
                dp[i][k] %= MOD;
            }
        } 
    }
    int res = 0;
    for (int i=1; i<=n; ++i)    {
        res += dp[m][i];    res %= MOD;
    }
    printf ("%d\n", res);
}
int main(void)  {       
    int T;  scanf ("%d", &T);
    while (T--) {
        scanf ("%d%d", &n, &m);
        for (int i=1; i<=n; ++i)    {
            scanf ("%d", &a[i]);
        }
        sort (a+1, a+1+n);  n = unique (a+1, a+1+n) - (a + 1);       
        Mat x = work ();
        Mat res = x ^ (m - 1);  int ans = 0;
        for (int i=1; i<=n; ++i)    {
            for (int j=1; j<=n; ++j)    {
                ans = (ans + res.m[i][j]) % MOD;
            }
        }
        printf ("%d\n", ans);
    }
    return 0;
}
