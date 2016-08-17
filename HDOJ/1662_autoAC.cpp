#include<cstring>
#include<cassert>
#include<cstdio>
#include<cctype>
#include<ctime>
#include<cmath>
#include<functional>
#include<algorithm>
#include<iostream>
#include<vector>
#include<string>
#include<bitset>
#include<queue>
#include<deque>
#include<stack>
#include<list>
#include<map>
#include<set>
using namespace std;
typedef long long int64;
typedef unsigned long long uint64;
typedef pair <int, int> PII;
typedef pair <int64, int64> PLL;
typedef pair <char, char> PCC;
typedef pair <double, double> PDD;
#define MP make_pair
#define PB push_back
#define SZ(a) ((int)(a).size())
#define X first
#define Y second
#define L(x) ((x)<<1)
#define R(x) ((x)<<1 | 1)
#define max3(x, y, z) (max(max((x), (y)), (z)))
#define min3(x, y, z) (min(min((x), (y)), (z)))
#define BIT(x, i) (((x) >> (i)) & 1)
#define FOR(it, c) for( TYPE((c).begin()) it = (c).begin(); it != (c).end(); it++)
const double PI = 2.0*acos(0.0);
const double EPS = 1e-6;
#define GREATER(x, y) ((x) > (y) + EPS)
#define GREATER_EQUAL(x, y) ((x) > (y) - EPS)
#define LESS(x, y) ((x) < (y) - EPS)
#define LESS_EQUAL(x, y) ((x) < (y) + EPS)
#define EQUAL(x, y) (abs((x) - (y)) < EPS)
#define MAX_N 35
#define MAX_M 1005
#define MAXX 0x3f
#define UPPER 2147483647LL
#define INT_MAX 2147483647
#define INF (1<<29)
#define BINF (1LL<<60)
#define NONE -1
#define NIL 0
struct data{
    char alpha;
    char dir;
    data(){}
    data(char alpha, char dir) :alpha(alpha), dir(dir){}
} tile[MAX_N][MAX_N];
const int OFFR[] = { 1, 0, -1, 0 };
const int OFFC[] = { 0, 1, 0, -1 };
int n, m;
bool try_to_remove(int sx, int sy, int line_cnt){
    bool visit[2][MAX_N][MAX_N];
    memset(visit, false, sizeof(visit));
    visit[0][sx][sy] = true;
    int p = 0;
    for (int ln = 1; ln <= line_cnt; ln++){
        vector <PII> V;
        memset(visit[p ^ 1], false, sizeof(visit[p ^ 1]));
        for (int r = 0; r <= n + 1; r++) for (int c = 0; c <= m + 1; c++) if (visit[p][r][c]){
            visit[p ^ 1][r][c] = true;
            for (int k = 0; k < 4; k++){
                int xx = r + OFFR[k];
                int yy = c + OFFC[k];
                while (xx >= 0 && xx <= n + 1 && yy >= 0 && yy <= m + 1){
                    if (tile[xx][yy].alpha != '.'){
                        if (xx == sx && yy == sy)
                            break;
                        if (tile[xx][yy].alpha == tile[sx][sy].alpha)
                            V.PB(MP(xx, yy));
                        break;
                    }
                    else
                        visit[p ^ 1][xx][yy] = true;
                    xx += OFFR[k];
                    yy += OFFC[k];
                }
            }
        }
        sort(V.begin(), V.end());
        if (SZ(V) > 0){
            tile[sx][sy].alpha = tile[V[0].X][V[0].Y].alpha = '.';
            return true;
        }
        p ^= 1;
    }
    return false;
}
bool refresh(){
    data tmp[MAX_N][MAX_N];
    for (int r = 1; r <= n; r++) for (int c = 1; c <= m; c++)
        tmp[r][c] = tile[r][c];
    bool rsh = false;
    for (int r = 1; r <= n; r++) for (int c = 1; c <= m; c++) if (tile[r][c].alpha != '.'){
        int ver = 4;
        switch (tile[r][c].dir){
        case 'D': ver = 0; break;
        case 'R': ver = 1; break;
        case 'U': ver = 2; break;
        case 'L': ver = 3; break;
        }
        if (ver <= 3){
            int pr = r, pc = c;
            int nr = pr + OFFR[ver];
            int nc = pc + OFFC[ver];
            if (nr >= 1 && nr <= n && nc >= 1 && nc <= m && tmp[nr][nc].alpha == '.'){
                swap(tmp[pr][pc], tmp[nr][nc]);
                rsh = true;
            }
        }
    }
    for (int r = 1; r <= n; r++) for (int c = 1; c <= m; c++)
        tile[r][c] = tmp[r][c];
    return rsh;
}
void solve(){
    while (true){
        bool move = false;
        for (int ln = 1; ln <= 3 && !move; ln++){
            for (int r = 1; r <= n && !move; r++) for (int c = 1; c <= m && !move; c++){
                if (tile[r][c].alpha != '.' && try_to_remove(r, c, ln))
                    move = true;
            }
        }
        if (move)
            while (refresh());
        else
            break;
    }
}
int main(){
    int T = 0;
    while (~scanf("%d %d", &n, &m) && n + m){
        char tmp[5];
        for (int r = 0; r <= n+1; r++){
            for (int c = 0; c <= m+1; c++){
                if (r == 0 || r == n + 1 || c == 0 || c == m + 1)
                    tile[r][c] = data('.', 'S');
                else{
                    scanf("%s", tmp);
                    tile[r][c] = data(tmp[0], tmp[1]);
                }
            }
        }
        solve();
        printf("Case %d\n", ++T);
        for (int r = 1; r <= n; r++){
            for (int c = 1; c <= m; c++)
                putchar(tile[r][c].alpha);
            puts("");
        }
    }
    return 0;
}
