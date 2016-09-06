#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <set>
using namespace std;
const int MaxN = 200000;
int N;
int bit[MaxN+5];
inline int lwb(int x) {
    return x & -x;
}
void add(int x, int val) {
    for (int i = x; i <= MaxN; i += lwb(i)) {
        bit[i] += val;    
    }
}
int sum(int x) {
    int ret = 0;
    for (int i = x; i > 0; i -= lwb(i)) {
        ret += bit[i];
    }
    return ret;
}
int cal(int x) {
    if (x <= MaxN/2) {
        int k = x << 1;
        return sum(k) - sum(k-1) + sum(MaxN) - sum(x - 1);
    } else {
        return sum(MaxN) - sum(x - 1);
    }
}
char vis[100005];
int que[100005];
int tail;
int main() {
    int T, x;
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &N);
        tail = 0;
        memset(bit, 0, sizeof (bit));
        memset(vis, 0, sizeof (vis));
        for (int i = 0; i < N; ++i)    {
            scanf("%d", &x);
            add(x<<1, 1);
            if (!vis[x]) {
                vis[x] = 1;
                que[tail++] = x;
            }
        }
        int Max = 0;
        for (int i = 0; i < tail; ++i) {
            Max = max(Max, cal(que[i]));
        }
        printf("%d\n", Max);
    }
    return 0;    
}
