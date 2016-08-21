#include <stdio.h>
#include <string.h>
#define N 110
#define eps 1e-8
char map[N][N];
double visit[N][N]; 
double deal ( int c, int n, int m ) {
 int i, j;
 double ans = 0;
 memset ( visit, 0, sizeof ( visit ) );
 visit[ 0 ][ c ] = 1;
 for ( i = 0 ; i < n - 1 ; ++i ) { 
  for ( j = 0 ; j < m ; ++j ) {
   if ( visit[ i ][ j ] > eps ) {
    if ( map[ i ][ j ] != '.' ) {
     ans += visit[ i ][ j ] * ( map[ i ][ j ] - '0' );
    }
    else {
     if ( map[ i + 1 ][ j ] != '*' ) { 
      visit[ i + 1 ][ j ] += visit[ i ][ j ];
     }
     else {
      if ( j > 0 ) { 
       visit[ i + 1 ][ j - 1 ] += visit[ i ][ j ] / 2;
      }
      if ( j < m - 1 ) {
       visit[ i + 1 ][ j + 1 ] += visit[ i ][ j ] / 2;
      }
     }
    }
   }
  }
 }
 for ( i = 0 ; i < m ; ++i ) {  if ( map[ n - 1 ][ i ] != '*' && map[ n - 1 ][ i ] != '.' ) {
   ans += visit[ n - 1 ][ i ] * ( map[ n - 1 ][ i ] - '0' );
  }
 }
 return ans;
}
int main () {
 int i, n, m, t;
 double ans, temp;
 scanf ( "%d", &t );
 while ( t-- ) {
  scanf ( "%d%d", &n, &m );
  getchar();
  for ( i = 0 ; i < n ; ++i ) {
   gets( map[ i ] );
   if ( map[ i ][ 0 ] == '\0' ) --i;
  }
  ans = 0;
  for ( i = 0 ; i < m ; ++i ) {
   if ( map[ 0 ][ i ] != '.' ) { 
    if ( map[ 0 ][ i ] == '*' ) temp = 0;
    else temp = map[ 0 ][ i ] - '0';
   }
   else temp = deal( i, n, m ); 
   if ( temp - ans > eps ) ans = temp;
  }
     printf ( "%.6lf\n", ans );
     }
     return 0;
}
