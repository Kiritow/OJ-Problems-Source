#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int p[1000000] ;
char pr[1000000] ;
int len, pnum, num[14] ;
void prime( )
{
    int i, j ;
    for( i=2; i<1000000; ++i ){
        pr[i] = 1 ;
    }
    for( i=2,pnum=0; i<1000000; ++i ){
        if( pr[i] ){
            p[pnum++] = i ;
            for( j=i+i; j<1000000; j+=i )
                pr[j] = 0 ;
        }
    }
}
int mod( int n )
{
    __int64 m=0 ;
    int i ;
    for( i=len-1; i>=0; --i ){
        m = ( m*100000000+num[i] ) % n ;
    }
    return m ;
}
int main()
{
    char a[111] ;
    int i, j, div, flag ;
    prime( ) ;
    while( scanf("%s%d", a, &div ) && div && a[0]!='0' ){
        len = strlen( a ) ;
        for( i=0; i<14; ++i )
            num[i] = 0 ;
        for( i=0; i<len; ++i ){
            j = (len+7-i) / 8 - 1 ;
            num[j] = num[j]*10 + a[i]-'0' ;
        }
        len = (len+7)/8 ;
        flag = 1 ;
        for( i=0; p[i]<div && i<pnum; ++i ){
            if( mod( p[i] ) == 0 ){
                flag = 0 ;
                break ;
            }
        }
        if( flag )
            printf("GOOD\n") ;
        else
            printf("BAD %d\n", p[i] ) ;
    }
    return 0 ;
}
