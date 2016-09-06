#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <queue>
#include <vector>
#define mp(a , b) make_pair(a , b)
using namespace std;
typedef long long LL;
const LL inf = 1000000000LL;
int a , b , l , r , k;
int pow (int a , int b) {
    int ret = 1;
    for (int i = 0 ; i < b ; i ++) {
        ret = ret * a;
        if (ret > inf || ret <= 0)
            return inf + 1;
    }
    return ret;
}
int gao (int c , int a , int b , int l , int r , int k) {
    if (c == 0) return l <= r;
    if (c == 1) {
        if (l > r) return 0;
        return max (0 , min(r , b) - max (l , a) + 1);
    }
    int down = max(a , l / pow(b , c - 1));
    int up = min (b , r / pow(a , c - 1));
    int ret = 0;
    for (int i = down ; i <= up ; i ++) {
        ret += gao (c - 1 , i , b , (l + i - 1) / i , r / i , k - ret);
        if (ret > k) return ret;  
    }
    return ret;
}
int ret , ans[50];
void fuck (int c , int a , int b , int l , int r , int k) {
    if (c == 0) return;
    if (c == 1) {
        int num = k + max(l , a) - 1;
        ret = ret * num;
        ans[c] = num;
        return ;
    }
    int down = max(a , l / pow(b , c - 1));
    int up = min (b , r / pow(a , c - 1));
    for (int i = down ; i <= up ; i ++) {
        int cnt = gao (c - 1 , i , b , (l + i - 1) / i , r / i , k);
        if (k > cnt) {
            k -= cnt;
            continue;
        }
        ret = ret * i;
        ans[c] = i;
        fuck (c - 1 , i , b , (l + i - 1) / i , r / i , k);
        return ;
    }
}
int main () {
    int t , cas = 0;
    scanf ("%d" , &t);
    while (t --) {
        bool ok = false;
        scanf ("%d %d %d %d %d" , &a , &b , &l , &r , &k);
        printf ("Case #%d: " , ++ cas);
        for (int i = 1 ; i <= 30 ; i ++) {
            int cnt = gao (i , a , b , l , r , k);
            if (k > cnt) {
                k -= cnt;
                continue;
            }
            ret = 1;
            fuck (i , a , b , l , r , k);
            printf ("%d\n" , ret);
            for (int j = i ; j >= 1 ; j --) {
                printf ("%d%c" , ans[j] , j == 1 ? '\n' : ' ');
            }
            ok = true;
            break;
        }
        if (!ok) puts("-1");
    }
    return 0;
}
