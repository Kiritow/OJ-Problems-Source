#include <cstdio>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <cstring>
#include <cmath>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <list>
#include <map>
#include <set>
#include <bitset>
#include <cstdlib>
#include <ctime>
using namespace std;
#define lson l, mid, rt << 1
#define rson mid + 1, r, rt << 1 | 1
typedef long long ll;
const int MAXN = 1e5 + 10;
const int INF = 0x3f3f3f3f;
const int MOD = 258280327;
int cal(int x, int y)
{
    int ret = x + y;
    ret %= 9;
    if(ret == 0) return 9;
    return ret;
}
int dp[MAXN][10];
int a[MAXN];
int main(){
    int T;
    int n, s1, s2;
    scanf("%d", &T);
    while(T--){
        scanf("%d%d%d", &n, &s1, &s2);
        int sum = 0;
        for(int i = 1; i <= n; i++){
            scanf("%d", &a[i]);
            sum = cal(sum, a[i]);
        }
        int ret = cal(s1, s2);
        memset(dp, 0, sizeof(dp));
        for(int i = 1; i <= n; i++){
            dp[i][a[i]] = 1;
        }
        for(int i = 1; i <= n; i++){
            for(int j = 0; j <= 9; j++){
                dp[i][j] = (dp[i][j] + dp[i-1][j]) % MOD;
                    int x = cal(a[i], j);
                    dp[i][x] = (dp[i][x] + dp[i-1][j]) % MOD;
                }
        }
        int ans = 0;
        if(ret == sum) {
            ans += dp[n][s1];
            if(s1 == sum) ans--;
        }
        if(s1 == sum) ans++;
        if(s2 == sum) ans++;
        printf("%d\n", ans);
    }
    return 0;
}
