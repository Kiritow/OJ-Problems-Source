#include <iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
struct node {
    int a[35][35];
    int n, m;
    void rota() {
        int b[35][35];
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                b[j][n - i - 1] = a[i][j];
            }
        }
        swap(n, m);
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                a[i][j] = b[i][j];
    }
} p[4], s;
int a[35][35];
int n, m;
int ans;
node cur[5];
void gao(int now) {
    if (now == 4) {
        for (int i = 0; i < 3; ++i)
            if (cur[i].n != cur[i + 1].n || cur[i].m != cur[i + 1].m)
                return;
        int minn = 100000;
        for (int i = 0; i < cur[0].n; ++i) {
            for (int j = 0; j < cur[0].m; ++j) {
                int sum = 0;
                for (int k = 0; k < 4; ++k) {
                    sum += cur[k].a[i][j];
                }
                if (sum < minn)
                    minn = sum;
            }
        }
        if (minn > ans)
            ans = minn;
        return;
    }
    cur[now] = p[now];
    gao(now + 1);
    for (int i = 0; i < 4; ++i) {
        cur[now].rota();
        gao(now + 1);
    }
}
int main() {
    while (scanf("%d%d", &n, &m) != EOF) {
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                scanf("%d", &a[i][j]);
        ans = 0;
        if (n % 4 == 0) {
            for (int i = 0; i < 4; ++i) {
                for (int j = n / 4 * i; j < n / 4 * (i + 1); ++j) {
                    for (int k = 0; k < m; ++k) {
                        p[i].a[j % (n / 4)][k] = a[j][k];
                    }
                }
                p[i].n = n / 4;
                p[i].m = m;
            }
            gao(0);
        }
        if (m % 4 == 0) {
            for (int i = 0; i < 4; ++i) {
                for (int j = 0; j < n; ++j) {
                    for (int k = i * (m / 4); k < (i + 1) * m / 4; ++k) {
                        p[i].a[j][k % (m / 4)] = a[j][k];
                    }
                }
                p[i].n = n;
                p[i].m = m / 4;
            }
            gao(0);
        }
        if (n % 2 == 0 && m % 2 == 0) {
            for (int i = 0; i < 4; ++i) {
                for (int j = (i / 2) * n / 2; j < (i / 2 + 1) * n / 2; ++j) {
                    for (int k = (i % 2) * m / 2; k < (i % 2 + 1) * m / 2;
                            ++k) {
                        p[i].a[j % (n / 2)][k % (m / 2)] = a[j][k];
                    }
                }
                p[i].n = n / 2;
                p[i].m = m / 2;
            }
            gao(0);
        }
        s.n = n;
        s.m = m;
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                s.a[i][j] = a[i][j];
        if (n < m) {
            s.rota();
            swap(n, m);
        }
        if (3 * s.n == 4 * s.m && s.m % 3 == 0 && s.n % 4 == 0) {
            for (int i = 0; i < 3; ++i) {
                for (int j = 0; j < m; ++j) {
                    for (int k = i * m / 3; k < (i + 1) * m / 3; ++k) {
                        p[i].a[j][k % (m / 3)] = s.a[j][k];
                    }
                }
                p[i].n = m;
                p[i].m = m / 3;
            }
            for (int i = m; i < n; ++i)
                for (int j = 0; j < m; ++j)
                    p[3].a[i - m][j] = s.a[i][j];
            p[3].n = n - m;
            p[3].m = m;
            gao(0);
            for (int i = 0; i < 3; ++i) {
                for (int j = n - m; j < n; ++j) {
                    for (int k = i * m / 3; k < (i + 1) * m / 3; ++k) {
                        p[i].a[j - (n - m)][k % (m / 3)] = s.a[j][k];
                    }
                }
                p[i].n = m;
                p[i].m = m / 3;
            }
            for (int i = 0; i < n - m; ++i)
                for (int j = 0; j < m; ++j)
                    p[3].a[i][j] = s.a[i][j];
            p[3].n = n - m;
            p[3].m = m;
            gao(0);
        }
        if (s.n == 2 * s.m && s.m % 2 == 0) {
            for (int i = 0; i < n / 2; ++i)
                for (int j = 0; j < m / 2; ++j)
                    p[0].a[i][j] = s.a[i][j];
            p[0].n = s.n / 2;
            p[0].m = s.m / 2;
            for (int i = 0; i < n / 2; ++i)
                for (int j = m / 2; j < m; ++j)
                    p[1].a[i][j - m / 2] = s.a[i][j];
            p[1].n = s.n / 2;
            p[1].m = s.m / 2;
            for (int i = n / 2; i < n / 4 * 3; ++i)
                for (int j = 0; j < m; ++j)
                    p[2].a[i - n / 2][j] = s.a[i][j];
            p[2].n = s.n / 4;
            p[2].m = s.m;
            for (int i = n / 4 * 3; i < n; ++i)
                for (int j = 0; j < m; ++j)
                    p[3].a[i - n / 4 * 3][j] = s.a[i][j];
            p[3].n = n / 4;
            p[3].m = m;
            gao(0);
            for (int i = n / 4; i < n / 4 * 3; ++i)
                for (int j = 0; j < m / 2; ++j)
                    p[0].a[i - n / 4][j] = s.a[i][j];
            p[0].n = s.n / 2;
            p[0].m = s.m / 2;
            for (int i = n / 4; i < n / 4 * 3; ++i)
                for (int j = m / 2; j < m; ++j)
                    p[1].a[i - n / 4][j - m / 2] = s.a[i][j];
            p[1].n = s.n / 2;
            p[1].m = s.m / 2;
            for (int i = 0; i < n / 4; ++i)
                for (int j = 0; j < m; ++j)
                    p[2].a[i][j] = s.a[i][j];
            p[2].n = s.n / 4;
            p[2].m = s.m;
            for (int i = n / 4 * 3; i < n; ++i)
                for (int j = 0; j < m; ++j)
                    p[3].a[i - n / 4 * 3][j] = s.a[i][j];
            p[3].n = n / 4;
            p[3].m = m;
            gao(0);
            for (int i = n / 2; i < n; ++i)
                for (int j = 0; j < m / 2; ++j)
                    p[0].a[i - n / 2][j] = s.a[i][j];
            p[0].n = s.n / 2;
            p[0].m = s.m / 2;
            for (int i = n / 2; i < n; ++i)
                for (int j = m / 2; j < m; ++j)
                    p[1].a[i - n / 2][j - m / 2] = s.a[i][j];
            p[1].n = s.n / 2;
            p[1].m = s.m / 2;
            for (int i = 0; i < n / 4; ++i)
                for (int j = 0; j < m; ++j)
                    p[2].a[i][j] = s.a[i][j];
            p[2].n = s.n / 4;
            p[2].m = s.m;
            for (int i = n / 4; i < n / 2; ++i)
                for (int j = 0; j < m; ++j)
                    p[3].a[i - n / 4][j] = s.a[i][j];
            p[3].n = n / 4;
            p[3].m = m;
            gao(0);
        }
        printf("%d\n", ans);
    }
    return 0;
}
