#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long LL;
const LL mod = 1000000007;
const int maxn = 100005;
int b[maxn],a[maxn];
int n,m;
LL cnt[maxn];
LL B[maxn];
int main() {
    int t;
    cin >> t;
    B[0] = 1;
    for (int i = 1;i < maxn;i++) B[i] = (B[i - 1] * 2) % mod;
    while (t--) {
        memset(cnt, 0, sizeof(cnt));
        cin >> n;
        for (int i = 0;i < n;i++) {
            scanf("%d", &a[i]);
            b[i] = a[i];
        }
        sort(b, b + n);
        m = unique(b, b + n) - b;
        LL ret = 0;
        for (int i = 0;i < n;i++) {
            int x = lower_bound(b, b + m, a[i]) - b;
            ret = ((ret - ((cnt[x] * (LL)a[i]) % mod * B[n - i - 1])%mod)%mod+mod)%mod;
            ret = (ret + B[n - 1] * (LL)a[i]) % mod;
            cnt[x] = (cnt[x] + B[i])%mod;
        }
        cout << ret << endl;
    }
    return 0;
}
