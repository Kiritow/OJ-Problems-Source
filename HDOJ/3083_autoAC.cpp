#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <ctime>
#include <iostream>
#include <algorithm>
#include <queue>
#include <set>
#include <map>
#include <stack>
#include <string>
#include <vector>
#include <deque>
#include <list>
#include <functional>
#include <numeric>
#include <cctype>
using namespace std;
const int MOD = 20091226;
typedef long long LL;
inline int getS(LL n) {
    LL mod = MOD * 6;
    LL ret = (n % mod) * ((n + 1) % mod);
    ret %= mod;
    ret *= (n + 2) % mod;
    ret %= mod;
    ret /= 6;
    return (int)ret;
}
inline int getX(LL n) {
    if(n <= 1) {
        return 0;
    }
    int mod = MOD * 24;
    LL ret = (n + 1) % mod;
    if(n % 2 == 1) {
        ret = (((2 * ret  - 3) * ret) % mod - 2) * ret;
    }else {
        ret = (n % mod) * ((n + 2) % mod);
        ret %= mod;
        ret *= (2 * n - 1) % mod;
    }
    ret %= mod;
    ret /= 24;
    return ret;
}
inline int getP(LL n) {
    if(n < 1) {
        return 0;
    }
    int mod = MOD * 8;
    LL ret = n % mod;
    ret = ((((ret * (ret + 1))% mod) * (ret + 2))% mod) * (ret + 3);
    ret %= mod;
    ret /= 8;
    return ret;
}
int main() {
    int n;
    LL t, d, p, s, x;
    while(scanf("%d", &n) == 1) {
        s = getS(n);
        x = getX(n);
        t = s + x;
        d = 3 * x;
        p = getP(n - 1);
        printf("Triangle: %d\n", t % MOD);
        printf("Diamond: %d\n", d % MOD);
        printf("Parallelogram: %d\n", p % MOD);
    }
    return 0;
}
