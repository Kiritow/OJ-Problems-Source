#include<map>
#include<set>
#include<cmath>
#include<stack>
#include<queue>
#include<cstdio>
#include<cctype>
#include<vector>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<functional>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MX = 1e5 + 5;
double A[MX], B[MX];
int main() {
    int T, n; 
    scanf("%d", &T);
    while(T--) {
        scanf("%d", &n);
        for(int i = 1; i <= n; i++) {
            scanf("%lf", &A[i]);
        }
        for(int i = 1; i <= n; i++) {
            scanf("%lf", &B[i]);
        }
        double L = 0, R = 1000, m;
        for(int i = 1; i <= 40; i++) {
            m = (L + R) / 2;
            double s, sum1 = 0, sum2 = 0;
            for(int j = 1; j <= n; j++) {
                if(A[j] <= m) s = 0;
                else s = B[j] * B[j] * (A[j] - m) * (A[j] - m) * (A[j] - m) / (3.0 * A[j] * A[j]);
                sum1 += s;
                sum2 += B[j] * B[j] * A[j] / 3.0 - s;
            }
            if(sum1 < sum2) R = m;
            else L = m;
        }
        printf("%d\n", (int)m);
    }
    return 0;
}
