#include <stdio.h>
#include <algorithm>
#include <stdlib.h>
#include <string.h>
using namespace std;
#define maxn 10010
struct Node {
        int t, x;
} E[maxn];
bool cmp(Node a, Node b) {
        return a.t < b.t;
}
int main() {
        int T, N, i, j;
        double ans;
        scanf("%d", &T);
        for(int cas = 1; cas <= T; ++cas) {
                scanf("%d", &N);
                for(i = 0; i < N; ++i)
                        scanf("%d%d", &E[i].t, &E[i].x);
                sort(E, E + N, cmp);
                for(ans = 0.0, i = 1; i < N; ++i) {
                        ans = max(ans, abs(E[i].x - E[i-1].x) * 1.0 / (E[i].t - E[i-1].t));
                }
                printf("Case #%d: %.2lf\n", cas, ans);
        }
        return 0;
}
