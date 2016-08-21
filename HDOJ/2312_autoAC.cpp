#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
#include <cctype>
using namespace std;
typedef pair<int, int> PII;
typedef pair<PII, PII> PPP;
typedef pair<int, PPP> PPPI;
#define FI first
#define SE second
#define PRIQ priority_queue
const int R = 66;
const int C = 33;
char mat[R][C];
bool vis[R][C][R][C];
int n, m;
inline int dis(int a, int b, int c, int d) { return abs(a - c) + abs(b - d);}
inline bool inmat(int a, int b) { return 0 <= a && a < n && 0 <= b && b < m;}
int work() {
    PRIQ<PPPI> Q;
    int nx, ny, cx, cy;
    memset(vis, 0, sizeof(vis));
    while (!Q.empty()) Q.pop();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (mat[i][j] != 'S') continue;
            for (int dx = -2; dx <= 2; dx++) {
                nx = i + dx;
                for (int dy = 1; dy <= 3; dy++) {
                    ny = j + dy;
                    if (inmat(nx, ny) && dis(i, j, nx, ny) <= 3 && mat[nx][ny] != 'X' && !vis[i][j][nx][ny]) {
                        if (isdigit(mat[nx][ny])) Q.push(PPPI((int) '0' - mat[nx][ny], PPP(PII(i, j), PII(nx, ny))));
                        else Q.push(PPPI(0, PPP(PII(i, j), PII(nx, ny))));
                        vis[i][j][nx][ny] = true;
                    }
                    ny = j - dy;
                    if (inmat(nx, ny) && dis(nx, ny, i, j) <= 3 && mat[nx][ny] != 'X' && !vis[nx][ny][i][j]) {
                        if (isdigit(mat[nx][ny])) Q.push(PPPI((int) '0' - mat[nx][ny], PPP(PII(nx, ny), PII(i, j))));
                        else Q.push(PPPI(0, PPP(PII(nx, ny), PII(i, j))));
                        vis[nx][ny][i][j] = true;
                    }
                }
            }
        }
    }
    while (!Q.empty()) {
        PPPI cur = Q.top();
        Q.pop();
        int v = cur.FI, a = cur.SE.FI.FI, b = cur.SE.FI.SE, c = cur.SE.SE.FI, d = cur.SE.SE.SE;
        if (mat[a][b] == 'T' || mat[c][d] == 'T') return -v;
        for (int dx = -2; dx <= 2; dx++) {
            nx = a + dx;
            cx = c + dx;
            for (int dy = 1; dy <= 3; dy++) {
                ny = b + dy;
                if (inmat(nx, ny) && dis(a, b, nx, ny) <= 3 && mat[nx][ny] != 'X' && !vis[a][b][nx][ny]) {
                    if (isdigit(mat[nx][ny])) Q.push(PPPI((int) '0' - mat[nx][ny] + v, PPP(PII(a, b), PII(nx, ny))));
                    else Q.push(PPPI(v, PPP(PII(a, b), PII(nx, ny))));
                    vis[a][b][nx][ny] = true;
                }
                cy = d - dy;
                if (inmat(cx, cy) && dis(cx, cy, c, d) <= 3 && mat[cx][cy] != 'X' && !vis[cx][cy][c][d]) {
                    if (isdigit(mat[cx][cy])) Q.push(PPPI((int) '0' - mat[cx][cy] + v, PPP(PII(cx, cy), PII(c, d))));
                    else Q.push(PPPI(v, PPP(PII(cx, cy), PII(c, d))));
                    vis[cx][cy][c][d] = true;
                }
            }
        }
    }
    return -1;
}
int main() {
    while (cin >> m >> n && (n || m)) {
        char buf[3];
        for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) cin >> buf, mat[i][j] = buf[0];
        cout << work() << endl;
    }
    return 0;
}
