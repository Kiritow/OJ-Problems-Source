#include<stdio.h>
#include<string.h>
#define MAXD 4
int N, M, a2;
struct Matrix
{
    int a[MAXD][MAXD];
    Matrix()
    {
        memset(a, 0, sizeof(a));
    }
};
Matrix multiply(Matrix &x, Matrix &y)
{
    int i, j, k;
    Matrix z;
    for(k = 0; k < 4; k ++)
        for(i = 0; i < 4; i ++)
            if(x.a[i][k])
            {
                for(j = 0; j < 4; j ++)
                    if(y.a[k][j])
                        z.a[i][j] = (z.a[i][j] + (long long)x.a[i][k] * y.a[k][j]) % M;
            }
    return z;
}
void powmod(Matrix &unit, Matrix &mat, int n)
{
    while(n)
    {
        if(n & 1)
            unit = multiply(mat, unit);
        n >>= 1;
        mat = multiply(mat, mat);
    }
}
void solve()
{
    Matrix mat, unit;
    unit.a[0][0] = unit.a[2][0] = 1, unit.a[1][0] = ((long long)a2 * a2) % M, unit.a[3][0] = a2;
    mat.a[0][0] = mat.a[0][1] = 1;
    mat.a[1][1] = (4ll * a2 * a2) % M, mat.a[1][2] = 1, mat.a[1][3] = ((-4ll * a2) % M + M) % M;
    mat.a[2][1] = 1;
    mat.a[3][1] = (2ll * a2) % M, mat.a[3][3] = M - 1;
    powmod(unit, mat, N - 1);
    printf("%d\n", unit.a[0][0]);
}
int main()
{
    int t;
    scanf("%d", &t);
    while(t --)
    {
        scanf("%d%d%d", &a2, &N, &M);
        solve();
    }
    return 0;
}
