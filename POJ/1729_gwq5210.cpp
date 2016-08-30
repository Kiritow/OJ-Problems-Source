/*************************************************************************
    > File Name: 1729.cpp
    > Author: gwq
    > Mail: gwq5210@qq.com 
    > Created Time: 2015年08月11日 星期二 15时42分37秒
 ************************************************************************/

#include <cmath>
#include <ctime>
#include <cctype>
#include <climits>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#include <map>
#include <set>
#include <queue>
#include <stack>
#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <algorithm>

#define INF (INT_MAX / 10)
#define clr(arr, val) memset(arr, val, sizeof(arr))
#define pb push_back
#define sz(a) ((int)(a).size())

using namespace std;
typedef set<int> si;
typedef vector<int> vi;
typedef map<int, int> mii;
typedef pair<int, int> pii;
typedef long long ll;

const double esp = 1e-5;

#define N 35

struct Node;

int n, vis[N][N][N][N];
int sx1, sy1, sx2, sy2, ex1, ey1, ex2, ey2, cnt;
int dx[] = {0, -1, 0, 1};
int dy[] = {1, 0, -1, 0};
char direct[] = "ENWS";
char mp[N][N];

int dist(int x1, int y1, int x2, int y2)
{
    return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
}

struct Node {
    int x1, y1, x2, y2, dis, d1, d2, id, pre;
    Node() {}
    Node(int a, int b, int c, int d, int dd) :x1(a), y1(b), x2(c), y2(d), dis(dd) {}
    void output(void)
    {
        printf("dis = %d\n", dis);
        printf("x1 = %d, y1 = %d.\n", x1, y1);
        printf("x2 = %d, y2 = %d.\n", x2, y2);
        printf("-----------------\n");
    }
    bool check(void)
    {
        if (check1() && check2()) {
            return true;
        } else {
            return false;
        }
    }
    bool check1(void)
    {
        if (x1 == ex1 && y1 == ey1) {
            return true;
        } else {
            return false;
        }
    }
    bool check2(void)
    {
        if (x2 == ex2 && y2 == ey2) {
            return true;
        } else {
            return false;
        }
    }
    bool operator <(const Node v) const
    {
        return this->dis < v.dis;
    }
}way[1000010];

void bfs(void)
{
    priority_queue<Node> q;
    clr(vis, -1);
    Node v = Node(sx1, sy1, sx2, sy2, dist(sx1, sy1, sx2, sy2));
    cnt = 1;
    v.d1 = -1;
    v.d2 = -1;
    v.id = 0;
    v.pre = -1;
    q.push(v);
    way[0] = v;
    vis[sx1][sy1][sx2][sy2] = v.dis;
    while (!q.empty()) {
        Node u = q.top();
        q.pop();
        //u.output();
        if (u.check()) {
            printf("%.2f\n", sqrt(1.0 * u.dis));
            Node p = u;
            string s1, s2;
            while (p.pre != -1) {
                if (p.d1 != '*') {
                    s1.pb(p.d1);
                }
                if (p.d2 != '*') {
                    s2.pb(p.d2);
                }
                p = way[p.pre];
            }
            reverse(s1.begin(), s1.end());
            reverse(s2.begin(), s2.end());
            cout << s1 << endl;
            cout << s2 << endl;
            return;
        }
        for (int i = 0; i < 4; ++i) {
            int nx1 = u.x1 + dx[i];
            int ny1 = u.y1 + dy[i];
            int d1 = direct[i];
            if (u.check1()) {
                nx1 = u.x1;
                ny1 = u.y1;
                d1 = '*';
            }
            if (!mp[nx1][ny1] || mp[nx1][ny1] == '#' || mp[nx1][ny1] == '*') {
                ;
            } else {
                for (int j = 0; j < 4; ++j) {
                    int nx2 = u.x2 + dx[j];
                    int ny2 = u.y2 + dy[j];
                    int d2 = direct[j];
                    if (u.check2()) {
                        nx2 = u.x2;
                        ny2 = u.y2;
                        d2 = '*';
                    }
                    if (!mp[nx2][ny2] || mp[nx2][ny2] == '$' || mp[nx2][ny2] == '*') {
                        ;
                    } else {
                        int ndis = dist(nx1, ny1, nx2, ny2);
                        ndis = min(ndis, u.dis);
                        int vv = vis[nx1][ny1][nx2][ny2];
                        if (vv == -1 || ndis > vis[nx1][ny1][nx2][ny2]) {
                            vis[nx1][ny1][nx2][ny2] = ndis;
                            v = Node(nx1, ny1, nx2, ny2, ndis);
                            v.d1 = d1;
                            v.d2 = d2;
                            v.pre = u.id;
                            v.id = cnt;
                            q.push(v);
                            way[cnt++] = v;
                        }
                    }
                }
            }
        }
    }
    return;
}

int main(int argc, char *argv[])
{
    while (scanf("%d", &n) != EOF) {
        if (!n) {
            break;
        }
        clr(mp, 0);
        for (int i = 1; i <= n; ++i) {
            scanf("%s", mp[i] + 1);
            for (int j = 1; j <= n; ++j) {
                if (mp[i][j] == 'H') {
                    sx1 = i;
                    sy1 = j;
                    mp[i][j] = '$';
                } else if (mp[i][j] == 'S') {
                    ex1 = i;
                    ey1 = j;
                    mp[i][j] = '$';
                } else if (mp[i][j] == 'h') {
                    sx2 = i;
                    sy2 = j;
                    mp[i][j] = '#';
                } else if (mp[i][j] == 's') {
                    ex2 = i;
                    ey2 = j;
                    mp[i][j] = '#';
                }
            }
        }
        bfs();
    }
    return 0;
}
