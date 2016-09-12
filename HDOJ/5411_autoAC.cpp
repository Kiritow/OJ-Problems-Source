#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<cstdio>
#include<ctime>
#include<vector>
using namespace std;
const int base = 2015;
const int maxn = 100005;
int T, n, m, k, kk;
struct Matrix
{
    #define size 55
    int m[size][size];
    Matrix() { memset(m, 0, sizeof(m)); }
    void operator =(const Matrix&b) { memcpy(m, b.m, sizeof(m)); }
    Matrix operator *(const Matrix&b) {
        Matrix c;
        for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
        for (int k = 0; k < size; k++)
            c.m[i][k] = (c.m[i][k] + m[i][j] * b.m[j][k]) % base;
        return c;
    }
    Matrix get(int x)
    {
        Matrix a, b = *this;
        for (int f = 0; x; x >>= 1)
        {
            if (x & 1)
            if (f) a = a * b; else a = b, f = 1;
            b = b * b;
        }
        return a;
    }
};
int main()
{
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d%d", &n, &m);
        Matrix a, b;
        for (int i = 1; i <= n + 1; i++) a.m[i][n + 1] = 1;
        for (int i = 1; i <= n; i++)
        {
            scanf("%d", &k);
            for (int j = 1; j <= k; j++)
            {
                scanf("%d", &kk);
                a.m[i][kk] = 1;
            }
        }
        for (int i = 1; i <= n + 1; i++) b.m[1][i] = 1;
        a = a.get(m);    
        b = b * a;
        if (m == 1) printf("%d\n", n + 1);
        else printf("%d\n", b.m[1][n + 1]);
    }
    return 0;
}
