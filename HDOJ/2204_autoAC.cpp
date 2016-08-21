#include<cstdio>
#include<cstring>
#include<cmath>
#include<vector>
#define EPS 1e-8
#define MAXN 65
typedef long long LL;
using namespace std;
bool p[MAXN];
vector<int> prime;
void Init() {
    int i, j;
    memset(p, true, sizeof(p));
    for (i = 2; i < 9; i++) {
        if (p[i]) {
            for (j = i * i; j < MAXN; j += i)
                p[j] = false;
        }
    }
    prime.clear();
    for (i = 2; i < MAXN; i++) {
        if (p[i])
            prime.push_back(i);
    }
}
int main() {
    LL n, tmp;
    int i, j, k, ans;
    Init();
    while (~scanf("%I64d", &n)) {
        ans = 1;
        for (i = 0; i < (int) prime.size(); i++) {
            tmp = (LL) (pow((double) n, 1.0 / prime[i]) + EPS);
            if (tmp == 1)
                break;
            ans += tmp - 1;
        }
        for (i = 0; i < (int) prime.size(); i++) {
            for (j = i + 1; j < (int) prime.size(); j++) {
                tmp = (LL) (pow((double) n, 1.0 / (prime[i] * prime[j])) + EPS);
                if (tmp == 1)
                    break;
                ans -= tmp - 1;
            }
        }
        for (i = 0; i < (int) prime.size(); i++) {
            for (j = i + 1; j < (int) prime.size(); j++) {
                for (k = j + 1; k < (int) prime.size(); k++) {
                    tmp = (LL) (pow((double) n,
                            1.0 / (prime[i] * prime[j] * prime[k])) + EPS);
                    if (tmp == 1)
                        break;
                    ans += tmp - 1;
                }
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
