#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;
const int MAX_N = 10;
const int MAX_S = 1 << MAX_N;
const int Mod = (int)1e9 + 7;
int n, m;
bool edge[MAX_N][MAX_N];
int cntEdge[MAX_S][MAX_S];
long long connected[MAX_S];
long long biconnected[MAX_S];
long long expand[MAX_S][MAX_S];
int main() {
    #ifdef LOCAL_JUDGE
    freopen("in.txt", "r", stdin);
    #endif
    int T;
    scanf("%d", &T);
    for (int cas = 1; cas <= T; cas++) {
        scanf("%d %d", &n, &m);
        memset(edge, true, sizeof(edge));
        for (int i = 1; i <= m; i++) {
            int a, b;
            scanf("%d %d", &a, &b);
            a--;
            b--;
            edge[a][b] = false;
            edge[b][a] = false;
        }
        for (int i = 0; i < n; i++) {
            edge[i][i] = false;
        }
        int cntState = 1 << n;
        for (int i = 0; i < cntState; i++) {
            for (int j = 0; j < cntState; j++) {
                if (i == j || (i & j) == 0) {
                    int &ref = cntEdge[i][j];
                    ref = 0;
                    for (int x = 0; x < n; x++) {
                        if ((i >> x) & 1) {
                            int low = (i == j) ? x + 1 : 0;
                            for (int y = low; y < n; y++) {
                                if ((j >> y) & 1) {
                                    ref += edge[x][y];
                                }
                            }
                        }
                    }
                }
            }
        }
        connected[0] = 1;
        biconnected[0] = 1;
        for (int mask = 1; mask < cntState; mask++) {
            int lowbit = mask & -mask;
            {
                long long &ref = connected[mask];
                ref = 1ll << cntEdge[mask][mask];
                for (int subset = mask ^ lowbit; subset; subset = (subset - 1) & (mask ^ lowbit)) {
                    ref -= connected[mask ^ subset] * (1ll << cntEdge[subset][subset]);
                }
            }
            {
                for (int target = mask ^ lowbit; target; target = (target - 1) & (mask ^ lowbit)) {
                    int source = mask ^ target;
                    int _lowbit = target & -target;
                    long long &ref = expand[mask][source];
                    ref = 0;
                    for (int subset = target ^ _lowbit; ; subset = (subset - 1) & (target ^ _lowbit)) {
                        int set = target ^ subset;
                        ref += connected[set] * cntEdge[set][source] * expand[mask ^ set][source];
                        if (subset == 0) {
                            break;
                        }
                    }
                }
                expand[mask][mask] = 1;
            }
            {
                long long &ref = biconnected[mask];
                ref = connected[mask];
                for (int subset = mask ^ lowbit; subset; subset = (subset - 1) & (mask ^ lowbit)) {
                    ref -= biconnected[mask ^ subset] * expand[mask][mask ^ subset];
                }
            }
        }
        int ans = biconnected[cntState - 1] % Mod;
        printf("%d\n", ans);
    }
    return 0;
}
