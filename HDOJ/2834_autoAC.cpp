#include <stdio.h>
#include <string.h>
#define For(i, n) for(i=0; i<(n); i++)
const int N = 64;
double P[N][N];
double A[N][N];
int out[N];
int t;
double s[N];
int n, m;
double dp[N][N];
double dpx[N][N];
int pre[N][N];
int ppt[N];
void read()
{
 int i, j;
 For(i, n)
 scanf("%lf", &s[i]);
 For(i, n)
 For(j, n)
 scanf("%lf", &P[i][j]);
 For(i, n)
 For(j, m)
 scanf("%lf", &A[i][j]);
 For(i, n)
 {
 s[i] /= 100;
 For(j, n)
 P[i][j] /= 100, A[i][j] /= 100;
 }
 scanf("%d", &t);
 For(i, t)
 scanf("%d", &out[i]);
 For(i, t)
 out[i] -= 1;
}
void doit()
{
 memset(dpx, 0, sizeof(dpx));
 int i, j, k;
 double tmp;
 For(j, n)
 {
 dp[0][j] = s[j];
 dpx[0][j] = dp[0][j] * A[j][out[0]];
 }
 for (i = 1; i < t; i++)
 {
 For(j, n)
 {
 For(k, n)
 {
 tmp = dpx[i - 1][k] * P[k][j] * A[j][out[i]];
 if (tmp > dpx[i][j])
 {
 dpx[i][j] = tmp;
 dp[i][j] = dp[i - 1][k] * P[k][j];
 pre[i][j] = k;
 }
 }
 }
 }
}
void pt()
{
 int i;
 int tmp;
 double mx = 0;
 For(i, n)
 if (dpx[t - 1][i] > mx)
 {
 mx = dpx[t - 1][i];
 tmp = i;
 }
 ppt[t - 1] = tmp;
 for (i = n-1; i > 0; i--)
 {
 ppt[i - 1] = pre[i][tmp];
 tmp = ppt[i - 1];
 }
 For(i, t)
 {
 if (i)
 putchar(' ');
 printf("%d", ppt[i] + 1);
 }
 puts("");
}
int main()
{
 while (2 == scanf("%d %d", &n, &m))
 {
 read();
 doit();
 pt();
 }
 return 0;
}
