/*
中国象棋棋盘，Alice有一个帅，Bob有一个将和一个马。如果Alice赢，输出
"Lucky guy!"，否则就输出"Lose in x steps T.T!"，x表示从开始到结束双方走的步数和。
一方获胜当且仅当自己的将（帅被对方吃掉）。特别注意，如果出现平局我们认为Alice获胜。
Alice如果知道自己无法取胜就会尽量让比赛进行更多的步数。双方采取最优策略。
*/
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <cstdlib>
#include <time.h>
using namespace std;
#define maxn 105
 
const int move_ma[8][2] = {///马移动
    {-2, -1}, {-2, 1}, {-1, -2}, {1, -2},
    {-1, 2}, {1, 2}, {2, -1}, {2, 1}
};
const int no[4][2] = {///马脚
    {-1, 0}, {0, -1}, {0, 1}, {1, 0}
};
const int move_shuai[4][2] = {///将移动
    {1, 0}, {-1, 0}, {0, 1}, {0, -1}
};
int Max[maxn][10][10], cnt[maxn][10][10];
int vis[maxn][10][10][2];
///敌马的位置 敌将位置 我将位置 0:我先手 1:敌先手
///状态下的失败步数
///0表示我必胜
int out[maxn][10][10];
///我先走 这个状态后继状态中有多少种合法状态
 
struct node {
    int a, b, c;///马位置 敌将位置 我将位置
    int id;///0:我先手 1:敌先手
    int step;///这个状态下失败的步数
    node (int _a, int _b, int _c, int _id, int _s) {
        a = _a, b = _b, c = _c, id = _id, step = _s;
    }
};
queue <node> q;
 
bool balk (int now, int next, int i, int j) {
    int x = now/9, y = now%9;
    int xx = next/9, yy = next%9;
    //cout << x << " " << y << endl;
    //cout << xx << " " << yy << endl;
    for (int k = 0; k < 8; k++) { 
        if (xx == x+move_ma[k][0] && yy == y+move_ma[k][1]) { //cout << k << endl;
            int xxx = x+no[k/2][0], yyy = y+no[k/2][1];
            //cout << xxx << " " << yyy << endl;
            if (xxx == i/3+7 && yyy == i%3+3) return 1;
            if (xxx == j/3 && yyy == j%3+3) return 1;
        }
    }
    return 0;
}
 
void bfs () {
    while (!q.empty ()) {
        node now = q.front (); q.pop ();
        int x = now.c/3, y = now.c%3;///我帅
        int ma_x = now.a/9, ma_y = now.a%9;///敌马
        if (now.id == 0) {///这一步是我先手 上一步是敌先手
            for (int i = 0; i < 4; i++) {///敌走将
                int xx = now.b/3+move_shuai[i][0], yy = now.b%3+move_shuai[i][1];///上一步敌将的位置
                if (xx < 0 || xx >= 3 || yy < 0 || yy >= 3) continue;
                if (vis[now.a][xx*3+yy][now.c][1] != -1) continue;
                if (xx+7 == ma_x && yy+3 == ma_y) continue;///敌将和马不重合
                vis[now.a][xx*3+yy][now.c][1] = now.step+1;
                q.push (node (now.a, xx*3+yy, now.c, 1, now.step+1));
            }
 
            for (int i = 0; i < 8; i++) {
                int xx = ma_x+move_ma[i][0], yy = ma_y+move_ma[i][1];
                if (xx < 0 || xx >= 10 || yy < 0 || yy >= 9) continue;
                if (vis[xx*9+yy][now.b][now.c][1] != -1) continue;
                if (xx == now.b/3+7 && yy == now.b%3+3) continue;///敌将和马不重合
                if (xx == x && yy == y+3) continue;///敌马和我帅不重合
                if (balk (xx*9+yy, now.a, now.b, now.c)) continue;///马脚
                vis[xx*9+yy][now.b][now.c][1] = now.step+1;
                q.push (node (xx*9+yy, now.b, now.c, 1, now.step+1));
            }
        }
        else {///上一步是我先手
            for (int i = 0; i < 4; i++) {
                int xx = x+move_shuai[i][0], yy = y+move_shuai[i][1];///上一步我的位置
                if (xx < 0 || xx >= 3 || yy < 0 || yy >= 3) continue;
                if (vis[now.a][now.b][xx*3+yy][0] != -1) continue;
                if (xx == ma_x && yy+3 == ma_y) continue;///上一步不可能重合
                Max[now.a][now.b][xx*3+yy] = max (Max[now.a][now.b][xx*3+yy], now.step);
                if (++cnt[now.a][now.b][xx*3+yy] == out[now.a][now.b][xx*3+yy]) {
                    vis[now.a][now.b][xx*3+yy][0] = Max[now.a][now.b][xx*3+yy]+1;
                    q.push (node (now.a, now.b, xx*3+yy, 0, vis[now.a][now.b][xx*3+yy][0]));
                }
            }
        }
    }
}
 
int relation (int x, int y, int i, int j, int who) {
    ///0:我必败 1:我必胜 2:不一定
    int x1 = i/3, y1 = i%3;///敌将
    int x2 = j/3, y2 = j%3;///我帅
    y1 += 3, y2 += 3;
    if (y1 == y2) {///两王相对(中间没有马) 胜负立分
        if (y == y1) {
            if (x > x1+7 || x < x2) {
                if (who == 0) return 1;
                return 0;
            }
            else return 2;
        }
        if (who == 0)
            return 1;
        else
            return 0;
    }
    if (who == 1) {
        int d1 = abs (x-x2), d2 = abs (y-y2);
        if ((d1 == 1 && d2 == 2) || (d1 == 2 && d2 == 1))
            return 0;///被敌马吃掉
        return 2;
    }
    ///马被吃
    if (x > 2 || y < 3 || y > 5) return 2;//马在外面
    if (y == y2) {
        if (x2-x == 1) {///在我将的下侧
            return 1;
        }
        if (x-x2 == 1) {///在我将的上侧
            if (y1 == y) return 2;///有敌将的保护
            return 1;
        }
        return 2;
    }
    if (x == x2 && abs (y-y2) == 1 && y <= 5 && y >= 3) {///在我将的左右侧
        if (y1 == y)
            return 2;///有敌方将的保护
        return 1;
    }
    return 2;
}
 
void init () {
    while (!q.empty ()) q.pop ();
    memset (vis, -1, sizeof vis);
    memset (Max, 0, sizeof Max);
    memset (out, 0, sizeof out);
    memset (cnt, 0, sizeof cnt);
    for (int x = 0; x < 10; x++) for (int y = 0; y < 9; y++) {///敌马位置
        for (int i = 0; i < 9; i++) {///敌将位置
            for (int j = 0; j < 9; j++) {///我将位置
                if ((y-3 == j%3 && x == j/3) || (y-3 == i%3 && x-7 == i/3))
                    continue;///马和将重合
                int res0 = relation (x, y, i, j, 0);
                int res1 = relation (x, y, i, j, 1);
                if (!res0)
                    vis[x*9+y][i][j][0] = 1, q.push (node (x*9+y, i, j, 0, 1));
                else if (res0 == 1) vis[x*9+y][i][j][0] = 0;
                if (!res1)
                    vis[x*9+y][i][j][1] = 1, q.push (node (x*9+y, i, j, 1, 1));
                else if (res1 == 1) vis[x*9+y][i][j][1] = 0;
 
                for (int k = 0; k < 4; k++) {///我先走
                    int next_x = j/3+move_shuai[k][0], next_y = j%3+move_shuai[k][1];
                    if (next_x < 0 || next_x >= 3 || next_y < 0 || next_y >= 3) continue;
                    if (next_x == x && next_y+3 == y) continue;///和马重合的状态已经计算过了
                    out[x*9+y][i][j]++;
                }
            }
        }
    }
    bfs ();
}
 
int x, y, xx, yy, xxx, yyy;
 
int main () {
    //freopen ("in", "r", stdin);
    //freopen ("out", "w", stdout);
    init ();    int t;
    //cout << balk (21, 32, 0, 7) << endl;
    //cout << vis[30][1][6][1] << endl;
    //cout << vis[0][0][0][0] << endl;
    cin >> t;
    int who;
    //输入敌马 敌将 我将坐标 先手的人
    while (t--) {
        cin >> x >> y >> xx >> yy >> xxx >> yyy >> who;
        xx -= 7, yy -= 3;
        yyy -= 3;
        int res = vis[x*9+y][xx*3+yy][xxx*3+yyy][who];
        if (res == 0) {
            cout << "Lucky guy!" << endl;
        }
        else
            cout << "Lose in " << res << " steps T.T!" << endl;
    }
    return 0;
}
