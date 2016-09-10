#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
#define prt(k) cout<<#k" = "<<k<<endl;
typedef long long ll;
const int N = 40020;
const int M = 202;
#include <vector>
bool mp[M+5][M+5];
int dp[M+5][M+5];
int cnt[M+5][M+5];
ll S;
int gcd(int a, int b) { return b==0?a:gcd(b, a%b); }
int U[M][M], R[M][M]; 
ll T[M][M]; 
int f(int i, int j)
{
    int ret = 0;
    for (int k=1;k<=j;k++) if (gcd(i,k)==1) ret++;
    return ret;
}
void init()
{
    memset(cnt, 0, sizeof cnt);
    for (int j=1;j<=200;j++)
        for (int i=1;i<=200;i++)
    {
        dp[i][j] = f(i, j);
        cnt[i][j] = cnt[i-1][j] + dp[i][j];
    }
}
int n;
int main()
{
    init();
    int re; scanf("%d", &re); int ca = 1;
    while (re--)
    {
        scanf("%d", &n);
        memset(mp, false, sizeof mp);
        memset(U, 0, sizeof U);
        memset(R, 0, sizeof R);
        memset(T, 0, sizeof T);
        S = 0;
        for (int i=0;i<n;i++)
        {
            int x, y; scanf("%d%d", &x, &y);
            mp[x][y] = true;
        }
        n = 200;
        for (int i=200;i>=1;i--)
            for (int j=200;j>=1;j--)
            if (mp[i][j]) {
                if (mp[i+1][j]) U[i][j]=U[i+1][j]+1;
                if (mp[i][j+1]) R[i][j]=R[i][j+1]+1;
            }
        for (int i=1;i<=200;i++)
            for (int j=1;j<=200;j++)
        if (mp[i][j]) {
            ll tmp[M];
            memset(tmp, 0, sizeof tmp);
            for (int k=1; k<=U[i][j]; k++)
                tmp[k] = dp[k][R[i][j]];
            for (int k = U[i][j]; k; k--)
                tmp[k-1] += tmp[k];
            S += tmp[0];
            for (int k=0; k<=U[i][j]; k++)
                T[i+k][j] += tmp[k];
        }
        ll ans = 0;
        for (int i=1;i<200;i++)
        {
            for (int j=1;j<200;j++)
            if (U[i][j]&&R[i][j]) {
                ll f = T[i][j];
                ll pp, p;
                pp = cnt[U[i][j]][R[i][j]];
                f -= pp;
                for (int k=1;k<=R[i][j];k++)
                {
                    f += T[i][j+k];
                    p = dp[k][U[i][j]];
                    ans += f * p * 2;
                }
                ans += pp * pp;
            }
        }
        ll ret = S * S - ans;
        printf("Case #%d: %I64d\n", ca++ , ret);
    }
    return 0;
}
