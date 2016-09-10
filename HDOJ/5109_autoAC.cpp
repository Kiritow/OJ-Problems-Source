#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<map>
#include<set>
#include<vector>
#include<queue>
#include<cstdlib>
#include<ctime>
#include<cmath>
using namespace std;
typedef long long LL;
int a;
LL s, b, t;
char str[10];
int main() {
    while (~scanf("%d%s", &a, str)) {
        int len = strlen(str);
        if (len == 1 && str[0] == '0') {
            puts("0");
            continue;
        }
        b = -1;
        LL base = 1;
        for (int i = 1; i <= len; i++)
            base *= 10;
        sscanf(str, "%I64d", &s);
        for (int i = 1; i <= 10000; i *= 10) {
            for (int j = (str[0] == '0'); j < a; j++) {
                t = ((LL) (j) * base + s) * i;
                int mod = (a - t % a) % a;
                if (mod < i) {
                    t += mod;
                    if (b < 0 || t < b)
                        b = t;
                }
            }
        }
        printf("%I64d\n", b / a);
    }
    return 0;
}
