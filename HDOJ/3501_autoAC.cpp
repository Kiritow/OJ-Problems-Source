#include<cstdio>
#include<cmath>
#include<cstring>
#include<queue>
#include<vector>
#include<ctime>
#include<functional>
#include<algorithm>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MX = 1e3 + 5;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;
LL eular(LL n) {
    LL ans = n;
    for(int i = 2; (LL)i * i <= n; i++) {
        if(n % i == 0) {
            ans -= ans / i;
            while(n % i == 0) n /= i;
        }
    }
    if(n > 1) ans -= ans / n;
    return ans;
}
int main() {
    LL n;
    while(~scanf("%I64dd", &n), n) {
        printf("%I64d\n", (n * (n - 1) / 2 - eular(n) * n / 2) % mod);
    }
}
