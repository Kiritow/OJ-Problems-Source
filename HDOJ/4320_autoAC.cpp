#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long int Int64;
int p[1000005], rec[100005], cnt;
void getprime()
{
    int k;
    for (int i = 4; i <= 1000000; i += 2) {
        p[i] = 1;
    }
    for (int i = 3; i <= 1000; i += 2) {
        k = 2 * i;
        for (int j = i * i; j <= 1000000; j += k) {
            p[j] = 1;    
        }    
    }
    rec[1] = 2;
    cnt = 1;
    for (int i = 3; i <= 1000000; i += 2) {
        if (!p[i]) {
            rec[++cnt] = i;    
        }    
    }
}
int main()
{
    int T, LIM, flag, ca = 0;
    Int64 a, b;
    getprime();
    scanf("%d", &T);
    while (T--) {
        flag = 0;
        scanf("%I64d %I64d", &a, &b);
        LIM = (int)sqrt(double(a));
        for (int i = 1; rec[i] <= LIM; ++i) {
            if (a % rec[i] == 0) {
                if (b % rec[i] != 0) {
                    flag = 1;
                    break;
                }
                while (a % rec[i] == 0) {
                    a /= rec[i];    
                }
            }
        }
        if (a != 1 && b % a != 0) {
            flag = 1;    
        }
        printf("Case #%d: ", ++ca);
        printf(flag ? "NO\n" : "YES\n");
    }
    return 0;    
}
