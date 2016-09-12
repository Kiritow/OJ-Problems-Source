#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
typedef long long ll;
int main(void)  {      
    ll n, m, x, y;
    while (scanf ("%I64d%I64d%I64d%I64d", &n, &m, &x, &y) == 4) {
        if (n > m)  {
            swap (n, m);    swap (x, y);
        }
        if (x > n - x + 1)  {
            x = n - x + 1;
        }
        if (y > m - y + 1)  {
            y = m - y + 1;
        }
        ll hm = (m + 1) / 2, hn = (n + 1) / 2;
        ll ans = min (hm, hn);
        if (m == n) {
            if (m % 2 == 1) {
                if (x == hn && y == hm) ans--;
            }
        }
        else    {
            ll t = min (y, n - x);
            ans = max (ans, t);
            ans = min (ans, hm);
        }
        printf ("%I64d\n", ans);
    }
    return 0;
}
