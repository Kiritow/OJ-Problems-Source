#include<stdio.h>
#include<math.h>
#include<string.h>
long long fib[50], ans[50];
int num, flag, sum, cnt;
int DFS(int n, int p) {
    if (n == 1) {
        flag = 1;
        return 1;
    }
    for (int i = p; i < cnt; i++) {
        if (n % ans[i] == 0 && DFS(n / ans[i], i)) {
            flag = 1;
            return 1;
        }
    }
    return 0;
}
int main() {
    fib[0] = 0;
    fib[1] = 1;
    for (int i = 2; i < 46; i++) {
        fib[i] = fib[i - 1] + fib[i - 2];
    }
    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &num);
        flag = cnt = 0;
        if (num == 0) {
            printf("Yes\n");
            continue;
        }
        for (int i = 3; fib[i] <= num; i++) {
            if (num == fib[i]) {
                flag = 1;
                break;
            }
            if (num % fib[i] == 0) {
                ans[cnt++] = fib[i];
            }
        }
        if (!flag) DFS(num, 0);
        if (flag) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}
