#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
#define N 1000020
int n, k, num[2], m, ans, sl, ssl;
int ss[N], s[N];
bool v[10002];
struct node {
    int pre, val, mod;
} q[N];
void bfs() {
    memset(v, false, sizeof(v));
    int l = 1, r = 1;
    for (int i=0; i<m; i++) if (num[i]) {
        q[r].pre = 0; q[r].mod = num[i] % n;
        q[r].val = num[i];
        if (q[r].mod == 0) { ans = r; break; }
        r++;
    }
    while (l < r && ans == -1) {
        for (int i=0; i<m; i++) {
            q[r].mod = (q[l].mod * k + num[i]) % n;
            if (!v[q[r].mod]) {
                v[q[r].mod] = true;
                q[r].pre = l;
                q[r].val = num[i];
                if (q[r].mod == 0) { ans = r; break; }
                r++;
            }
        }
        l++;
    }
}
int cmp() {
    if (sl < ssl) return -1;
    if (sl > ssl) return 1;
    for (int i=0; i<sl; i++) if (s[i] != ss[i]) return s[i]-ss[i];
    return 0;
}
void cpy() {
    ssl = sl;
    for (int i=0; i<sl; i++) ss[i] = s[i];
}
void get_s(int x) {
    if (x == 0) return ;
    get_s(q[x].pre); s[sl++] = q[x].val;
}
void print() {
    for (int i=0; i<ssl; i++) printf("%d", ss[i]);
    printf("\n");
}
int main() {
    while (scanf("%d%d", &n, &k) == 2) {
        ssl = 0;
        for (int i=1; i<k; i++) {
            num[0] = i, m = 1;
            ans = -1;
            bfs();
            if (ans != -1) {
                sl = 0; get_s(ans);
                if (cmp() < 0 || ssl == 0) cpy();
            }
        }
        if (ssl == 0) {
            for (int i=0; i<k; i++) for (int j=i+1; j<k; j++) {
                num[0] = i, num[1] = j; m = 2;
                ans = -1;
                bfs();
                if (ans != -1) {
                    sl = 0; get_s(ans);
                    if (cmp() < 0 || ssl == 0) cpy();
                }
            }
        }
        print();
    }
    return 0;
}
