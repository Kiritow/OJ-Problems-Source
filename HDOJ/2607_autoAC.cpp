#include <stdio.h>
#include <string.h>
#define maxn 100002
int X[maxn], Y[maxn], Z[maxn];
char buf[40];
int main() {
    // freopen("data.in", "r", stdin); 
    int i, id = 0, cnt = 0, ret = 0; // id璁板版涓℃, ret璁板缁缁
    while (gets(buf)) {
        if (*buf == NULL) {
            if (id)
                if (ret == 0) puts("None.");
                else {
                    while (id--) {
                        if (ret >= X[id] && ret <= Y[id] && (ret - X[id]) % Z[id] == 0)
                            ++cnt;
                    }
                    printf("%d %d\n", ret, cnt);
                }
            id = cnt = ret = 0;
            continue;
        }
        sscanf(buf, "%d%d%d", &X[id], &Y[id], &Z[id]);
        for (i = X[id]; i <= Y[id]; i += Z[id])
            ret ^= i;
        ++id;
    }
    if (id) 
        if (ret == 0) puts("None.");
        else {
            while (id--) {
                if (ret >= X[id] && ret <= Y[id] && (ret - X[id]) % Z[id] == 0)
                    ++cnt;
            }
            printf("%d %d\n", ret, cnt);
        }
    return 0;
}
