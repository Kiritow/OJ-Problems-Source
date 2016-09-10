#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
#define LL _int64 
#define mod 10000007
int a[100010];
struct matrix
{
    LL m[3][3];
};
matrix mul(matrix x, matrix y)
{
    matrix temp;
    memset(temp.m, 0, sizeof(temp.m));
    int i, j, k;
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            if (x.m[i][j] == 0)
            {
                continue;
            }
            for (k = 0; k < 3; k++)
            {
                if (y.m[j][k] == 0)
                {
                    continue;
                }
                temp.m[i][k] = (temp.m[i][k] + (x.m[i][j] * y.m[j][k]) % mod) % mod;
            }
        }
    }
    return temp;
}
matrix quickpow(matrix a, int n)
{
    matrix res;
    int i;
    memset(res.m, 0, sizeof(res.m));
    for (i = 0; i < 3; i++)
    {
        res.m[i][i] = 1;
    }
    while (n)
    {
        if (n & 1)
        {
            res = mul(res,a);
        }
        n >>= 1;
        a = mul(a, a);
    }
    return res;
}
int main()
{
    int n, k;
    while ((scanf("%d%d", &n, &k)) != EOF)
    {
        LL sum = 0;
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &a[i]);
            sum += a[i];
        }
        sort(a, a + n);
        matrix ans;
        ans.m[0][0] = 1; ans.m[0][1] = 1; ans.m[0][2] = 1;
        ans.m[1][0] = 0; ans.m[1][1] = 1; ans.m[1][2] = 1;
        ans.m[2][0] = 0; ans.m[2][1] = 1; ans.m[2][2] = 0;
        ans = quickpow(ans, k);
        printf("%d\n", (ans.m[0][0] * sum + ans.m[0][1] * a[n - 1] + ans.m[0][2] * a[n - 2]) % mod);
    }
    return 0;
}
