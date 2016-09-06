#include <stdio.h>
#include <string.h>
#include <map>
#include <algorithm>
typedef __int64 LL ;
const LL Mod = 1000000007LL ;
const int m = (1 << 8) ;
const int mm = 70 ;
bool ok[m]  ;
int a[8] , N ;
int min[m] ;
struct Matrix{
    LL mat[mm][mm] ;
    void init(){
        memset( mat,  0 ,sizeof(mat) ) ;
    }
}M[31] , res ,mid ;
LL ans[mm] ;
bool is_ok(int s){
    if( s==0 )  return true ;
    if( s==m-1 )  return true ;
    int val[8] ;
    int i ;
    for(i=0;i<8;i++)
        if( s&a[i] )    val[i] = 1 ;
        else    val[i] = 0;
    i = 0 ;
    while( val[i] ) ++ i ;
    for(int ii=0;ii<8;ii++  ){
        if( val[ (ii+i)%8 ] == 0 )   continue ;
        if( ii+1<8 && val[ (ii+i+1)%8 ] ){
            ii ++ ;
        }
        else    return false ;
    }
    return true ;
}
int getmin( int n ){
    int val[8] ;
    for(int i=0;i<8;i++) {
        if( n&a[i] )    val[i] = 1 ;
        else    val[i] = 0 ;
    }
    int v = 0 ;
    int res = n ;
    for(int ii=0;ii<8;ii++)
        if( val[ (2+ii)%8 ] )   v |= a[ ii ]  ;
    if( res > v )   res = v ;
    v = 0 ;
    for(int ii=0;ii<8;ii++)
        if( val[ (4+ii)%8 ] )   v |= a[ ii ]  ;
    if( res > v )   res =v ;
    v = 0 ;
    for(int ii=0;ii<8;ii++)
        if( val[ (6+ii)%8 ] )   v |= a[ ii ]  ;
    if( res > v )   res =v ;
    return res ;
}
std::map<int , int> mp ;
bool vis[m + 10][m + 10]  ;
void deal(int sou , int to){
    int val[8]  ;
    for(int i=0;i<8;i++){
        if( to&a[i] )  val[i] = 1 ;
        else    val[i] = 0 ;
    }
    LL v1 , v2 ;
    v1 = sou ;
    for(int j=0; j<=6;j+=2 ){
        v2 = 0  ;
        for(int jj=0;jj<8;jj++){
            if( val[ (j+jj)%8 ] )  v2 |= a[jj]  ;
        }
        if( ( v1|v2 )==m-1 && ok[ v1&v2 ] && !vis[v1][v2] ){
            M[0].mat[ mp[ min[v1] ] ][ mp[ min[v2] ] ] ++ ;
            vis[v1][v2] = 1 ;
        }
    }
}
void build_matrix(){
    M[0].init() ;
    memset( vis , 0 , sizeof(vis) );
    std::map<int, int>::iterator it1 ,it2  ;
    for( it1 = mp.begin() ; it1!=mp.end() ; it1++ ){
        for( it2=mp.begin() ; it2!=mp.end() ; it2++ ){
            deal( it1->first , it2->first ) ;
        }
    }
    M[0].mat[mm-1][mm-1] = 2 ;
    for(int ii=1;ii<=30;ii++){
        for(int i=0;i<mm;i++){
                for(int j=0;j<mm;j++){
                    mid.mat[i][j] = 0 ;
                    for(int k=0;k<mm;k++){
                        mid.mat[i][j] = ( mid.mat[i][j] + M[ii-1].mat[i][k] * M[ii-1].mat[k][j] % Mod ) % Mod ;
                    }
                }
            }
        M[ii] = mid ;
    }
}
void init(){
    a[0] = 1 ;
    for(int i=1;i<8;i++)    a[i] = a[i-1]<<1 ;
    for(int i=0;i<m;i++)    min[i] = getmin(i)  ;
    for(int i=0;i<m;i++){
        ok[i] = is_ok( i ) ;
        mp[ min[i] ] = 1 ;
    }
    std::map<int,int>::iterator it = mp.begin() ;
    int ss = 0 ;
    for( it ; it != mp.end(); it ++ ){
        it->second = ss ++ ;
    }
    build_matrix() ;
}
void calc( int n ){
    memset( ans , 0 , sizeof(ans) )  ;
    int jj = 0 ;
    ans[ mm-1 ] = 1 ;
    LL CC[mm] ;
    while( n ){
        if( n&1 ){
            for(int i=0;i<mm;i++){
                CC[i] = 0;
                for(int j=0;j<mm;j++){
                    CC[i] = ( CC[i] + ans[j] * M[jj].mat[i][j]% Mod ) % Mod ;
                }
            }
            for(int i=0;i<mm;i++)  ans[i] = CC[i] ;
        }
        n >>= 1 ; jj ++ ;
    }
}
int main(){
    init() ;
    int T ;scanf("%d",&T) ;
    int cas = 0 ;
    while( T-- ){
        scanf("%d",&N) ;
        calc(N + 1) ;
        printf("Case %d: %I64d\n",++cas,ans[0] ) ;
    }
    return 0 ;
}
