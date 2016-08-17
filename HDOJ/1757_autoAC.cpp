#include <stdio.h>
#include <string.h>
#define maxn 10
struct matrix{
    int ma[maxn][maxn];
    matrix(){memset( ma, 0, sizeof(ma) );}
};
int k, m;
matrix operator * (const matrix & a,const matrix & b){
    matrix t;
    for(int h = 0; h < maxn; h ++ ){
        for(int i = 0; i < maxn; i ++ ){
            for(int j = 0; j < maxn; j ++ ){
                t.ma[h][i] += a.ma[h][j] * b.ma[j][i] % m;
            }
            t.ma[h][i] %= m;
        }
    }
    return t;
}
matrix binary_multiply(int n,matrix a){
    matrix t;
    if( n == 1 )
        return a;
    if( n > 1 ){
        t = binary_multiply( n>>1, a );
        t = t * t;
    }
    if( n & 1 )
        t = t * a;
    return t;
}
int main(){
    int i;
    matrix a, t;
    while( ~scanf("%d%d", &k, &m ) ){
        for( i = 1; i < maxn; i ++ )
            a.ma[i][i-1] = 1;
        for( i = 0; i < maxn; i ++ )
            scanf("%d", &a.ma[0][i] );
        if( k < maxn )
            printf("%d\n", k % m );
        else{
            t = binary_multiply( k-9, a );
            for( k = i = 0; i < maxn; i ++ ){
                k += t.ma[0][i] * ( maxn - i - 1 );
                k %= m;
            }
            printf("%d\n", k );
        }
    }
    return 0;
}
