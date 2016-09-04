#include <iostream>
#include <stack>
#include <queue>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <set>
#include <vector>
#include <cstring>
#include <algorithm>
#define INF 0x7ffffffffffLL
#define N 10010
#define M 100010
#define LL long long
#define mod 95041567
using namespace std;
struct node{
    int index;
    int val;
};
int n, m, k, MAX;
int fb[N], life[M];
node dp[N][110];
node cal(int x, int y, bool f){
    node v = dp[x - 1][y];
    int z = fb[x];
    if(f) v = dp[x - 1][y - 1], z *= 2;
    bool flag = 0;
    while(v.index <= k){
        if(v.val > z){
            if(!flag) v.val -= z;
            return v;
        }
        else{
            if(v.index) flag = 1;
            z -= v.val;
            v.val = life[++v.index];
            if(v.index > 1 && z == 0) return v;
        }
    }
    return v;
}
int main()
{
    while(scanf("%d %d %d", &n, &m, &k) != EOF){
        if(n + m + k ==0) break;
        for(int i = 1; i <= n; ++i)
            scanf("%d", &fb[i]);
        for(int i = 1; i <= k; ++i)
            scanf("%d", &life[i]);
        if(!k){
            printf("0\n");
            continue;
        }
        MAX = 0;
        dp[0][0].index = 0, dp[0][0].val = 0;
        for(int i = 1; i <= n; ++i){
            int p = min(i, m);
            for(int j = 0; j <= p; ++j){
                node x = cal(i, j, 0);
                if(!j){
                    dp[i][j] = x;
                    MAX = max(MAX, dp[i][j].index - 1);
                    continue;
                }
                node y = cal(i, j, 1);
                if(j == i){
                    dp[i][j] = y;
                    MAX = max(MAX, dp[i][j].index - 1);
                    continue;
                }
                if(x.index > y.index) dp[i][j] = x;
                else if(x.index < y.index) dp[i][j] = y;
                else if(x.val > y.val) dp[i][j] = y;
                else dp[i][j] = x;
                MAX = max(MAX, dp[i][j].index - 1);
            }
            if(p <= m) dp[i][p + 1] = dp[i][p];
        }
        printf("%d\n", MAX);
    }
    return 0;
}
