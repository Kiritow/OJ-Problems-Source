#include<cstdio>
#include<vector>
using namespace std;
typedef __int64 ll;
const ll maxn = 1e18;
ll n[20], x[20];
vector<ll> nn, xx;
int main()
{
    int i;
    long long N;
    n[0] = 7LL, x[0] = 1LL;
    nn.push_back(1LL), xx.push_back(1LL);
    for (i = 1;; ++i)
    {
        n[i] = 7LL * n[i - 1] + 48LL * x[i - 1];
        x[i] = n[i - 1] + 7LL * x[i - 1];
        if (n[i] < 0) break;
        if ((n[i] - 3) % 4 == 0) nn.push_back((n[i] - 3) / 4), xx.push_back(x[i]);
    }
    nn.push_back(maxn + 5);
    while (scanf("%I64d", &N), N)
    {
        for (i = 0; i < nn.size(); ++i)
        {
            if (N < nn[i])
            {
                printf("%I64d %I64d\n", nn[i - 1], xx[i - 1]);
                break;
            }
        }
    }
    return 0;
}
