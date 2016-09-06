#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;
int Maps[ 11 ][ 11 ];
int Cost[ 11 ];
int Inst[ 11 ][ 11 ];
int F[ 11 ][ 1025 ];
int Stat[ 11 ];
int Q[ 11 ][ 1025 ];
int main()
{
    int N,M;
    while ( cin >> N >> M && N ) {
        for ( int i = 1 ; i <= M ; ++ i )
            cin >> Cost[ i ];
        for ( int i = 1 ; i <= N ; ++ i )
        for ( int j = 1 ; j <= M ; ++ j )
            cin >> Inst[ i ][ j ];
        for ( int i = 1 ; i <= N ; ++ i )
        for ( int j = 1 ; j <= N ; ++ j )
            cin >> Maps[ i ][ j ];
        int V = (1<<N)-1;
        for ( int i = 0 ; i <= N ; ++ i )
        for ( int j = 0 ; j <= V ; ++ j )
            F[ i ][ j ] = -10000001;
        for ( int j = 0 ; j <= V ; ++ j )
            F[ 0 ][ j ] = 0;
        for ( int i = 1 ; i <= M ; ++ i ) 
        for ( int j = 0 ; j <= V ; ++ j ) {
            int temp = j;
            for ( int k = 1 ; k <= N ; ++ k ) {
                Stat[ k ] = temp%2;
                temp /= 2;
            }
            int Save = 0;
            for ( int k = 1 ; k <= N ; ++ k )
                if ( Stat[ k ] )
                    Save += Inst[ k ][ i ] - Cost[ i ];
            for ( int p = 1 ; p <= N ; ++ p )
            for ( int q = p+1 ; q <= N ; ++ q )
                if ( Stat[ p ] && Stat[ q ] )
                    Save += Maps[ p ][ q ];
            int count = 0;
            Q[ 0 ][ 0 ] = j;
            for ( int k = 1 ; k <= N ; ++ k )
                if ( !Stat[ k ] ) {
                    for ( int p = 0 ; p < (1<<count) ; ++ p ) {
                        int New = Q[ count ][ p ];
                        Q[ count+1 ][ p*2+0 ] = New;
                        Q[ count+1 ][ p*2+1 ] = New|(1<<(k-1));
                    }
                    ++ count;
                }
            int Min = -10000001;
            for ( int k = 0 ; k < (1<<count) ; ++ k ) {
                if ( Min < F[ i-1 ][ Q[ count ][ k ] ] )
                    Min = F[ i-1 ][ Q[ count ][ k ] ];
            }
            F[ i ][ j ] = Min+Save;
        }
        int Max = -10000001;
        for ( int i = 1 ; i <= M ; ++ i ) 
        for ( int j = 0 ; j <= V ; ++ j )
            if ( Max < F[ i ][ j ] )
                Max = F[ i ][ j ];
        if ( Max > 0 )
            cout << Max << endl;
        else
            cout << "STAY HOME" << endl;
    }
    return 0;
}
