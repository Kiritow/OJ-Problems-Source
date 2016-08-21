#include <stdio.h> 
#include <stdlib.h> 
#include <math.h> 
#include <string.h> 
#include <ctype.h> 
#include <time.h> 
#include <iostream> 
#include <algorithm> 
#include <queue> 
#include <vector> 
#include <map> 
#include <set>
#include <stack>
#include <list>
#include <string>
using namespace std; 
#define INF 0x7F7F7F7F  
#define eps 1e-8 
typedef long long LL; 
typedef vector<int> VI;
typedef vector<string> VS;
typedef pair <int , int> PII;
#define PB push_back
#define MP make_pair
#define CL(a,b) memset ( a , b , sizeof ( a ) ) 
#define CLN(a,n,b) memset ( a , b , n * sizeof ( size ) ) 
#define FOR(a,b,i) for ( i = a ; i < b ; i++ ) 
#define REP(i,n) FOR ( 0 , n , i )
#define FORB(b,a,i) for ( i = b ; i > a ; i-- ) 
#define FORE(a,b,i) for ( i = a ; i <= b ; i++ ) 
#define FOREB(b,a,i) for ( i = b ; i >= a ; i-- ) 
#define COPY(a,b,lt,rt,i) for ( i = lt ; i <= rt ; i++ ) a[i] = b[i]; 
#define sqr(a,b) sqrt ( (double) (a) * (a) + (double) (b) * (b) ) 
template <class T> inline T INT_LEN( T v ) { int len = 1 ; while ( v /= 10 ) ++len; return len; } 
template <class T> inline double DIS ( T a , T b ) { return sqr ( a.x - b.x , a.y - b.y ); }
typedef struct {
    double x , y;
}tc;
tc w[2] , t[2];
double vw , vt , mn , mx;
bool input (){
    while ( ~scanf ( "%lf" , &w[0].x ) ){
        scanf ( "%lf%lf%lf%lf" , &w[0].y , &w[1].x , &w[1].y , &vw );
        scanf ( "%lf%lf%lf%lf%lf" , &t[0].x , &t[0].y , &t[1].x , &t[1].y , &vt );
        scanf ( "%lf%lf" , &mn , &mx );
        return true;
    }
    return false;
}
template < typename T >
double dot ( T a , T b , T c ){
    return ( b.x - a.x ) * ( c.x - a.x ) + ( b.y - a.y ) * ( c.y - a.y );
}
template < typename T >
double det ( T a , T b , T c ){
    return ( b.x - a.x ) * ( c.y - a.y ) - ( b.y - a.y ) * ( c.x - a.x );
}
double get_dis ( tc fro , tc to , tc o , double dx , double dy ){
    fro.x += dx , fro.y += dy;
    to.x += dx , to.y += dy;
    double dis1 = DIS ( o , fro );
    double dis2 = DIS ( o , to );
    double d = min ( dis1 , dis2 );
    double di = DIS ( fro , to );
    if ( di <= eps ){
        return d;
    }else if ( dot ( fro , o , to ) >= -eps && dot ( to , o , fro ) >= -eps ){
        return fabs ( det ( fro , to , o ) ) / di;
    }else {
        return d;
    }
}
double calc ( tc fro , tc to , tc o , double dx , double dy){
    int lt = 0 , rt = INF , mid;
    double dis1 , dis2;
    while ( lt <= rt ){
        mid = ( lt + rt ) >> 1;
        dis1 = get_dis ( fro , to , o , dx * mid , dy * mid );
        dis2 = get_dis ( fro , to , o , dx * -~mid , dy * -~mid );
        if ( dis1 <= dis2 + eps ) rt = ~-mid;
        else lt = -~mid;
    }
    return get_dis ( fro , to , o , dx * lt , dy * lt );
}
void solve (){
    tc tg , wg , p1 , p2;
    double L1 = DIS ( t[0] , t[1] ); 
    tg.x = ( t[1].x - t[0].x ) * vt / L1;
    tg.y = ( t[1].y - t[0].y ) * vt / L1;    
    double L2 = DIS ( w[0] , w[1] );
    wg.x = ( w[1].x - w[0].x ) * vw / L2;
    wg.y = ( w[1].y - w[0].y ) * vw / L2;
    double time = L1 / vt;
    p1.x = t[0].x + ( tg.x - wg.x ) * time;
    p1.y = t[0].y + ( tg.y - wg.y ) * time;   
    p2.x = p1.x + ( -tg.x - wg.x ) * time;
    p2.y = p1.y + ( -tg.y - wg.y ) * time;    
    double d1 = calc ( t[0] , p1 , w[0] , p2.x - t[0].x , p2.y - t[0].y );
    double d2 = calc ( p1 , p2 , w[0] , p2.x - t[0].x , p2.y - t[0].y );
    double d = min ( d1 , d2 );
    if ( d + eps < mn ) puts ( "Dangerous" );
    else if ( d - eps > mx ) puts ( "Miss" );
    else puts ( "Perfect" );
}
int main (void){
    while ( input () ){
        solve ();
    }
    return 0;
}
