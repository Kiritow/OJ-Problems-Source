#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<string>
#include<string.h>
#include<math.h>
#include<limits.h>
#include<time.h>
#include<stdlib.h>
#include<map>
#include<queue>
#include<set>
#include<stack>
#include<vector>
#define LL long long
using namespace std;
const int mod = 1e9 + 7;
char dna[5] = "ATGC";
LL dp[2][70000], prt[20];
int res[20], res1[20], ans[70000][5];
int main()
{
    int T;
    while(~scanf("%d", &T))
        while(T--)
        {
            memset(res, 0, sizeof res);
            memset(ans, 0, sizeof ans);
            memset(dp, 0, sizeof dp);
            string s;
            cin >> s;
            int n;
            cin >> n;
            int len = s.size();
            int maxx = 1 << len;
            for(int i = 0; i < maxx; i++)
            {
                res[0] = 0;
                int tmp = i;
                int cnt = 1;
                for(int j = 0; j < len; j++)
                {
                    if(tmp & 1)
                        res[cnt] = res[cnt - 1] + 1;
                    else
                        res[cnt] = res[cnt - 1];
                    cnt++;
                    tmp >>= 1;
                }
                for(int j = 0; j < 4; j++)
                {
                    res1[0] = 0;
                    for(int k = 1; k <= len; k++)
                    {
                        if(s[k - 1] == dna[j])
                            res1[k] = res[k - 1] + 1;
                        else
                            res1[k] = max(res1[k - 1], res[k]);
                    }
                    for(int k = len; k > 0; k--)
                    {
                        ans[i][j] <<= 1;
                        if(res1[k] > res1[k - 1])
                            ans[i][j] += 1;
                    }
                }
            }
            dp[0][0] = 1;
            for(int i = 0; i < n; i++)
            {
                memset(dp[(i + 1) & 1], 0, sizeof dp[(i + 1) & 1]);
                for(int j = 0; j < maxx; j++)
                {
                    for(int k = 0; k < 4; k++)
                    {
                        dp[(i + 1) & 1][ans[j][k]] += dp[i & 1][j];
                        if(dp[(i + 1) & 1][ans[j][k]] > mod)
                            dp[(i + 1) & 1][ans[j][k]] %= mod;
                    }
                }
            }
            memset(prt, 0, sizeof prt);
            for(int i = 0; i < maxx; i++)
            {
                int cnt = 0;
                int tmp = i;
                while(tmp)
                {
                    if(tmp & 1)
                        cnt++;
                    tmp >>= 1;
                }
                prt[cnt] += dp[n & 1][i];
                if(prt[cnt] > mod)
                    prt[cnt] %= mod;
            }
            for(int i = 0; i <= len; i++)
                printf("%lld\n", prt[i]);
        }
    return 0;
}
