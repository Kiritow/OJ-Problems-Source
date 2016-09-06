#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <map>
#include <queue>
#include <set>
#include <vector>
#define MAXM 111111
#define MAXN 111111
#define INF 1000000007
#define eps 1e-8
using namespace std;
typedef vector<int>::iterator Viter;
int n;
vector<int>g;
int a[MAXN];
int dp1[MAXN], dp2[MAXN], num1[MAXN], num2[MAXN];
void gao(int dp[], int num[])
{
    g.clear();
    Viter it;
    for(int i = n - 1; i >= 0; i--)
    {
        int sz = g.size();
        if(!sz || a[i] >= g[sz - 1])
        {
            g.push_back(a[i]);
            dp[i] = sz + 1;
        }
        else
        {
            it = upper_bound(g.begin(), g.end(), a[i]);
            dp[i] = it - g.begin() + 1;
            *it = a[i];
        }
        pair<Viter, Viter>bounds = equal_range(g.begin(), g.end(), a[i]);
        num[i] = bounds.second - bounds.first;
    }
}
int main()
{
    int T;
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d", &n);
        for(int i = 0; i < n; i++) scanf("%d", &a[i]);
        gao(dp1, num1);
        for(int i = 0; i < n; i++) a[i] = -a[i];
        gao(dp2, num2);
        int ans = 0;
        for(int i = 0; i < n; i++)
            ans = max(ans, dp1[i] + dp2[i] - min(num1[i], num2[i]));
        printf("%d\n", ans);
    }
    return 0;
}
