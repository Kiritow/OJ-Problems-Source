#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <cmath>
using namespace std;
typedef long long LL;
template<class T> T sqr(T x) { return x * x;}
template<class T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a;}
int main() {
    LL n, m;
    while (cin >> n >> m) {
        LL bx = 1, by = 1;
        for (LL i = 1; i <= m; i++) {
            LL t = (int) sqrt((double) sqr(i) * n);
            for (int d = 0; d < 2; d++) {
                if (abs(sqr(t + d) * sqr(by) - n * sqr(by) * sqr(i)) < abs(sqr(bx) * sqr(i) - n * sqr(by) * sqr(i))) bx = t + d, by = i;
            }
        }
        LL GCD = gcd(bx, by);
        cout << bx / GCD << "/" << by / GCD << endl;
    }
    return 0;
}
