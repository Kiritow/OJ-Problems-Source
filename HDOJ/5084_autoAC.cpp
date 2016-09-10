#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
__int64 dp[2200][2200];
__int64 num[2200];
bool mark[2200][2200];
int N, Q;
int main(){
    while( scanf( "%d", &N ) != EOF ){
        for( int i = 0; i <= 2 * N - 2; i++ ){
            scanf( "%I64d", &num[i] );
        }
        memset( mark, false, sizeof( mark ) );
        for( int i = 0; i <= N - 1; i++ ){
            for( int j = 2 * N - 2; j >= N - 1; j-- ){
                if( mark[i][j] )    continue;
                __int64 sum = 0;
                int t1 = i, t2 = j, t3 = N;
                while( t3-- ){
                    sum += num[t1++] * num[t2--];
                }
                dp[i][j] = sum;
                mark[i][j] = true;
                t1 = i + 1, t2 = j - 1;
                while( t1 <= N - 1 && t2 >= N - 1 ){
                    sum = sum - num[t1-1] * num[t2+1] + num[t1+N-1] * num[t2-N+1];
                    dp[t1][t2] = sum;
                    mark[t1][t2] = true;
                    t1++, t2--;
                }
            }
        }
        scanf( "%d", &Q );
        __int64 ans = 0, ans1 = 0;
        int r, c;
        while( Q-- ){
            scanf( "%d%d", &r, &c );
            ans1 = dp[N-1-(r+ans1)%N][N-1+(c+ans1)%N];
            ans += ans1;
        }
        printf( "%I64d\n", ans );
    }
    return 0;
}
