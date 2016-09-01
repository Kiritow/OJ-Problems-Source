#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#define inf 1e9
using namespace std;
pair<int, int> point[20];
bool fix[20];
double dp[1<<18];
double Distance(int a, int b) {
    int x1 = point[a].first, y1 = point[a].second;
    int x2 = point[b].first, y2 = point[b].second;
    return sqrt(1.0*(x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2));
}
double Fixed(int n, int state, int cur) {
    double ans = 0;
    bool mark[20];
    double dist[20];
    for (int i = 0; i < n; ++i) {
        if (((1<<i) & state)) {
            mark[i] = 1;
            dist[i] = Distance(i, cur);
        }
        else
            mark[i] = 0;
    }
    for (int i = 0; i < 2; ++i) {
        double Min = inf;
        int p = 19;
        for (int j = 0; j < n; ++j) {
            if (mark[j] && dist[j] < Min) {
                Min = dist[j];
                p = j;
            }
        }
        ans += Min;
        mark[p] = 0;
    }
    if (ans >= inf) return -1;
    return ans;
}
int main() {
    int n;
    while (cin>>n) {
        if (!n) break;
        int begin = 0, target = 0;
        for (int i = 0; i < n; ++i) {
            cin>>point[i].first>>point[i].second>>fix[i];
            if (fix[i])
                begin += (1<<i);
            target += (1<<i);
        }
        for (int i = 0; i < (1<<n); ++i)
            dp[i] = inf;
        dp[begin] = 0;
        for (int i = begin; i < target; ++i) {
            if (dp[i] == inf) continue;
            for (int j = 0; j < n; ++j) {
                if (i & (1<<j)) continue;
                double sum = Fixed(n, i, j);
                if (sum >= 0)
                    dp[i|(1<<j)] = min(dp[i|(1<<j)], dp[i] + sum);
            }
        }
        if (dp[target] == inf)
            printf("No Solution\n");
        else
            printf("%.6lf\n", dp[target]);
    }
    return 0;
}
