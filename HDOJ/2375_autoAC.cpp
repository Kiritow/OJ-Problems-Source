#include <iostream>
#include <algorithm>
using namespace std;
template <class T> 
void out(T x, int n){ for (int i = 0; i < n; ++i) cout << x[i] << ' '; cout << endl; }
template <class T> 
void out(T x, int n, int m){ for (int i = 0; i < n; ++i) out(x[i], m); cout << endl; }
#define OUT(x) (cout << #x << " = " << x << endl)
#define FOR(i, a, b) for(int i = (int)a; i < (int)b; ++i)
#define REP(i, b) FOR(i, 0, b)
#define FORD(i, a, b) for(int i = (int)a; i >= (int)b; --i)
#define MAXN 20
#define MAXX (1<<16)
#define Inf 1e20
#define IN(x, tmp) ((tmp>>x)&1)
double disCount[MAXN][MAXN];
double price[MAXN], area[MAXN];
double f[MAXX];
double ans;
int n, m;
void input(){
int t, xi;
double yi;
REP (i, n)
REP (j, n)
disCount[i][j] = 1.0;
REP (i, n)
{
scanf("%lf %lf %d", &price[i], &area[i], &t);
while (t--)
{
scanf("%d %lf", &xi, &yi);
disCount[i][xi-1] *= (100.0-yi)*0.01;
}
}
}
void solve(){
double area0;
m = 1<<n;
REP (i, m) f[i] = Inf;
ans = Inf;
f[0] = 0;
REP (tmp, m)
{
if (Inf == f[tmp]) continue;
area0 = 0;
REP (j, n)
{
if (IN(j, tmp))
{
area0 += area[j];
}
else
{
double cost = price[j];
REP (i, n)
{
if (IN(i, tmp)) cost *= disCount[i][j];
}
int temp = tmp | (1<<j);
cost += f[tmp];
if (f[temp] > cost)
{
f[temp] = cost;
}
}
}
if (tmp) ans = min(ans, f[tmp]/area0); 
}
printf("%.4lf\n", ans);
}
int main(){
while (EOF != scanf("%d", &n))
{ 
if (0 == n) break;
input();
solve();
}
return 0;
}
