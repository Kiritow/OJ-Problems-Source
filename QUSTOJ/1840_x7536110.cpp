#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const int P = 1e9+7;
const int maxn = 1e6+10;
ll f[maxn], r[maxn];
ll C(int n,int m){ return n < m? 0 : f[n]*r[n-m]%P*r[m]%P;}
ll lucas(int n,int m){
    if(n < m) return 0;
    if(!m||n == m) return 1;
    return C(n%P, m%P)*lucas(n/P, m/P)%P;
}
void init(){
    int i;
    for(r[0] = r[1] = f[0] = f[1] = 1, i = 2; i < maxn; i++){
        f[i] = f[i-1]*i%P, r[i] = -r[P%i]*(P/i)%P;
        while(r[i] < 0) r[i] += P;
    }
    for(i = 2; i < maxn; i++)
        r[i] = r[i]*r[i-1]%P;
}
ll solve(int n, int m, int k){//n个位置链选m个，间隔 >= k
    return C(n-(m-1)*k, m);
}
 
int main(){
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);
    init();
    int T; scanf("%d", &T);
    ll n, m, k;
    while(T--){
        scanf("%lld%lld%lld", &n, &m, &k);
        if(m == 1) printf("%lld\n", n);
        else if((k+1)*m > n) puts("0");
        else {
            ll ans = ( solve(n-2*k-1, m-1, k)*k%P + solve(n-k, m, k))%P;
            printf("%lld\n", ans);
        }
    }
}
/*
1张圆桌有n个不同的座位，你需要留出m个座位给学生安排座位。为了防止作弊，任意两个相邻学生坐的座位至少需要隔开k个空座位。
问：有几种不同的选择座位的方式？方案数可能很大，需要对1e9+7取模。
0 < m < n < 1e6, 0 < k < 1000, T <= 1000
input
2
4 2 6
5 2 1
output
0
5
第2组样例解释：
座位编号为1,2,3,4,5。
有2个宾客到来，中间隔1个座位。可以选择(1,3)(1,4)(2,4)(2,5)(3,5)这5种方式。
*/
