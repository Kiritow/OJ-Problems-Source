#include<stdio.h>
#include<assert.h>
#include<cstring>
#include<algorithm>
using namespace std;
#define maxm 210
#define maxn 5
double inf = 1e100;
double eps = 1e-5;
void pivot(int m,int n, double a[maxm][maxn], int B[maxm], int N[maxn], int r, int c){
    int i, j;
    swap(N[c], B[r]);
    a[r][c] = 1 / a[r][c];
    for(j = 0; j <= n; j++)
        if(j != c)
            a[r][j] *= a[r][c];
    for(i = 0; i <= m; i++)
        if(i != r){
            for(j = 0; j <= n; j++)
                if(j != c)
                    a[i][j] -= a[i][c] * a[r][j];
            a[i][c] = -a[i][c] * a[r][c];
        }
}
int feasible(int m, int n, double a[maxm][maxn],int B[maxm], int N[maxn]){
    int r, c, i;
    double p, v;
    while(1){
        for(p = inf, i = 0; i < m; i++)
            if(a[i][n] < p)
                p = a[r=i][n];
        if(p > -eps)
            return 1;
        for(p = 0, i = 0; i < n; i++)
            if(a[r][i] < p)
                p = a[r][c=i];
        if(p > -eps)
            return 0;
        p = a[r][n] / a[r][c];
        for(i = r + 1; i < m; i++)
            if(a[i][c] > eps){
                v = a[i][n] / a[i][c];
                if(v < p)
                    r = i, p = v;
            }
            pivot(m, n, a, B, N, r, c);
    }
}
int simplex(int m, int n, double a[maxm][maxn], double b[maxn], double &ret){
    int B[maxm], N[maxn], r, c, i;
    double p, v;
    for(i = 0; i <n; i++)
        N[i] = i;
    for(i = 0; i < m; i++)
        B[i] = n + i;
    if(!feasible(m, n, a, B, N))
        return 0;
    while(1){
        for(p = 0,i = 0; i < n; i++)
            if(a[m][i] > p)
                p = a[m][c=i];
        if(p < eps){
            for(i = 0; i < n; i++)
                if(N[i] < n)
                    b[N[i]] = 0;
            for(i = 0; i < m; i++)
                if(B[i] < n)
                    b[B[i]] = a[i][n];
            ret = -a[m][n];
            return 1;
        }
        for(p = inf, i = 0; i < m; i++)
            if(a[i][c] > eps){
                v = a[i][n] / a[i][c];
                if(v < p)
                    p= v, r = i;
            }
        if(p == inf)
            return -1;
        pivot(m, n, a, B, N, r, c);    
    }
}
double A[maxm][maxn], B[maxn];
int main()
{
    int n , ca = 1, L, R;
    while(scanf("%d", &n) != EOF){
        if(n == 0)
            break;
        scanf("%d%d", &L, &R);
        for(int i = 0; i < n; i++){
            int x, y, z, p;
            scanf("%d%d%d%d", &x, &y, &z, &p);
            A[2*i][0] = x;
            A[2*i][1] = y;
            A[2*i][2] = z;
            A[2*i][3] = p - L;
            A[2*i+1][0] = -x;
            A[2*i+1][1] = -y;
            A[2*i+1][2] = -z;
            A[2*i+1][3] = R - p;
        }
        A[2*n][0] = 1.0;
        A[2*n][1] = -1.0;
        A[2*n][2] = 0.0;
        A[2*n][3] = 0;
        A[2*n+1][0] = 0.0;
        A[2*n+1][1] = 1.0;
        A[2*n+1][2] = -1.0;
        A[2*n+1][3] = 0;
        A[2*n+2][0] = -1.0;
        A[2*n+2][1] = 0.0;
        A[2*n+2][2] = 0.0;
        A[2*n+2][3] = 0;
        scanf("%lf%lf%lf", &A[2*n+3][0], &A[2*n+3][1], &A[2*n+3][2]);
        A[2*n+3][3] = -R;
        double ret;
        int sta = simplex(2*n+3, 3, A, B, ret);
        printf("Case %d: ", ca++);
        if(sta == -1)
            printf("Too expensive!\n");
        else if(sta == 0)
            printf("Inconsistent data\n");
        else
            printf("%.4lf\n",ret);
    }
    return 0;
}
