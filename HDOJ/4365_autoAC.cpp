#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cmath>
#include<queue>
#include<set>
#include<map>
#include<cstring>
#include<vector>
#include<string>
#define LL long long
#define MOD 100000007
using namespace std;
class Point
{
public:
     int x,y;
     bool operator == (const Point &tmp) const{
        return  (x==tmp.x && y==tmp.y);        
     }    
}p[2024];
int midx,midy;
bool cmp(const Point &a,const Point &b){
    if(a.x != b.x)
    return a.x < b.x;
    return a.y < b.y;
}
void Solve1( int x, int y , int cnt )
{
    if( x > midx) 
    {
        x = (midx<<1) - x;
    } 
    if( y > midy ) y = (midy<<1) - y;
    if( x > y ) swap( x ,y );
    p[cnt].x = x; p[cnt].y = y;
}
void Solve2( int x, int y , int  cnt )
{
    if( x > midx )
    {
        int d = x - midx - 1;
        x = midx - d;
    }
    if( y > midy )
    {
        int d = y - midy - 1;
        y = midy - d;
    }
    if( x > y ) swap( x , y );
    p[cnt].x = x ; p[cnt].y = y;    
}
LL Pow( LL k , LL a )
{
    LL ans = 1;
    while( k )    
    {
         if( k &1 ) ans = (ans*a)%MOD;
         a = (a*a)%MOD;
         k >>= 1;    
    }
    return ans;
}
int main(  )
{
    int n,m,k,x,y;
    while( scanf( "%d %d %d",&n,&m,&k )==3 )
    {
           midx =  (n+1) /2;midy = midx;
           for( int i = 0; i < m ; i ++ )
           {
                scanf( "%d %d",&x,&y );
                x += 1 ; y += 1;
                if( n & 1 ) Solve1( x ,y , i );
                else Solve2( x , y , i );
           }
           LL L = ( n + 1 )/2;
           LL ans = L*L/2  + (L + 1) /2;
           sort(p,p+m,cmp);           
           ans -= unique(p,p+m)-p;
           if( ans > 0 )
           {
           ans = Pow( ans , (LL)k );
           printf( "%I64d\n",ans ); 
           }
           else printf( "0\n" );    
    }
    return 0;
}
