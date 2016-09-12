#pragma comment(linker, "/STACK:1677721600")
#include <map>
#include <set>
#include <cmath>
#include <queue>
#include <stack>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <cassert>
#include <iostream>
#include <algorithm>
#define pb push_back
#define mp make_pair
#define LL long long
#define lson lo,mi,rt<<1
#define rson mi+1,hi,rt<<1|1
#define Min(a,b) ((a)<(b)?(a):(b))
#define Max(a,b) ((a)>(b)?(a):(b))
#define mem(a,b) memset(a,b,sizeof(a))
#define rep(i,a,b) for(int i=(a); i<=(b); i++)
#define dec(i,a,b) for(int i=(a); i>=(b); i--)
using namespace std;
const int mod = 1e9 + 7;
const double eps = 1e-8;
const double ee = exp(1.0);
const int inf = 0x3f3f3f3f;
const int maxn = 500 + 10;
const double pi = acos(-1.0);
const LL iinf = 0x3f3f3f3f3f3f3f3f;
int readT()
{
    char c;
    int ret = 0,flg = 0;
    while(c = getchar(), (c < '0' || c > '9') && c != '-');
    if(c == '-') flg = 1; else ret = c ^ 48;
    while( c = getchar(), c >= '0' && c <= '9') ret = ret * 10 + (c ^ 48);
    return flg ? - ret : ret;
}
int c[maxn][maxn];
int a[maxn][maxn];
int n, m;
int lowbit(int x)
{
    return x & -x;
}
void update(int x, int y, int num)
{
    for (int i = x; i <= n; i += lowbit(i))
    {
        for (int j = y; j <= m; j += lowbit(j))
        {
            c[i][j] ^= num;
        }
    }
}
int query(int x, int y)
{
    int res = 0;
    int t = x;
    for (int i = x; i > 0; i -= lowbit(i))
    {
        for (int j = y; j > 0; j -= lowbit(j))
        {
            res ^= c[i][j];
        }
    }
    return res;
}
int sum(int x0, int y0, int x1, int y1)
{
    x0--, y0--;
    return query(x1, y1) ^ query(x0, y1) ^ query(x1, y0) ^ query(x0, y0);
}
int main()
{
    int ncase = readT();
    while (ncase--)
    {
        mem(c, 0);
        n = readT();
        m = readT();
        int q = readT();
        rep(i, 1, n)
        {
            rep(j, 1, m)
            {
                a[i][j] = readT();
                update(i, j, a[i][j]);
            }
        }
        while (q--)
        {
            int op = readT();
            if (op == 1)
            {
                int x1 = readT();
                int y1 = readT();
                int x2 = readT();
                int y2 = readT();
                int ans = sum(x1, y1, x2, y2);
                puts(ans ? "Yes" : "No");
            }
            else
            {
                int x = readT();
                int y = readT();
                int num =readT();
                update(x, y, num ^ a[x][y]);
                a[x][y] = num;
            }
        }
    }
    return 0;
}
