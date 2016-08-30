#include<stdio.h>
#include<string.h>
#include<algorithm>
#define MAXD 3010
#define INF 0x3f3f3f3f
int N, P, f[MAXD][MAXD], K[MAXD][MAXD], A[MAXD], a[MAXD];
void init()
{
    int i;
    scanf("%d%d", &N, &P);
    for(i = 1; i <= N; i ++) scanf("%d", &a[i]);
    std::sort(a + 1, a + 1 + N);
    for(i = 1, A[0] = 0; i <= N; i ++) A[i] = A[i - 1] + a[i];
}
int getw(int x, int y)
{
    int t = x + y >> 1;
    return (t - x) * a[t] - A[t - 1] + A[x - 1] + A[y] - A[t] - (y - t) * a[t];
}
void solve()
{
    int i, j, k, p, t;
    for(i = 0; i <= N; i ++) K[i][i] = i, f[i][i] = 0;
    for(p = 1; p <= N - P; p ++)
    {
        for(i = 0; (j = i + p) <= N; i ++) f[i][j] = INF;
        for(i = 1; (j = i + p) <= N; i ++)
            for(k = K[i][j - 1]; k <= K[i + 1][j]; k ++)
                if(f[i][j] > (t = f[i - 1][k - 1] + getw(k, j)))
                    f[i][j] = t, K[i][j] = k;
    }
    printf("%d\n", f[P][N]);
}
int main()
{
    int t;
    scanf("%d", &t);
    while(t --)
    {
        init();
        if(P >= N) printf("0\n");
        else solve();    
    }
    return 0;    
}
