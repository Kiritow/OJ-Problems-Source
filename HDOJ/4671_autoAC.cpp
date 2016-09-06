#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int V = 105;
int n, m, ans[V][V];
bool vis[V][V];
int main() {
    int i, j, k;
    while(~scanf("%d%d", &n, &m)) {
        memset(ans, 0, sizeof(ans));
        memset(vis, false, sizeof(vis));
        for(i = 0, j = 1; i < m; ++i) {
            ans[i][0] = j;
            vis[i][j] = true;
            j = j == n ? 1 : j + 1;
        }
        for(i = 0; i < m; ++i) {
            if(ans[i][1] != 0)
                continue;
            int now = m % n + 1;
            for(j = i; j < m; j += n) {
                if(now == ans[j][0])
                    now = now == n ? 1 : now + 1;
                ans[j][1] = now;
                vis[j][now] = true;
                now = now == n ? 1 : now + 1;
            }
        }
        for(i = 0; i < m; ++i)
            for(j = 2, k = 1; j < n; ++j) {
                while(vis[i][k])
                    k++;
                ans[i][j] = k++;
            }
        for(i = 0; i < m; ++i) {
            for(j = 0; j < n - 1; ++j)
                printf("%d ", ans[i][j]);
            printf("%d\n", ans[i][n - 1]);
        }
    }
}
