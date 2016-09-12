#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define LL long long
#define N 50007
LL c[N], s[N];
void init() {
    for (LL i = 1; i < N; ++i)
        c[i] = i * (i - 1) >> 1;
}
inline int read() {
    int ret = 0;
    char ch = getchar();
    while (!('0' <= ch && ch <= '9'))
        ch = getchar();
    while ('0' <= ch && ch <= '9') {
        ret = ret * 10 + ch - '0';
        ch = getchar();
    }
    return ret;
}
int main() {
    init();
    int T = read();
    int n, i;
    LL sum;
    bool flag;
    while (T--) {
        n = read();
        for (i = 0; i < n; ++i)
            s[i] = read();
        sort(s, s + n);
        sum = 0;
        flag = true;
        for (i = 1; i <= n; ++i) {
            sum = sum + s[i - 1];
            if (sum < c[i]) {
                flag = false;
                break;
            }
        }
        if (sum != c[n])
            flag = false;
        if (flag)
            puts("It seems to have no problem.");
        else
            puts("The data have been tampered with!");
    }
    return 0;
}
