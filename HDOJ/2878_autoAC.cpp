#include<stdio.h>
#include<string.h>
#include<algorithm>
#define MAXM 1010
#define MAXN 250010
#define MAXD 501010
#define INF 0x3f3f3f3f
int N, M, K, P, a[510], b[510], g[510][510];
int size, U[MAXD], D[MAXD], L[MAXD], R[MAXD], C[MAXD];
int S[MAXM], H[MAXN], ANS;
void read(int X, int *a, int c)
{
    int i, j, x, y, n;
    memset(a, 0, sizeof(int) * (N + 1));
    for(i = 0; i < X; i ++)
    {
        scanf("%d%d", &x, &y);
        if(x > y) std::swap(x, y);
        if(c) y += 2;
        for(j = x; j <= y; j ++) a[j] = 1;
    }
}
void prep(int n, int m)
{
    int i;
    for(i = 0; i <= m; i ++)
    {
        R[i] = i + 1, L[i + 1] = i;
        U[i] = D[i] = i, S[i] = 0;
    }
    R[m] = 0, size = m;
    for(i = 0; i <= n; i ++) H[i] = -1;
}
void insert(int r, int c)
{
    ++ size;
    C[size] = c, ++ S[c];
    D[size] = D[c], U[size] = c, U[D[c]] = size, D[c] = size;
    if(H[r] == -1) L[size] = R[size] = size, H[r] = size;
    else L[size] = H[r], R[size] = R[H[r]], L[R[H[r]]] = size, R[H[r]] = size;
}
void init()
{
    int i, j, k;
    scanf("%d%d", &N, &M);
    memset(g, 0, sizeof(g));
    for(i = 0; i < M; i ++)
    {
        scanf("%d", &K), read(K, a, 0);
        scanf("%d", &P), read(P, b, 1);
        for(j = 1; j <= N; j ++)
            if(a[j])
                for(k = 1; k <= N; k ++)
                    if(b[k]) g[j][k] = 1;
    }
    prep(N * N, N + N);
    for(i = 1; i <= N; i ++)
        for(j = 1; j <= N; j ++)
            if(g[i][j]) insert((i - 1) * N + j, i), insert((i - 1) * N + j, N + j);
}
void remove(int c)
{
    int i, j;
    R[L[c]] = R[c], L[R[c]] = L[c];
    for(i = D[c]; i != c; i = D[i])
        for(j = R[i]; j != i; j = R[j])
            U[D[j]] = U[j], D[U[j]] = D[j], -- S[C[j]];
}
void resume(int c)
{
    int i, j;
    for(i = U[c]; i != c; i = U[i])
        for(j = L[i]; j != i; j = L[j])
            U[D[j]] = j, D[U[j]] = j, ++ S[C[j]];
    R[L[c]] = c, L[R[c]] = c;
}
void dance()
{
    if(R[0] == 0)
    {
        ++ ANS;
        return ;
    }
    int i, j, t = INF, id;
    for(i = R[0]; i != 0; i = R[i])
        if(S[i] < t) t = S[i], id = i;
    remove(id);
    for(i = D[id]; i != id; i = D[i])
    {
        for(j = R[i]; j != i; j = R[j]) remove(C[j]);
        dance();
        if(ANS > 65535) return ;
        for(j = L[i]; j != i; j = L[j]) resume(C[j]);
    }
    resume(id);
}
void solve()
{
    ANS = 0;
    dance();
    if(ANS > 65535) printf("OVERFLOW!\n");
    else printf("%d\n", ANS);
}
int main()
{
    int t;
    scanf("%d", &t);
    while(t --)
    {
        init();
        solve();
    }
    return 0;
}
