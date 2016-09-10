#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<time.h>
#include<string>
#define REP(i,n) for(int i=0;i<n;++i)
#define REP1(i,a,b) for(int i=a;i<=b;++i)
#define REP2(i,a,b) for(int i=a;i>=b;--i)
#define MP make_pair
#define LL long long
#define ULL unsigned long long
#define X first
#define Y second
#define MAXN 1000050
using namespace std;
map<ULL, int> mp;
int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };
char s[6][9];
int id[6][9];
int qx[100];
int qy[100];
int qcnt;
ULL q[MAXN];
ULL bas[100];
struct node {
    char a[6][9];
    int scnt;
    node() {
    }
    ;
    node(ULL now) {
        scnt = 0;
        REP(i,6)
            REP(j,8)
                a[i][j] = s[i][j];
        REP(i,qcnt)
        {
            ULL k = now & 3;
            now >>= 2;
            if (k == 0)
                continue;
            if (k == 1) {
                a[qx[i]][qy[i]] = 'S';
                scnt++;
            }
            if (k == 2)
                a[qx[i]][qy[i]] = 'M';
            if (k == 3)
                a[qx[i]][qy[i]] = 'P';
        }
    }
};
void init() {
    qcnt = 0;
    int cid = 0;
    memset(id, -1, sizeof(id));
    REP(i,6)
        REP(j,8)
        {
            if (s[i][j] == '#' || s[i][j] == 'N')
                continue;
            qx[qcnt] = i;
            qy[qcnt++] = j;
            id[i][j] = cid++;
        }
}
ULL geths(char s[6][9]) {
    ULL ans = 0;
    REP(i,6)
        REP(j,8)
        {
            if (s[i][j] == 'S') {
                ans += bas[id[i][j] << 1];
                continue;
            }
            if (s[i][j] == 'M') {
                ans += 2 * bas[id[i][j] << 1];
                continue;
            }
            if (s[i][j] == 'P') {
                ans += 3 * bas[id[i][j] << 1];
            }
        }
    return ans;
}
bool check(int x, int y) {
    if (x < 0 || x >= 6 || y < 0 || y >= 8)
        return false;
    return true;
}
node move(node a, int x, int y, int dxx, int dyy, int &p) {
    char c = a.a[x][y];
    while (true) {
        int xx = x + dxx;
        int yy = y + dyy;
        if ((!check(xx, yy)) || a.a[xx][yy] != '.') {
            p = 1;
            return a;
        }
        a.a[xx][yy] = a.a[x][y];
        a.a[x][y] = '.';
        if (c == 'P') {
            int flag=0;
            for (int j = 0; j < 4; ++j) {
                int px = xx + dx[j];
                int py = yy + dy[j];
                if (!check(px, py))
                    continue;
                if (a.a[px][py] == 'N') {
                    p = 0;
                    return a;
                }
                if (a.a[px][py] == 'S' || a.a[px][py] == 'M') {
                    if (a.a[px][py] == 'S') {
                        a.scnt--;
                        if (a.scnt == 0) {
                            p = 0;
                            return a;
                        }
                    }
                    a.a[px][py] = '.';
                    flag=1;
                }
            }
            if(flag)
            {
                p=1;
                return a;
            }
        } else {
            for (int i = 0; i < 4; ++i) {
                int px = xx + dx[i];
                int py = yy + dy[i];
                if (!check(px, py))
                    continue;
                if (a.a[px][py] == 'P') {
                    if (c == 'S') {
                        a.scnt--;
                        if (a.scnt == 0) {
                            p = 0;
                            return a;
                        }
                    }
                    a.a[xx][yy] = '.';
                    p = 1;
                    return a;
                }
            }
            for (int i = 0; i < 4; ++i) {
                int px = xx + dx[i];
                int py = yy + dy[i];
                if (!check(px, py))
                    continue;
                if (a.a[px][py] == 'N') {
                    if (c == 'S') {
                        p = 2;
                        return a;
                    }
                    p = 0;
                    return a;
                }
            }
        }
        x = xx;
        y = yy;
    }
    return a;
}
int d[MAXN];
int bfs(ULL st) {
    int tail = 0;
    d[0] = 0;
    q[tail++] = st;
    mp.clear();
    mp[st] = 1;
    for (int i = 0; i < tail; ++i) {
        node a = node(q[i]);
        REP(j,6)
            REP(k,8)
            {
                if (a.a[j][k] == 'S' || a.a[j][k] == 'M' || a.a[j][k] == 'P') {
                    for (int x = 0; x < 4; ++x) {
                        int p;
                        node e = move(a, j, k, dx[x], dy[x], p);
                        if (p == 2) {
                            return d[i] + 1;
                        }
                        if (p == 1) {
                            ULL hs = geths(e.a);
                            if (mp.find(hs) == mp.end()) {
                                mp[hs] = 1;
                                q[tail] = hs;
                                d[tail++] = d[i] + 1;
                            }
                        }
                    }
                }
            }
    }
    printf("tail:%d\n",tail);
    return -1;
}
int main() {
    bas[0] = 1;
    for (int i = 1; i <= 64; ++i)
        bas[i] = bas[i - 1] * 2;
    while(scanf(" %s",s[0])!=EOF){
        for(int i=1;i<6;++i)scanf(" %s",s[i]);
        init();
        ULL hs=geths(s);
        REP(i,6)REP(j,8)if(s[i][j]=='S'||s[i][j]=='M'||s[i][j]=='P')s[i][j]='.';
        int ans=bfs(hs);
        printf("%d\n",ans);
    }
    return 0;
}
