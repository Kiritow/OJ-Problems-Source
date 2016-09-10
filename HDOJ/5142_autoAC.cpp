#include<cstring>
#include<cstdio>
#include<cmath>
int buf[40];
void go(int n) {
    int i, j = 0, res = 0;
    memset(buf, 0, sizeof(buf));
    do buf[j++] = n % 2; while (n /= 2);
    for (i = j - 1; ~i; i--) res += buf[i] * (int)pow(2, j - i - 1);
    printf("%d\n", res);
}
int main() {
    int t, n;
    scanf("%d", &t);
    while (t--) scanf("%d", &n), go(n);
    return 0;
}
