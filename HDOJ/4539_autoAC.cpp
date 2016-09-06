#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;
int N, M, idx;
int sta[175], num[175];
int cnt[15], mp[105];
int f[105][175][175];
void print(int x) {
    int rec[50] = {0}, p = 0;
    while (x) {
        rec[p++] = x % 2;
        x /= 2;
    }
    for (int i = 9; i >= 0; --i) {
        printf(i == 0 ? "%d\n" : "%d", rec[i]);
    }
}
inline bool legal(int x) {
    if (x & (x << 2)) return false;
    return true;
}
void init() {
    int lim;
    idx = 1;
    for (int k = 1; k <= 10; ++k) {
        lim = 1 << k;
        for (int i = 1<<(k-1); i < lim; ++i) {
            if (legal(i)) {
                sta[idx] = i;
                for (int j = 0; j < k; ++j) {
                    if (i & (1 << j)) ++num[idx];
                }
                idx++;
            }
        }
        cnt[k] = idx;
    }
}
inline bool place(int x, int y) {
    return (x & y) == x;
}
inline bool judge_1(int x, int y) { 
    if ((x << 1) & y || (x >> 1) & y) return false;
    return true;
}
inline bool judge_2(int x, int y) { 
    if (x & y) return false;
    return true;
}
int solve() {
    int ret = 0;
    memset(f, 0, sizeof (f));
    if (N == 1) {
        for (int i = 0; i < cnt[M]; ++i) {
            if (place(sta[i], mp[1])) {
                ret = max(ret, num[i]);
            }
        }
        return ret;
    }
    for (int i = 0; i < cnt[M]; ++i) {
        if (!place(sta[i], mp[2])) continue;
        for (int j = 0; j < cnt[M]; ++j) {
            if (!place(sta[j], mp[1])) continue;
            if (judge_1(sta[i], sta[j])) {
                f[2][i][j] = num[i] + num[j];
            }
        }
    }
    for (int i = 3; i <= N; ++i) {
        for (int j = 0; j < cnt[M]; ++j) {
            if (!place(sta[j], mp[i])) continue;
            for (int k = 0; k < cnt[M]; ++k) {
                if (!place(sta[k], mp[i-1]) || !judge_1(sta[j], sta[k])) continue;
                for (int h = 0; h < cnt[M]; ++h) {
                    if (!place(sta[h], mp[i-2]) || !judge_1(sta[k], sta[h])) continue;
                    if (judge_2(sta[j], sta[h])) {
                        f[i][j][k] = max(f[i][j][k], f[i-1][k][h] + num[j]);    
                    }
                }
            }
        }    
    }
    for (int i = 0; i < cnt[M]; ++i) {
        for (int j = 0; j < cnt[M]; ++j) {
            ret = max(ret, f[N][i][j]);
        }
    }
    return ret;
}
int main() {
    init();
    int c;
    while (scanf("%d %d", &N, &M) != EOF) {
        memset(mp, 0, sizeof (mp));
        for (int i = 1; i <= N; ++i) {
            for (int j = 1; j <= M; ++j) {
                scanf("%d", &c);
                mp[i] <<= 1;
                mp[i] |= c;
            }
        }
        printf("%d\n", solve());
    }
    return 0;    
}
