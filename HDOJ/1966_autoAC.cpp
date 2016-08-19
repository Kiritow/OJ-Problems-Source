#include <stdio.h>  
#include <string.h>  
#include <math.h>  
#define min(a,b) ((a)<(b)?(a):(b))  
#define max(a,b) ((a)>(b)?(a):(b))  
#define INF 0x3f3f3f3f  
const int N = 55;  
const double eps = 1e-6;  
int t, n;  
double dp[N][N];  
struct Point {  
    double x, y;  
    void read() {  
        scanf("%lf%lf", &x, &y);  
    }  
} p[N];  
double area(Point a, Point b, Point c) {  
    return fabs((b.x - a.x) * (c.y - a.y) - (c.x - a.x) * (b.y - a.y)) / 2.0;  
}  
void init() {  
    scanf("%d", &n);  
    for (int i = 0; i < n; i++)  
        p[i].read();  
}  
bool judge(int i, int j, int k) {  
    double s = area(p[i], p[j], p[k]);  
    for (int x = 0; x < n; x++) {  
        if (x == i || x == j || x == k) continue;  
        double sum = area(p[i], p[j], p[x]) + area(p[i], p[k], p[x]) + area(p[k], p[j], p[x]);  
        if (fabs(sum - s) < eps) return false;  
    }  
    return true;  
}  
double solve() {  
    double ans = INF;  
    for (int len = 2; len < n; len++) {  
        for (int l = 0; l < n; l++) {  
            int r = (l + len) % n;  
            dp[l][r] = INF;  
            for (int k = (l + 1) % n; k != r; k = (k + 1) % n) {  
                if (!judge(l, k, r)) continue;  
                dp[l][r] = min(dp[l][r], max(max(dp[l][k], dp[k][r]), area(p[l], p[k], p[r])));  
            }  
            if (len == n - 1)  
                ans = min(ans, dp[l][r]);  
        }  
    }  
    return ans;  
}  
int main() {  
    scanf("%d", &t);  
    while (t--) {  
        init();  
        printf("%.1lf\n", solve());  
    }  
    return 0;  
}
