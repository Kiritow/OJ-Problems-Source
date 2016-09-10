#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <queue>
#include <stack>
#define lson step << 1
#define rson step << 1 | 1
#define lowbit(x) (x & (-x))
#define Key_value ch[ch[root][1]][0] 
using namespace std;
typedef long long LL;
const int N = 505;
int n , m , r , q;
int food[N][N] , prod[N][N];
int a[N * N] , b[N * N] , tot , x[N * N];
int s[N * N] , cnt;
void add (int x , int v) {
    for (int i = x ; i <= cnt ; i += lowbit (i)) {
        s[i] = max (s[i] , v);
    }
}
int ask (int x) {
    int ret = 0;
    for (int i = x ; i > 0 ; i -= lowbit (i)) {
        ret = max (ret , s[i]);
    }
    return ret;
}
int main () {
    int t , cas = 0;
    scanf ("%d" , &t);
    while (t --) {
        memset (food , 0 , sizeof(food));
        memset (prod , 0 , sizeof(prod));
        memset (s , 0 , sizeof(s));
        scanf ("%d %d %d %d" , &n , &m , &r , &q);
        for (int i = 1 ; i <= n ; i ++) {
            for (int j = 1 ; j <= m ; j ++) {
                scanf ("%d" , &food[i][j]);
                food[i][j] += food[i - 1][j] + food[i][j - 1] - food[i - 1][j - 1];
            }
        }
        for (int i = 1 ; i <= n ; i ++) {
            for (int j = 1 ; j <= m ; j ++) {
                scanf ("%d" , &prod[i][j]);
                prod[i][j] += prod[i - 1][j] + prod[i][j - 1] - prod[i - 1][j - 1];
            }
        }
        tot = 0;
        r = 2 * r + 1;
        for (int i = r ; i <= n ; i ++) {
            for (int j = r ; j <= m ; j ++) {
                a[tot] = food[i][j] - food[i][j - r] - food[i - r][j] + food[i - r][j - r];
                b[tot] = prod[i][j] - prod[i][j - r] - prod[i - r][j] + prod[i - r][j - r];
                x[tot] = a[tot];
                tot ++;
            }
        }
        sort (x , x + tot);
        cnt = unique (x , x + tot) - x;
        for (int i = 0 ; i < tot ; i ++) {
            int y = cnt - (lower_bound (x , x + cnt , a[i]) - x);
            add (y , b[i]);
        }
        printf ("Case #%d:\n" , ++ cas);
        while (q --) {
            int A , B;
            scanf ("%d %d" , &A , &B);
            int low = min (A , B) + r * r * 1 , high = min (A , B) + r * r * 3 , mid , ans;
            while (low <= high) {
                mid = (low + high) >> 1;
                int y = cnt - (lower_bound (x , x + cnt , mid - A) - x);
                if (y < 1) {
                    high = mid - 1;
                    continue;
                }
                int tmp = ask (y);
                if (tmp + B >= mid) {
                    ans = mid;
                    low = mid + 1;
                }
                else high = mid - 1;
            }
            printf ("%d\n" , ans);
        }
        if (t) puts ("");
    }
    return 0;
}
