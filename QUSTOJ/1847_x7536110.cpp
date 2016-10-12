#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
namespace acm {
/// count primes between [1..n] (0< n <=1e9)
/// solution: dp
/// d(n, i) means that the number of value whose min prime number is bigger than i in [1..n]
/// d(n, i) = d(n, i-1) if number i is not a prime
/// d(n, i) = d(n, i-1) - d(n/i, i) + d(i, i-1) if number i is a prime
/// complex time: O(n^(3/4)), space: O(n^(1/2))
static const long long maxn = 1e6+11;
long long dp[maxn];
struct CountPrime {
    long long solve(long long n) {
        if (n < 2) {
            return 0;
        }
        dp[0] = 0;
        long long sqrtn = 1, length = 0;
        for (; sqrtn <= n / sqrtn; ++sqrtn) {
            dp[++length] = sqrtn - 1;
        }
        for (long long i = sqrtn - 1; i > 0; --i) {
            long long val = n / i;
            if (val != i) {
                dp[++length] = val - 1;
            }
        }
        for (long long i = 1; i < sqrtn; ++i) {
            if (dp[i] == dp[i-1]) {
                continue;
            }
            for (long long j=length; j>0; --j) {
                long long val = j < sqrtn ? j : n / (length - j + 1);
                if (i > val / i) {
                    break;
                }
                long long pre_statue_pos = val / i;
                if (pre_statue_pos >= sqrtn) {
                    pre_statue_pos = length - n / pre_statue_pos + 1;
                }
                dp[j] += dp[i-1] - dp[pre_statue_pos];
            }
        }
        return dp[length];
    }
};
} // namespace acm
int main()
{
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);
    acm::CountPrime cp;
    //printf("IIII\n");
    long long n;
    while (scanf ("%lld", &n) != EOF) {
        printf ("%lld\n", cp.solve(n));
    }
    return 0;
}
