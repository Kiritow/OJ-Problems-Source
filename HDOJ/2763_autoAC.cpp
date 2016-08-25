#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int N = 21;
const int M = 20;
int ans[21][N] = {{1}};
int BigNumPow(int x[], int n);
int BigNumCopy(int x[], int y[]);
int BigNumMul(int x[], int y[]);
int BigNumAdd(int x[], int y[]);
int main()
{
    int n, t;
    int i, j;
    int BigNum[N], BigPow[N], BigStep[N], BigCycle[N], tem[N];
    memset(BigNum, 0, sizeof(BigNum));
    memset(BigPow, 0, sizeof(BigPow));
    memset(BigStep, 0, sizeof(BigStep));
    memset(BigCycle, 0, sizeof(BigCycle));
    BigNum[0] = 2;
    BigStep[0] = 6;
    BigStep[1] = 1;
    BigPow[0] = 1;
    BigCycle[0] = 4;
    for(i = 1; i < 20; ++i)
    {
        while(BigNum[i] == 0 || BigNum[i] > 2)
        {
            BigNumMul(BigNum, BigStep);
            BigNumAdd(BigPow, BigCycle);
        }
        BigNumCopy(ans[i], BigPow);
        BigNumPow(BigStep, 5);
        memset(tem, 0, sizeof(tem));
        for(j = 0; j < M; ++j)
        {
            tem[j] += BigCycle[j] * 5;
            if(tem[j] > 9)
            {
                tem[j + 1] += tem[j] / 10;
                tem[j] = tem[j] % 10;
            }
        }
        BigNumCopy(BigCycle, tem);
    }
    scanf("%d", &t);
    for(j = 1; j <= t; ++j)
    {
        scanf("%d", &n);
        printf("%d %d ", j, n);
        --n;
        i = M;
        while(ans[n][i] == 0)
            --i;
        while(i >= 0)
            printf("%d", ans[n][i--]);
        printf("\n");
    }
    return 0;
}
int BigNumPow(int x[], int n)
{
    int tmp[N];
    int res[N];
    BigNumCopy(tmp, x);
    memset(res, 0, sizeof(res));
    res[0] = 1;
    while(n > 0)
    {
        if(n & 1)
        {
            BigNumMul(res, tmp);
        }
        BigNumMul(tmp, tmp);
        n = n >> 1;
    }
    BigNumCopy(x, res);
    return 0;
}
int BigNumCopy(int x[], int y[])
{
    int i;
    for(i = 0; i < N; ++i)
        x[i] = y[i];
    return 0;
}
int BigNumMul(int x[], int y[])
{
    int i, j, k;
    int tem[N];
    int res[N];
    memset(res, 0, sizeof(res));
    for(i = 0; i < M; ++i)
    {
        memset(tem, 0, sizeof(tem));
        for(k = i, j = 0; k < M; ++j, ++k)
        {
            tem[k] += y[i] * x[j];
            tem[k + 1] += tem[k] / 10;
            tem[k] = tem[k] % 10;
        }
        BigNumAdd(res, tem);
    }
    BigNumCopy(x, res);
    return 0;
}
int BigNumAdd(int x[], int y[])
{
    int i;
    for(i = 0; i < M; ++i)
    {
        x[i] += y[i];
        if(x[i] > 9)
        {
            x[i] -= 10;
            ++x[i + 1];
        }
    }
    return 0;
}
