#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define repf(i,a,b) for(int i=(a);i<=(b);i++)
typedef long long ll;
const int N = 4e4+10;
int a[N], rec[N<<1];
int n, m, pos, cnt;
ll ans;
int main() {
    while (~scanf("%d%d", &n, &m)) {
        memset(rec, 0, sizeof(rec));
        repf (i, 0, n - 1) {
            scanf("%d", &a[i]);
            if (a[i] == m) {
                pos = i;
            }
        }
        cnt = 0;
        for (int i = pos; i >= 0; i--) {
            if (a[i] > m) cnt++;
            if (a[i] < m) cnt--;
            rec[N + cnt]++;
        }
        cnt = 0;
        ans = 0;
        for (int i = pos; i < n; i++) {
            if (a[i] > m) cnt++;
            if (a[i] < m) cnt--;
            ans += rec[N - cnt];
        }
        cout << ans << endl;
    }
    return 0;
}
