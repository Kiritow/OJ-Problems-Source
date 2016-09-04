#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <queue>
#include <stack>
#include <bitset>
#include <cstdio>
#include <vector>
#include <cassert>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <sstream>
#include <iomanip>
#include <iostream>
#include <algorithm>
#include <functional>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
#define MP(a, b) make_pair(a, b)
#define FOREACH(e,x) for(__typeof(x.begin()) e=x.begin();e!=x.end();++e)
const int MAX_R = 30 + 1;
const int dir[5][2] = {{0, 0}, {0, -1}, {0, 1}, {-1, 0}, {1, 0}};
int R, C;
int dp[MAX_R][MAX_R][MAX_R][MAX_R], vis[MAX_R][MAX_R];
char mat[MAX_R][MAX_R];
int valid(int r, int c) {
    return r >= 0 && r < R && c >= 0 && c < C && mat[r][c] != '#';
}
int searchQ(int qr, int qc, int ar, int ac) {
    int &ret = dp[qr][qc][ar][ac];
    if (ret != -1)
        return ret;
    if (qr == ar && qc == ac)
        return ret = 0;
    if (mat[qr][qc] == 'E')
        return ret = 1;
    ret = 0;    
    int nqr, nqc, nar, nac;
    for (int i = 1; i < 5 && !ret; i++) {
        nqr = qr + dir[i][0];
        nqc = qc + dir[i][1];
        if (!valid(nqr, nqc) || vis[nqr][nqc]) continue;
if (nqr == ar && nqc == ac)
    continue;
        vis[nqr][nqc] = 1;
        int win = 1;
        for (int j = 0; j < 5 && win; j++) {
            nar = ar + dir[j][0];
            nac = ac + dir[j][1];
            if (!valid(nar, nac)) continue;
            win &= searchQ(nqr, nqc, nar, nac);
        }
        vis[nqr][nqc] = 0;
        ret |= win;
    }
    return ret;
}
int searchA(int qr, int qc, int ar, int ac) {
    int &ret = dp[qr][qc][ar][ac];
    if (ret != -1)
        return ret;
    if (qr == ar && qc == ac)
        return ret = 1;
    if (mat[qr][qc] == 'E')
        return ret = 0;
    ret = 0;    
    int nqr, nqc, nar, nac;
    for (int i = 1; i < 5 && !ret; i++) {
        nar = ar + dir[i][0];
        nac = ac + dir[i][1];
        if (!valid(nar, nac) || vis[nar][nac]) continue;
        vis[nar][nac] = 1;
        int win = 1;
        for (int j = 0; j < 5 && win; j++) {
            nqr = qr + dir[j][0];
            nqc = qc + dir[j][1];
            if (!valid(nqr, nqc)) continue;
if (nqr == ar && nqc == ac)
    continue;
            win &= searchA(nqr, nqc, nar, nac);
        }
        vis[nar][nac] = 0;
        ret |= win;
    }
    return ret;
}
int main() {
    while (~scanf("%d %d", &C, &R)) {
        int sQr, sQc, sAr, sAc;
        for (int r = 0; r < R; r++) {
            scanf("%s", mat[r]);
            for (int c = 0; c < C; c++) {
                if (mat[r][c] == 'Q') sQr = r, sQc = c;
                if (mat[r][c] == 'A') sAr = r, sAc = c;
            }
        }
        memset(dp, -1, sizeof(dp));
        memset(vis, 0, sizeof(vis));
        vis[sQr][sQc] = 1;
        int escape = searchQ(sQr, sQc, sAr, sAc);
        if (escape) puts("Queen can escape.");
        else {
            memset(dp, -1, sizeof(dp));
            memset(vis, 0, sizeof(vis));
            vis[sAr][sAc] = 1;
            int cath = searchA(sQr, sQc, sAr, sAc);
            if (!cath) puts("Queen can not escape and Army can not catch Queen.");
            else puts("Army can catch Queen.");
        }
    }
    return 0;
}
