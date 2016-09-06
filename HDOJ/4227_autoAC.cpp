#include <iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;
int a[13], p[13];
int sum, i, ans;
bool use[13];
void dfs(int k) {
    int i;
    if (k == 12) {
        ans++;
        return;
    }
    for (i = 0; i < 12; i++) {
        if (i > 0 && !use[i - 1] && p[k - 1] == a[i])
            continue;
        if (!use[i]) {
            p[k] = a[i];
            if (k == 3) {
                if (p[0] + p[1] + p[2] + p[3] != sum) {
                    continue;
                }
            }
            if (k == 6) {
                if (p[3] + p[4] + p[5] + p[6] != sum) {
                    continue;
                }
            }
            if (k == 8) {
                if (p[0] + p[8] + p[7] + p[6] != sum) {
                    continue;
                }
            }
            if (k == 10) {
                if (p[10] + p[1] + p[8] + p[9] != sum) {
                    continue;
                }
            }
            if (k == 11) {
                if (p[10] + p[2] + p[4] + p[11] != sum) {
                    continue;
                }
                if (p[9] + p[7] + p[5] + p[11] != sum) {
                    continue;
                }
            }
            use[i] = 1;
            dfs(k + 1);
            use[i] = 0;
        }
    }
}
int main() {
    while (1) {
        sum = 0;
        for (i = 0; i < 12; i++) {
            scanf("%d", &a[i]);
            sum += a[i];
        }
        sort(a, a + 12);
        if (!sum)
            break;
        if (sum % 3) {
            printf("0\n");
            continue;
        }
        ans = 0;
        sum /= 3;
        dfs(0);
        printf("%d\n", ans / 12);
    }
    return 0;
}
