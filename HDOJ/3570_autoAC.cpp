#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <queue>
using namespace std;
const int MAXN = 210;
const int INFINITE = 0x3F3F3F3F ;
int dp[MAXN] , f0[MAXN][MAXN] , f1[MAXN][MAXN] , f2[MAXN][MAXN] , n , m , p ;
vector< pair<int , int> > e[MAXN] ;
int tot[MAXN] ;
void dfs(int u,int fa)
{
 tot[u] = 1 ;
 for (int i = 0 ; i < e[u].size() ; i++)
 {
 int v = e[u][i].first ;
 if (v == fa) continue ;
 dfs(v,u) ;
 tot[u] += tot[v] ;
 }
 f0[u][1] = f1[u][1] = f2[u][1] = 0 ;
 for (int i = 2 ; i <= tot[u] ; i++)
 f0[u][i] = f1[u][i] = f2[u][i] = INFINITE ;
 for (int i = 0 ; i < e[u].size() ; i++)
 {
 int v = e[u][i].first , w = e[u][i].second ;
 if (v == fa) continue ;
 for (int j = tot[u] ; j > 1 ; j--)
 {
 for (int k = 1 ; k < j && k <= tot[v] ; k++)
 {
 f2[u][j] = min(f2[u][j] , f2[u][j-k] + f2[v][k] + 2 * w) ;
 f1[u][j] = min(f1[u][j] , f2[u][j-k] + f1[v][k] + w) ;
 f1[u][j] = min(f1[u][j] , f1[u][j-k] + f2[v][k] + 2 * w) ;
 f0[u][j] = min(f0[u][j] , f1[u][j-k] + f1[v][k] + w) ;
 f0[u][j] = min(f0[u][j] , f2[u][j-k] + f0[v][k] + 2 * w) ;
 f0[u][j] = min(f0[u][j] , f0[u][j-k] + f2[v][k] + 2 * w) ;
 }
 }
 }
 for (int i = 1 ; i <= tot[u] ; i++)
 {
 dp[i] = min(dp[i] , f0[u][i]) ;
 dp[i] = min(dp[i] , f1[u][i]) ;
 dp[i] = min(dp[i] , f2[u][i]) ;
 }
}
int main()
{
 int T , cas=0 ;
 scanf("%d",&T);
 while (T--)
 {
 scanf("%d%d",&n,&p);
 for (int i = 1 ; i <= n ; i++)
 e[i].clear() ;
 for (int i = 1 ; i < n ; i++)
 {
 int u , v , w ;
 scanf("%d%d%d",&u,&v,&w);
 e[u].push_back(make_pair(v,w)) ;
 e[v].push_back(make_pair(u,w)) ;
 }
 for (int i = 1 ; i <= n ; i++)
 dp[i] = INFINITE ;
 dfs(1,-1) ;
 scanf("%d",&m);
 printf("Case %d:\n",++cas) ;
 while (m--)
 {
 int X ;
 scanf("%d",&X) ;
 int ans = 0 ;
 for (int i = 1 ; i <= n ; i++)
 {
 if (dp[i] + i*X > p) break ;
 ans = i ;
 }
 printf("%d\n",ans) ;
 }
 }
 return 0 ;
}
