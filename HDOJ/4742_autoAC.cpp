#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <set>
#include <map>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#define lowbit(x) (x & (-x))
#define mp(a,b) make_pair (a , b)
#pragma comment(linker, "/STACK:1024000000,1024000000")    
using namespace std;
typedef long long LL;
const int N = 100005;
typedef pair<int , int> pii;
struct Node {
    int x , y , z , id;
    void input () {
        scanf ("%d %d %d" , &x , &y, &z);
    }
    bool operator < (const Node &n) const {
        return x != n.x ? x < n.x : (y != n.y ? y < n.y : z < n.z);
    }
}a[N] , b[N];
int x[N] , m , n;
pii dp[N] , bit[N];
void update (pii &a , pii b) {
    if (b.first > a.first) a = b;
    else if (b.first == a.first) a.second += b.second;
}
void init () {
    for (int i = 1 ; i <= m ; i ++)
        bit[i] = mp(0 , 0);
}
void add (int idx , pii val) {
    for (int i = idx ; i <= m ; i += lowbit (i))
        update (bit[i] , val);
}
pii ask (int idx) {
    pii ans = mp (0 , 0);
    for (int i = idx ; i > 0 ; i -= lowbit (i))
        update (ans , bit[i]);
    return ans;
}
void clear (int idx) {
    for (int i = idx ; i <= m ; i += lowbit (i))
        bit[i] = mp (0 , 0);
}
void gao (int l , int r) {
    if (l == r) return ;
    int mid = (l + r) >> 1;
    gao (l , mid);
    int cnt = 0;
    for (int i = l ; i <= r ; i ++) {
        b[cnt ++] = a[i];
        b[cnt - 1].x = 0;
    }
    sort (b , b + cnt);
    for (int i = 0 ; i < cnt ; i ++) {
        if (b[i].id <= mid) {
            add (b[i].z , dp[b[i].id]);
        }
        else {
            pii t = ask (b[i].z);
            t.first ++;
            update (dp[b[i].id] , t);
        }
    }
    for (int i = 0 ; i < cnt ; i ++)
        if (b[i].id <= mid)
            clear (b[i].z);
    gao (mid + 1 , r);
}
int main () {
    int t ;
    scanf ("%d" , &t);
    while (t --) {
        scanf ("%d" , &n);
        for (int i = 0 ; i < n ; i ++) {
            a[i].input ();
            x[i] = a[i].z;
            dp[i] = mp (1 , 1);
        }
        sort (x , x + n);
        m = unique (x , x + n) - x;
        for (int i = 0 ; i < n ; i ++)
            a[i].z = lower_bound (x , x + m , a[i].z) - x + 1;
        sort (a , a + n);
        for (int i = 0 ; i < n ; i ++)
            a[i].id = i;
        init ();
        gao (0 , n - 1);
        pii ans = mp (0 , 0);
        for (int i = 0 ; i < n ; i ++) {
            update (ans , dp[i]);
        }
        printf ("%d %d\n" , ans.first , ans.second);
    }
    return 0;
}
