#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define LL long long 
using namespace std;
LL n, p;
LL multi(LL a, LL b) {    
    LL ret = 0;
    while(b) {
        if(b & 1) ret = (ret + a) % p;
        a = (a + a) % p;
        b >>= 1;
    }
    return ret;
}
LL powmod(LL a, LL b) {    
    LL ret = 1;
    while(b) {
        if(b & 1) ret = multi(ret, a) % p;
        a = multi(a, a) % p;
        b >>= 1;
    }
    return ret;
}
int main() {
    while(cin >> n >> p) {
        if(p == 1) {
            cout << 0 << endl;
        } else if(n == 1) {
            cout << 1 << endl;
        } else {
            LL ans = powmod(2, n) - 2;
            if(ans < 0) ans += p;
            cout << ans << endl;
        }
    }
    return 0;
}
