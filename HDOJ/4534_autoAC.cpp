#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
const int N = 1605;
const int inf = 0x3f3f3f3f;
int n;
int sz;
char str[105];
int del[2][N][1<<8]; 
int sco[2][N][1<<8];
struct Ac_auto {
    int ch[N][26];
    int fail[N];
    int sta[N];
    int gain[N];
    char kill[N]; 
    int idx, root;
    int newnd() {
        memset(ch[idx], 0, sizeof (ch[idx]));
        gain[idx] = sta[idx] = fail[idx] = kill[idx] = 0;
        return idx++;
    }
    void init() {
        idx = 0, root = newnd();
    }
    void insert(char ss[], int val) {
        int len = strlen(ss);
        int p = root;
        for (int i = 0; i < len; ++i) {
            char c = ss[i]-'a';
            if (!ch[p][c]) ch[p][c] = newnd();
            p = ch[p][c];
        }
        if (val == 999) sta[p] = 1 << sz;
        else if (val == -999) kill[p] = 1;
        else gain[p] = val;
    }
    void build() { 
        queue<int>q;
        for (int i = 0; i < 26; ++i) {
            if (ch[root][i]) {
                q.push(ch[root][i]);
            }
        }
        while (!q.empty()) {
            int p = q.front();
            q.pop();
            for (int i = 0; i < 26; ++i) {
                int v = ch[p][i];
                int x = fail[p];
                if (v) {
                    q.push(v);
                    while (x && !ch[x][i]) x = fail[x]; 
                    fail[v] = ch[x][i]; 
                    kill[v] |= kill[fail[v]]; 
                    sta[v] |= sta[fail[v]]; 
                    gain[v] += gain[fail[v]];
                } else {
                    ch[p][i] = ch[x][i];
                }
            }
        }
    }
};
Ac_auto ac;
void solve() {
    memset(del, 0x3f, sizeof (del)); 
    memset(sco, 0x80, sizeof (sco)); 
    int cur = 0, nxt = 1;
    del[cur][0][0] = 0; 
    sco[cur][0][0] = 0; 
    int len = strlen(str);
    int lim = 1 << sz;
    const int &idx = ac.idx;
    for (int i = 0; i < len; ++i) { 
        int c = str[i]-'a';
        memset(del[nxt], 0x3f, sizeof (del[nxt]));
        memset(sco[nxt], 0x80, sizeof (sco[nxt]));
        for (int j = 0; j < idx; ++j) {
            for (int k = 0; k < lim; ++k) { 
                if (del[cur][j][k] == inf) continue; 
                if (del[nxt][j][k] > del[cur][j][k] + 1) {
                    del[nxt][j][k] = del[cur][j][k] + 1;
                    sco[nxt][j][k] = sco[cur][j][k];
                } else if (del[nxt][j][k] == del[cur][j][k] + 1) {
                    if (sco[nxt][j][k] < sco[cur][j][k]) {
                        sco[nxt][j][k] = sco[cur][j][k];
                    }
                }
                int np = ac.ch[j][c];
                if (ac.kill[np]) continue; 
                int gain = ac.gain[np];
                int nsta = k|ac.sta[np];
                if (del[nxt][np][nsta] > del[cur][j][k]) {
                    del[nxt][np][nsta] = del[cur][j][k];
                    sco[nxt][np][nsta] = sco[cur][j][k] + gain;
                } else if (del[nxt][np][nsta] == del[cur][j][k]) {
                    if (sco[nxt][np][nsta] < sco[cur][j][k] + gain) {
                        sco[nxt][np][nsta] = sco[cur][j][k] + gain;
                    }
                }
            }
        }
        swap(cur, nxt);
    }
    int xdel = inf, xsco;
    for (int i = 0; i < idx; ++i) {
        if (xdel > del[cur][i][lim-1]) {
            xdel = del[cur][i][lim-1];
            xsco = sco[cur][i][lim-1];
        } else if (xdel == del[cur][i][lim-1]) {
            xsco = max(xsco, sco[cur][i][lim-1]);
        }
    }
    if (xdel == inf) {
        puts("Banned");
    } else {
        printf("%d %d\n", xdel, xsco);
    }
}
int main() {
    int T, ca = 0;
    scanf("%d", &T);
    while (T--) {
        int val;
        sz = 0;
        ac.init();
        scanf("%d", &n);
        for (int i = 0; i < n; ++i) {
            scanf("%s %d", str, &val);
            ac.insert(str, val);
            if (val == 999) ++sz;
        }
        ac.build();
        scanf("%s", str);
        printf("Case %d: ", ++ca);
        solve();
    }
    return 0;
}
