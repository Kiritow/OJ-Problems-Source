#include <iostream>
#include <algorithm>
using namespace std;
int mp[210][210];
int m[210][210];
int set[410];
int N, M, f, sum, ans;
const int inf = 0x7f7f7f7f;
bool Find;
int vh[410];
int h[410];
int find( int x)
{
  return x == set[x] ? x : set[x] = find( set[x] );    
}
void init_flow( )
{
  memset(h, 0, sizeof(h));
  memset(vh, 0, sizeof(vh));     
}
void init( )
{
  for( int i = 0; i < 110; i++)
       set[i] = i;
  memset(mp, 0, sizeof(mp));
  memset(m, 0, sizeof(m));     
}
//婧0锛姹N + 1 
void make_graph(int mid)
{ 
  //婧瑰板濂崇
  memset(mp, 0, sizeof(mp)); 
  for( int i = 1; i <= N; i++)
  {
     mp[0][i] = mid;      
  }
  //风版
  for( int i = N + 1; i <= 2 * N; i++)
  {
     mp[i][2 * N + 1] = mid;     
  }
  for( int i = 1; i <= 2 * N; i++)
      for( int j = 1; j <= 2 * N; j++)
        mp[i][j] = m[i][j];
  //崇郴浠ヤ 
  for( int i = 1; i <= 2 * N; i++)
  {
      for( int j = 1; j <= 2 * N; j++)
      {
        if( set[i] == set[j])
        {
            for( int k = 1; k <= 2 * N; k++)
            {
              if ( mp[j][k] && k != i)
                 mp[i][k] = 1;     
            }   
        }   
      }    
  }
}
void dfs( int x )
{
   int hmin = 2 * N + 1, i;
   if( x == 2 * N + 1)
   {
      sum += ans;
      Find = true;
      return;   
   }
   for( i = 0; i <= 2 * N + 1; i++)
   {
      if( mp[x][i] > 0)
      {
        if( h[x] == h[i] + 1 )
        {
          if( mp[x][i] < ans )
              ans = mp[x][i];
          dfs( i );
          if( Find )
              break;
          if( h[0] >= 2 * N + 1 )
              return;    
        }
        if( h[i] < hmin )
            hmin = h[i];    
      }        
   }
   if( Find )
   {
     mp[x][i] -= ans;
     mp[i][x] += ans;    
   }
   else
   {
     vh[h[x]]--;
     if( vh[h[x]] == 0 )
         h[0] = 2 * N + 1;
     h[x] = hmin + 1;
     vh[h[x]]++;    
   }     
}
int sap( )
{
   sum = 0;
   init_flow( );
   vh[0] = 2 * N + 2;
   while( h[0] < 2 * N + 2 )
   {
     ans = inf;
     Find = false;
     dfs( 0 );          
   }
   return sum;     
}
int solve( )
{
  int l = 0, r = N, temp = 0;
  while( l <= r )
  {
     int mid = (l + r) / 2;
     make_graph(mid);
     if( sap( ) == mid * N )
     {
         temp = mid;
         l = mid + 1;    
     }
     else
         r = mid - 1;       
  }
  return temp;    
}
int main( )
{
  int T, a, b;
  cin>>T;   
  while( T-- )
  {
    cin>>N>>M>>f;
    init( );
    for( int i = 1; i <= M; i++)
    {
       cin>>a>>b;
       mp[a][b + N] = 1;
       m[a][b + N] = 1;
    }
    for( int i = 1; i <= f; i++)
    {
       cin>>a>>b;
       int x = find( a );
       int y = find( b );
       if( x != y )
           set[x] = y;
    }
    for( int i = 1; i <= N; i++)
    {
         set[i] = find( i );     
    }          
    printf("%d\n", solve( ));       
  }
  return 0;
}
