#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long int Int64;
int N;
struct Point
{
    Int64 x, y, sum;
}e[100005];
bool cmpx(Point a, Point b)
{
    return a.x < b.x;
}
bool cmpy(Point a, Point b)
{
    return a.y < b.y;
}
int main()
{
    int T, t;
    Int64 sum, Min;
    scanf("%d", &T);
    while (T--) {
        Min = 1LL << 62;
        scanf("%d", &N);
        for (int i = 1; i <= N; ++i) {
            scanf("%I64d %I64d", &e[i].x, &e[i].y);
            t = e[i].x, e[i].x += e[i].y;
            e[i].y -= t, e[i].sum = 0;
        }
        sort(e+1, e+1+N, cmpx);
        sum = 0;
        for (int i = 1; i <= N; ++i) {
            e[i].sum += (i-1) * e[i].x - sum;
            sum += e[i].x;
        }
        sum = 0;
        for (int i = N; i >= 1; --i) {
            e[i].sum += sum - (N-i) * e[i].x;
            sum += e[i].x;
        }
        sort(e+1, e+1+N, cmpy);
        sum = 0;
        for (int i = 1; i <= N; ++i) {
            e[i].sum += (i-1) * e[i].y - sum;
            sum += e[i].y;
        }
        sum = 0;
        for (int i = N; i >= 1; --i) {
            e[i].sum += sum - (N-i) * e[i].y;
            Min = min(Min, e[i].sum);
            sum += e[i].y;
        }
        printf("%I64d\n", Min >> 1);
    }
    return 0;
}
