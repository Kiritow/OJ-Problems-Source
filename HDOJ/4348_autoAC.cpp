#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;
const int maxn = 100010;
int n, m;
struct Node {
    long long d, td;
    int timelabel;
    Node() {};
    Node(long long _d, long long _td, int t) {
        d = _d; td = _td; timelabel = t;
    }
};
vector<Node> bit[maxn];
long long a[maxn], sum[maxn] = {0};
inline int lowbit(int x)
{
    return x & (-x);
}
inline void update(int x, long long w, int timelabel)
{
    int size;
    long long tw = w * x;
    while (x <= n) {
        size = bit[x].size();
        bit[x].push_back(bit[x][size-1]);
        size++;
        bit[x][size-1].d += w;
        bit[x][size-1].td += tw;
        bit[x][size-1].timelabel = timelabel;
        x += lowbit(x);
    }
}
inline long long getsum(int x, int timelabel)
{
    long long sd = 0, std = 0;
    int size, ox = x;
    while (x > 0) {
        size = bit[x].size();
        while (bit[x][size-1].timelabel > timelabel) {
            size--;
        }
        sd += bit[x][size-1].d;
        std += bit[x][size-1].td;
        x -= lowbit(x);
    }
    return (ox + 1) * sd - std;
}
inline long long getans(int x, int y, int timelabel)
{
    return sum[y] - sum[x-1] + getsum(y, timelabel) - getsum(x - 1, timelabel);
}
inline void back(int timelabel)
{
    int size;
    for (int i = 1; i <= n; ++i) {
        size = bit[i].size();
        while (bit[i][size-1].timelabel > timelabel) {
            bit[i].pop_back();
            size--;
        }
    }
}
void build()
{
    for (int i = 1; i <= n; ++i) {
        bit[i].clear();
        bit[i].push_back(Node(0LL, 0LL, 0));
    }
}
int main()
{
    int cas = 0;
    while (scanf("%d%d", &n, &m) != EOF) {
        if (cas++) printf("\n");
        for (int i = 1; i <= n; ++i) {
            scanf("%lld\n", &a[i]);
            sum[i] = sum[i-1] + a[i];
        }
        char op[3];
        int x, y, z;
        int timelabel = 0;
        build();
        while (m--) {
            scanf("%s", op);
            if (op[0] == 'Q') {
                scanf("%d%d", &x, &y);
                printf("%lld\n", getans(x, y, timelabel));
            } else if (op[0] == 'C') {
                scanf("%d%d%d", &x, &y, &z);
                timelabel++;
                update(x, z, timelabel);
                update(y + 1, -z, timelabel);
            } else if (op[0] == 'H') {
                scanf("%d%d%d", &x, &y, &z);
                printf("%lld\n", getans(x, y, z));
            } else {
                scanf("%d", &x);
                timelabel = x;
                back(x);
            }
        }
    }
    return 0;
}
