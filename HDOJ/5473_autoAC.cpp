#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <algorithm>
using namespace std;
typedef long long ll;
struct Point {
    ll x, y;
    Point(ll x = 0, ll y = 0): x(x), y(y) {}
    void read() { scanf("%lld%lld", &x, &y); } 
    bool operator < (const Point& u) const { return x < u.x || (x == u.x && y < u.y); }
    bool operator == (const Point& u) const { return !(*this < u) && !(u < *this); }
    bool operator != (const Point& u) const { return !(*this == u); }
    bool operator > (const Point& u) const { return u < *this; }
    bool operator <= (const Point& u) const { return *this < u || *this == u; }
    bool operator >= (const Point& u) const { return *this > u || *this == u; }
    Point operator + (const Point& u) { return Point(x + u.x, y + u.y); }
    Point operator - (const Point& u) { return Point(x - u.x, y - u.y); }
    Point operator * (const double u) { return Point(x * u, y * u); }
    Point operator / (const double u) { return Point(x / u, y / u); }
    ll operator ^ (const Point& u) { return x*u.y - y*u.x; }
};
typedef Point Vector;
ll Cross(Vector a, Vector b) { return a.x * b.y - a.y * b.x; }
ll getArea (Point* p, int n) {
    ll ret = 0;
    for (int i = 0; i < n-1; i ++)
        ret += Cross(p[i]-p[0], p[i+1]-p[0]);
    return ret < 0 ? -ret : ret;
}
int getConvexHull (Point* p, int n, Point* ch) {
    sort(p, p + n);
    int m = 0;
    for (int i = 0; i < n; i++) {
        while (m > 1 && Cross(ch[m-1]-ch[m-2], p[i]-ch[m-1]) <= 0) m--;
        ch[m++] = p[i];
    }
    int k = m;
    for (int i = n-2; i >= 0; i--) {
        while (m > k && Cross(ch[m-1]-ch[m-2], p[i]-ch[m-1]) <= 0) m--;
        ch[m++] = p[i];
    }
    if (n > 1) m--;
    return m;
}
const int maxn = 105;
int N, K;
ll dp[maxn][maxn];
Point P[maxn], Q[maxn];
ll solve () {
    ll allarea = getArea(P, N);
    if (K >= N) return allarea;
    ll ret = 0;
    bool vis[maxn];
    memset(vis, 0, sizeof(vis));
    int ti = min(5 * (N / K), N);
    for (int t = 0; t < ti; t++) {
        int s = rand() % N;
        while (vis[s]) s = rand() % N;
        vis[s] = 1;
        memset(dp, 0, sizeof(dp));
        dp[0][0] = allarea;
        for (int i = 1; i <= N; i++) {
            int u = (i + s) % N;
            ll sum = 0;
            for (int j = i-1; j >= 0; j--) {
                int v = (j + s) % N;
                int p = (v + 1) % N;
                ll tmp = ((P[p]-P[u])^(P[v]-P[u]));
                if (tmp < 0) tmp = -tmp;
                sum += tmp;
                for (int x = K; x > 0; x--)
                    dp[i][x] = max(dp[i][x], dp[j][x-1]-sum);
            }
        }
        ret = max(ret, dp[N][K]);
    }
    return ret;
}
int main () {
    int cas;
    scanf("%d", &cas);
    srand((int)time(NULL));
    for (int kcas = 1; kcas <= cas; kcas++) {
        scanf("%d%d", &N, &K);
        for (int i = 0; i < N; i++) Q[i].read();
        N = getConvexHull(Q, N, P);
        printf("Case #%d: %lld\n", kcas, solve());
    }
    return 0;
}
