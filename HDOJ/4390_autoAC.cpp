#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <cstring>
#include <algorithm>
#include <string>
#include <set>
#include <ctime>
#include <queue>
#include <map>
#include <sstream>
#define CL(arr, val)    memset(arr, val, sizeof(arr))
#define REP(i, n)       for((i) = 0; (i) < (n); ++(i))
#define FOR(i, l, h)    for((i) = (l); (i) <= (h); ++(i))
#define FORD(i, h, l)   for((i) = (h); (i) >= (l); --(i))
#define L(x)    (x) << 1
#define R(x)    (x) << 1 | 1
#define MID(l, r)   (l + r) >> 1
#define Min(x, y)   x < y ? x : y
#define Max(x, y)   x < y ? y : x
#define E(x)    (1 << (x))
const double eps = 1e-4;
typedef long long LL;
const int inf = ~0u>>2;
using namespace std;
const int N = 110;
const int M = 1000010;
const int MOD = 1e9 + 7;
int c[N][N];
int k[M], t[M];
int num, n;
int prime[N*20];
bool vis[N*20];
int cnt;
void get_prime() {
    CL(vis, true);
    int i, j;
    for(i = 2; i < N*20; ++i) {
        for(j = i*i; j < N*20; j += i) {
            vis[j] = false;
        }
    }
    cnt = 0;
    for(i = 2; i < N*20; ++i) {
        if(vis[i])  prime[cnt++] = i;
    }
}
void init() {
    get_prime();
    CL(c, 0);
    int i , j;
    for(i = 0; i < N; ++i)  c[i][0] = c[i][i] = 1;
    for(i = 2; i < N; ++i) {
        for(j = 1; j < i; ++j) {
            c[i][j] = (c[i-1][j] + c[i-1][j-1])%MOD;
        }
    }
}
LL solve(int x) {
    int m = n, flag = 1, i;
    for(i = 0; i < n; ++i) {
        if(((1<<i)&x) == 0) {
            flag *= -1; m--;
        }
    }
    LL tmp = 1;
    for(i = 0; i < num; ++i) {
        tmp = tmp*LL(c[k[i]+m-1][m-1])%MOD;
    }
    return tmp*flag;
}
int main() {
    init();
    int x, i, j;
    LL ans;
    while(~scanf("%d", &n)) {
        CL(t, 0);
        for(i = 0; i < n; ++i) {
            scanf("%d", &x);
            for(j = 0; prime[j]*prime[j] <= x; ++j) {
                if(x%prime[j] == 0) {
                    while(x%prime[j] == 0) {
                        t[prime[j]]++; x /= prime[j];
                    }
                }
            }
            if(x != 1)   t[x]++;
        }
        num = 0;
        for(i = 2; i < M; ++i) {
            if(t[i] != 0) {
                k[num++] = t[i];
            }
        }
        ans = 0;
        for(i = (1<<n)-1; i >= 1; --i) {
            ans = (ans + solve(i))%MOD;
        }
        cout << (ans%MOD + MOD)%MOD << endl;
    }
    return 0;
}
