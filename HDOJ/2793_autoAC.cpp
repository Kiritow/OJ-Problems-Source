#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
const __int64 MAX_N = 5;
const __int64 MOD = 1000000007;
__int64 N;
void multipy( __int64 a[MAX_N][MAX_N], __int64 b[MAX_N][MAX_N], __int64 c[MAX_N][MAX_N] ){
    for( __int64 i = 1; i <= 4; i++ ){
        for( __int64 j = 1; j <= 4; j++ ){
            c[i][j] = 0;
            for( __int64 k = 1; k <= 4; k++ ){
                c[i][j] = ( c[i][j] + a[i][k] * b[k][j] % MOD ) % MOD;
            }
        }
    }
}
void get_matrix_pow( __int64 a[MAX_N][MAX_N], __int64 n ){
    __int64 ans[MAX_N][MAX_N] = {0};
    __int64 temp[MAX_N][MAX_N];
    for( __int64 i = 1; i <= 4; i++ )   ans[i][i] = 1;
    while( n ){
        if( n % 2 == 1 ){
            multipy( ans, a, temp );
            memcpy( ans, temp, sizeof( __int64 ) * MAX_N * MAX_ );
        }
        multipy( a, a, temp );
        memcpy( a, temp, sizeof( __int64 ) * MAX_N * MAX_ );
        n /= 2;
    }
    memcpy( a, ans, sizeof( __int64 ) * MAX_N * MAX_ );
}
__int64 solve( __int64 n ){
    __int64 a[MAX_N][MAX_N] = {0};
    if( n < 0 ){
        return 0;
    }
    if( n == 0 ){
        return 1;
    }else if( n == 1 ){
        return 2;
    }
    a[1][1] = 0;a[1][2] = 1;a[1][3] = 0;a[1][4] = 0;
    a[2][1] = 0;a[2][2] = 0;a[2][3] = 1;a[2][4] = 0;
    a[3][1] = 1;a[3][2] = 1;a[3][3] = 1;a[3][4] = 0;
    a[4][1] = 0;a[4][2] = 0;a[4][3] = 1;a[4][4] = 1;
    get_matrix_pow( a, n - 1 );
    __int64 ans = 0;
    __int64 b[MAX_N];
    b[1] = b[2] = b[3] = 1;
    b[4] = 2;
    for( __int64 i = 1; i <= 4; i++ ){
        ans = ( ans + a[4][i] * b[i] % MOD ) % MOD;
    }
    return ans;
}
int main(){
    __int64 A, B;
    while( scanf( "%I64d%I64d", &A, &B ) != EOF ){
        printf( "%I64d\n", ( solve( B ) - solve( A - 1 ) + MOD ) % MOD );
    }
    return 0;
}
