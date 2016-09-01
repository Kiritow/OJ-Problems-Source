#include <utility>
#include <algorithm>
#include <string>
#include <cstring>
#include <cstdio>
#include <iostream>
#include <iomanip>
#include <set>
#include <vector>
#include <cmath>
#include <queue>
#include <bitset>
#include <map>
#include <iterator>
using namespace std;
#define clr(a,v) memset(a,v,sizeof(a))
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
const int INF = 0x7f7f7f7f;
const int maxn = 211111;
const double pi = acos(-1.0);
const double eps = 1e-10;
const int mod = 1000000007;
typedef long long LL;
typedef pair<int, int> pii;
typedef vector<LL> VI;
typedef vector<VI> VVI;
typedef vector<VVI> VVVI;
VVI E, I, A;
int size;
LL f[20][20];
LL P[20];
LL num[20][20];
LL arr[20];
int convert(char *s) {
    if (strcmp(s, "Monday") == 0)
        return 1;
    if (strcmp(s, "Tuesday") == 0)
        return 2;
    if (strcmp(s, "Wednesday") == 0)
        return 3;
    if (strcmp(s, "Thursday") == 0)
        return 4;
    if (strcmp(s, "Friday") == 0)
        return 5;
    if (strcmp(s, "Saturday") == 0)
        return 6;
    if (strcmp(s, "Sunday") == 0)
        return 7;
    return -1;
}
LL POW(LL a, LL b) {
    LL res = 1;
    while (b) {
        if (b & 1)
            res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}
VVI multi(const VVI& A, const VVI& B) {
    VVI res = VVI(size, VI(size, 0));
    int i, j, k;
    for (i = 0; i < size; ++i) {
        for (j = 0; j < size; ++j) {
            for (k = 0; k < size; ++k) {
                res[i][j] += A[i][k] * B[k][j];
                if (res[i][j] >= mod)
                    res[i][j] %= mod;
            }
        }
    }
    return res;
}
VVI cal(const VVI& A, LL k) {
    VVI res = E, t = A;
    while (k) {
        if (k & 1)
            res = multi(res, t);
        t = multi(t, t);
        k >>= 1;
    }
    return res;
}
void output(const VVI &arr) {
    for (int i = 0; i < size; ++i) {
        cout.width(5);
        for (int j = 0; j < size; ++j) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}
LL go(int n, int k, int s) {
    size = k + 2;
    int i, j, t;
    int a = (7 - s % 7) % 7, b = (8 - s % 7) % 7;
    LL ans = 0;
    if (n <= 7) {
        for (i = 1; i <= n; ++i) {
            t = i % 7;
            if (t == a || t == b)
                continue;
            ans += POW(i, k);
            ans = ans >= mod ? ans % mod : ans;
        }
        return ans;
    }
    E = VVI(size, VI(size, 0));
    for (i = 0; i < size; ++i)
        E[i][i] = 1;
    I = VVI(size, VI(size, 0));
    I[0][0] = 1;
    for (i = 1; i < size; ++i)
        I[0][i] = f[k][i - 1] * P[i - 1] % mod;
    for (i = 1; i < size; ++i) {
        for (j = i; j < size; ++j) {
            I[i][j] = f[k + 1 - i][j - i] * P[j - i] % mod;
        }
    }
    LL p = n / 7, tmp;
    VVI res = E, ta, tb;
    int r = n % 7;
    ta = cal(I, p - 1);
    tb = multi(ta, I);
    for (i = 1; i <= 7; ++i) {
        if (i % 7 == a || i % 7 == b)
            continue;
        arr[0] = num[i][k];
        tmp = 0;
        for (j = 1; j < size; ++j)
            arr[j] = num[i][k + 1 - j];
        if (i <= r) {
            for (j = 0; j < size; ++j) {
                tmp += tb[0][j] * arr[j];
                tmp %= mod;
            }
        } else {
            for (j = 0; j < size; ++j) {
                tmp += ta[0][j] * arr[j];
                tmp %= mod;
            }
        }
        ans += tmp;
        ans %= mod;
    }
    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    char s[14];
    int n, k, i, j;
    P[0] = 1;
    for (i = 1; i < 20; ++i)
        P[i] = P[i - 1] * 7 % mod;
    for (i = 0; i < 20; ++i)
        f[i][0] = f[i][i] = 1;
    for (i = 1; i < 20; ++i) {
        for (j = 1; j < i; ++j) {
            f[i][j] = f[i - 1][j - 1] + f[i - 1][j];
            f[i][j] %= mod;
        }
    }
    for (i = 0; i < 20; ++i)
        num[i][0] = 1;
    for (i = 1; i < 20; ++i) {
        for (j = 1; j < 20; ++j) {
            num[i][j] = num[i][j - 1] * i % mod;
        }
    }
    int T, cas;
    scanf("%d", &T);
    for (cas = 1; cas <= T; ++cas) {
        scanf("%s", s);
        scanf("%d%d", &n, &k);
        printf("Case %d: %I64d\n", cas, go(n, k, convert(s)));
    }
    return 0;
}
