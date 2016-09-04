#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <cstdlib>
using namespace std;
struct point{
    int x, y;
    point() {}
    point(int a, int b) : x(a), y(b){}
    void input(){
        scanf("%d%d", &x, &y);
    }
    friend point operator - (const point &a, const point &b){
        return point(a.x - b.x, a.y - b.y);
    }
    friend bool operator < (const point &a, const point &b){
        return a.x < b.x;
    }
};
const int maxn = 200 + 10, maxm = 500 + 10;
point po[maxn], mi[maxm];
int det(point a, point b){
    return a.x * b.y - a.y * b.x;
}
int num[maxn][maxn];
int n, m, cs;
void init(point a, point b, int &cnt){
    int x1 = a.x, x2 = b.x;
    for (int i = 0; i < m; i++)
        if (mi[i].x >= x1 && mi[i].x < x2)
            if (det(mi[i] - a, b - a) > 0)
                cnt += 1;
}
int main(){
    scanf("%d", &cs);
    for (int kase = 1; kase <= cs; ++kase){
        scanf("%d%d", &n, &m);
        for (int i = 0; i < n; i++)
            po[i].input();
        for (int i = 0; i < m; i++)
            mi[i].input();
        sort(po, po + n);
        for (int i = 0; i < n; i++)
            for (int j = i + 1; j < n; j++)
                init(po[i], po[j], num[i][j] = 0);
        printf("Case #%d: ", kase);
        double ans = -1;
        for (int i = 0; i < n; i++)
            for (int j = i + 1; j < n; j++)
                for (int k = j + 1; k < n; k++){
                    int cnt = num[i][k] - num[i][j] - num[j][k];
                    if (!cnt) continue;
                    double area = det(po[j] - po[i], po[k] - po[i]) / 2.0;
                    double tmp = area / (double)cnt;
                    if (ans == -1 || ans > tmp) ans = tmp;
                }
        if (ans == -1) puts("-1");
        else printf("%.6lf\n", ans);
    }
    return 0;
}
