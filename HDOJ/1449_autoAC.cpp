#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <iostream>
#define INF 0x3f3f3f3f
#define MAXN 1000005
using namespace std;
int N, dp[MAXN];
struct Node {
    int x, y, ac;
}e[5005];
int DP() {
    int ret = INF;
    memset(dp, 0x3f, sizeof (dp));
    dp[e[1].x] = 0; 
    for (int i = 2; i <= N; ++i) { 
        int a = e[i].ac, b = e[i].x; 
        for (int j = a; j < b; ++j) {
            int p = 2*e[i].x-j;
            if (p < e[N].x) {
                dp[p] = min(dp[p], dp[j]+1);
            } else {
                ret = min(ret, dp[j]+1); 
            }
        }
    }
    return ret == INF ? -1 : ret;
}
int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &N);
        for (int i = 1; i <= N; ++i) {
            scanf("%d %d", &e[i].x, &e[i].y);
            e[i].ac = max(0, (int)ceil(e[i].x-sqrt(2.*e[i].y*e[1].y-1.*e[1].y*e[1].y)));
        }
        printf("%d\n", DP());
    }
    return 0;    
}
