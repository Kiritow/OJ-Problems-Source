#include <stdio.h>
#include <string.h>
#define maxn 32800
bool arr[maxn << 1];
int main() {
    int n, m, i, j, cnt, cas = 0;
    while(scanf("%d%d", &n, &m) == 2) {
        memset(arr, 0, sizeof(bool) * n * 2);
        for(i = j = 0; i < n; ++i) {
            cnt = 0;
            while(true) {
                if(arr[j] == false) {
                    if(++cnt == m) break;
                }
                if(++j == 2 * n) j = 0;
            }
            arr[j] = true;
        }
        for(i = 0; i < n * 2; ++i) {
            putchar(arr[i] ? 'B' : 'G');
            if((i + 1) % 50 == 0) putchar('\n');
        }
        putchar('\n'); putchar('\n');
    }
    return 0;
}
