#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <queue>
#include <algorithm>
#include <math.h>
using namespace std;
#define M 205
#define eps 1e-8
int equ, var;
double a[M][M], x[M];
int Gauss ()
{
    int i, j, k, col, max_r;
    for (k = 0, col = 0; k < equ && col < var; k++, col++)
    {
        max_r = k;
        for (i = k+1; i < equ; i++)
            if (fabs (a[i][col]) > fabs (a[max_r][col]))
                max_r = i;
        if (k != max_r)
        {
            for (j = col; j < var; j++)
                swap (a[k][j], a[max_r][j]);
            swap (x[k], x[max_r]);
        }
        x[k] /= a[k][col];
        for (j = col+1; j < var; j++) a[k][j] /= a[k][col];
        a[k][col] = 1;
        for (i = 0; i < equ; i++) if (i != k)
        {
            x[i] -= x[k] * a[i][k];
            for (j = col+1; j < var; j++) a[i][j] -= a[k][j] * a[i][col];
            a[i][col] = 0;
        }
    }
    return 1;
}
int has[M], vis[M], k, e, n, m;
double p[M], sum;
int bfs (int u)
{
    memset (has, -1, sizeof(has));
    memset (a, 0, sizeof(a));            
    memset (vis, 0, sizeof(vis));
    int v, i, flg = 0;
    queue<int> q;
    q.push (u);
    k = 0;
    has[u] = k++;
    while (!q.empty ())
    {
        u = q.front ();
        q.pop ();
        if (vis[u]) continue;
        vis[u] = 1;
        if (u == e || u == n-e)        
        {
            a[has[u]][has[u]] = 1;
            x[has[u]] = 0;
            flg = 1;
            continue;
        }
        a[has[u]][has[u]] = 1;
        x[has[u]] = sum;
        for (i = 1; i <= m; i++)
        {
            if (fabs (p[i]) < eps) continue;
            v = (u + i) % n;
            if (has[v] == -1) has[v] = k++;
            a[has[u]][has[v]] -= p[i];
            q.push (v);
        }
    }
    return flg;
}
int main()
{
    int t, s, d, i;
    scanf ("%d", &t);
    while (t--)
    {
        scanf ("%d%d%d%d%d", &n, &m, &e, &s, &d);
        n = 2*(n-1);
        sum = 0;
        for (i = 1; i <= m; i++)
        {
            scanf ("%lf", p+i);
            p[i] = p[i] / 100;
            sum += p[i] * i;
        }
        if (s == e)
        {
            puts ("0.00");
            continue;
        }
        if (d > 0) s = (n - s) % n;
        if (!bfs (s))
        {
            puts ("Impossible !");
            continue;
        }
        equ = var = k;
        Gauss ();
        printf ("%.2f\n", x[has[s]]);
    }
    return 0;
}
