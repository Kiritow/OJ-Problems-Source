#include<cstdio>
#include<iostream>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<string>
#include<map>
#include<set>
#include<vector>
#include<queue>
#include<stack>
using namespace std;
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define red(i, a, b) for (int i = (a); i >= (b); --i)
#define clr( x , y ) memset(x,y,sizeof(x))
#define sqr(x) ((x) * (x))
#define mp make_pair
#define pb push_back
#define x first
#define y second
typedef long long lint;
#pragma comment(linker,"/STACK:102400000,102400000")
const int mm = 1000003;
const lint qq = 100000;
int n , m , q = 0 , d[100100] , s[100100] , mx[100100];
vector < int > a[100100];
lint f[1001000] , p[1001000];
bool v[100100];
pair < int , int > ans , as = mp( 100000000 , 100000000 );
void MX(pair < int , int > k) {
    if ( k.x > k.y ) swap( k.x , k.y );
    if ( k < ans ) ans = k;
}
int find(int t)
{
    int k = mm - 2 , s = 1;
    while ( k ) {
        if ( k & 1 ) s = (lint) s * t % mm;
        t = (lint) t * t % mm;
        k >>= 1;
    }
    return s;
}
void init()
{
    int x , y;
    rep(i,1,n) scanf("%d",&d[i]) , v[i] = 1 , a[i].clear();
    rep(i,2,n) {
        scanf("%d%d",&x,&y);
        a[x].pb( y );
        a[y].pb( x );
    }
    ans = as;
}
void fdfs(int t,int fa)
{
    s[t] = 1; mx[t] = 0;
    red(i,a[t].size()-1,0) if ( a[t][i] != fa && v[a[t][i]] ) {
        fdfs( a[t][i] , t );
        s[t] += s[a[t][i]];
        mx[t] = max( mx[t] , s[a[t][i]] );
    }
}
int froot(int t,int m)
{
    int x = t , y;
    mx[t] = max( mx[t] , m - s[t] );
    red(i,a[t].size()-1,0) if ( v[a[t][i]] && s[t] > s[a[t][i]] ) {
        y = froot( a[t][i] , m );
        if ( mx[y] < mx[x] ) x = y;
    }
    return x;
}
void dfs(int t,int fa,lint s,int k)
{
    s = s * d[t] % mm;
    if ( k ) {
        lint x = f[p[s]*m%mm] - q * qq;
        if ( x > 0 ) MX( mp( (int)x , t ) );
    } else {
        lint x = q * qq + t;
        if ( f[s] < q * qq || f[s] > x ) f[s] = x;
    }
    red(i,a[t].size()-1,0) if ( v[a[t][i]] && a[t][i] != fa ) dfs( a[t][i] , t , s , k );
}
void work()
{
    rep(i,1,n) while ( v[i] ) {
        fdfs( i , 0 );
        int x = froot( i , s[i] );
        v[x] = 0;
        q ++;
        f[d[x]] = q * qq + x;
        red(j,a[x].size()-1,0) if ( v[a[x][j]] ) {
            dfs( a[x][j] , x , 1 , 1 );
            dfs( a[x][j] , x , d[x] , 0 );
        }
    }
    if ( ans == as ) puts("No solution"); else printf("%d %d\n",ans.x,ans.y);
}
int main()
{
    rep(i,1,mm) p[i] = find( i );
    while ( cin >> n >> m ) {
        init();
        work();
    }
    return 0;
}
