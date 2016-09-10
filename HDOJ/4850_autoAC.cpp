#include <cstdio>
#include <cstring>
const int N = 20005;
int vis[N], vis2[N][30], on = 0;
char out[500005];
int getnext(int x, int a) {
    return x % (26 * 26) * 26 + a;
}
void init() {
    int now = 0;
    for (int i = 0; i < 3; i++)
    out[on++] = 'a';
    while (true) {
    int Min = 26, iv = 0;
    for (int i = 1; i < 26; i++) {
        if (vis2[now][i]) continue;
        int tmp = getnext(now, i);
        if (vis[tmp] < Min) {
        Min = vis[tmp];
        iv = i;
        }
    }
    int tmp = getnext(now, iv);
    if (vis[tmp] == 26) break;
    vis2[now][iv] = 1;
    now = tmp;
    vis[now]++;
    out[on++] = now % 26 + 'a';
    }
}
int n;
int main() {
    init();
    while (~scanf("%d", &n)) {
    if (n > 456979) printf("Impossible\n");
    else printf("%s\n", (out + 456979 - n));
    }
    return 0;
}
