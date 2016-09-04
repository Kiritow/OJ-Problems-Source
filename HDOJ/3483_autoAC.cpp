#include <iostream>
#include <cstring>
using namespace std;
#define M 55
#define LL long long
#define FF(i, n) for(int i = 0; i < n; i++)
int ans[M], mod, C[M][M];
int ret[M][M], init[M][M];
void ini(int n, int x)
{
    memset(init, 0, sizeof(init));
    FF(i, n) FF(j, i+1)
        init[i][j] = (LL)x*C[i][j] % mod;
    FF(i, n) ans[i] = x;
    ans[n] = 0;
    init[n][n-1] = init[n][n] = 1;
}
void matmul(int a[][M], int b[][M], int n)
{
    int tp[M][M] = {0};
    FF(i, n) FF(k, n) if(a[i][k]) FF(j, n) if(b[k][j])
        tp[i][j] = (tp[i][j] + (LL)a[i][k]*b[k][j]) % mod;
    FF(i, n) FF(j, n) a[i][j] = tp[i][j];
}
void matmul(int a[], int b[][M], int n)
{
    int tp[M] = {0};
    FF(j, n) if(a[j]) FF(i, n) if(b[i][j])
        tp[i] = (tp[i] + (LL)a[j]*b[i][j]) % mod;
    FF(i, n) a[i] = tp[i];
}
void qmod(int n, int b)
{
    FF(i, n) FF(j, n) ret[i][j] = (i==j);
    for( ; b; b >>= 1)
    {
        if (b & 1) matmul(ret, init, n);
        matmul(init, init, n);
    }
}
int main()
{
    int i, j, n, x;
    while (cin >> n >> x >> mod, n >= 1)
    {
        for(i = 0; i <= x; i++)
            C[i][0] = C[i][i] = 1;
        for(i = 2; i <= x; i++)
            for(j = 1; j < i; j++)
                C[i][j] = ((LL)C[i-1][j-1]+C[i-1][j]) % mod;
        ini(x+1, x);
        qmod(x+2, n);
        matmul(ans, ret, x+2);
        cout << ans[x+1] << endl;
    }
    return 0;
}
