#include <iostream>
#include <cstdio>
#include <cstring>
#include <cassert>
#include <queue>
#include <vector>
#include <map>
#include <set>
#include <cmath>
#include <algorithm>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<(int)(b);++i)
#define rrep(i,b,a) for(int i=(b);i>=(int)(a);--i)
#define eps 1e-8
#define clr(a,x) memset(a,x,sizeof(a))
#define LL long long
const int maxn = 10000+5;
int p[maxn];
int find(int x)
{
    if (x == p[x]) return x;
    return p[x] = find(p[x]);
}
int u[maxn*4],v[maxn*4],c[maxn*4];
int id[maxn],tot;
double A[500][500];
int N,M,S,T;
void input()
{
    scanf("%d%d%d%d",&N,&M,&S,&T);
    rep(i,0,M)  scanf("%d%d%d",u+i,v+i,c+i);
}
void gauss(int n)
{
    int i , j , k , r;
    for(i=0; i < n; ++i) {
        r = i;
        for(j = i+1; j <= n; ++j)
        if (fabs(A[j][i]) > fabs(A[r][i])) r = j;
        if (r != i) for(j = 0; j <= n; ++j) swap(A[r][j],A[i][j]);
        for(j = i+1; j <= n; ++j) A[i][j] /= A[i][i];
        A[i][i] = 1.0;
        for(k = 0; k < n; ++k) {
            if (fabs(A[k][i]) < eps || i == k) continue;
            double f = A[k][i];
            for(j = 0; j <= n; ++j) A[k][j] -= f * A[i][j];
        }
    }
}
void solve()
{
    rep(i,1,N+1) p[i] = i;
    rep(i,0,M) if (c[i] == 0)
        p[find(u[i])] = find(p[v[i]]); 
    if (find(S) == find(T)) {
        printf("0.000000\n");
        return;
    }
    tot = 0;
    rep(i,1,N+1)
    if (find(i) == i) id[i] = tot++;
    rep(i,1,N+1)
    id[i] = id[find(i)];
    rep(i,0,tot) p[i] = i;
    rep(i,0,M) p[find(u[i])] = find(v[i]);
    if (find(S) != find(T)) {
        puts("inf");
        return;
    }
    clr(A,0);
    rep(i,0,M) {
        if (id[u[i]] == id[v[i]]) continue;
        int x = id[u[i]] , y = id[v[i]];
        ++A[x][x]; --A[x][y];
        ++A[y][y]; --A[y][x];
    }
    S = id[S]; T = id[T];
    A[S][tot] = 1.0; A[T][tot] = -1.0;
    A[tot-1][S]++;
    gauss(tot);
    printf("%.6lf\n",-A[T][tot] + A[S][tot] + eps);
}
int main()
{
    int T; cin >> T;
    while (T--) {
        input();
        solve();
    }
}
