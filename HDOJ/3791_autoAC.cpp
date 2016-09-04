#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct Node
{
    int data;
    struct Node *lc,*rc;
}node,*Link;
int n,f,c,cnt;
char f1[11],la1[11],f2[11],la2[11];
void insert( Link *L,int x )
{
    if( *L )
    {
        if( x < ( *L ) -> data )
            insert( &( *L ) -> lc , x );
        else
            insert( &( *L ) -> rc , x );
    }
    else
    {
        *L = new node;
        ( *L ) -> data = x;
        ( *L ) -> lc = ( *L ) -> rc = NULL;
    }
}
void print1(Link L,char f[] )
{
    if( L )
    {
        f[cnt++] = L ->data + '0';
        print1( L -> lc ,f);
        print1( L -> rc ,f);
    }
}
void print2( Link L, char la[] )
{
    if( L )
    {
        print2( L -> lc, la );
        print2( L -> rc, la );
        la[cnt++] = L -> data + '0' ;
    }
}
int main(  )
{
    while( scanf( "%d",&n ),n )
    {
        f = 1;
        Link L = NULL;
        Link L1 = NULL;
        char str[11];
        scanf( "%s",str );
        c = strlen( str );
        for( int i = 0; i < c; ++i )
            insert( &L , str[i] - '0' );
        cnt = 0;
        print1( L ,f1);
        f1[cnt] = 0;
        cnt = 0;
        print2( L,la1 );
        la1[cnt] = 0;
        for( int i = 0; i < n; ++i )
        {
            f = 1;
            memset( f2,0,sizeof( f2 ) );
            memset( la2,0,sizeof( la2 ) );
            scanf( "%s",str );
            c = strlen( str );
            for( int i = 0; i < c; ++i )
                insert( &L1, str[i] - '0' );
            cnt = 0;
            print1( L1,f2 );
            f2[cnt] = 0;
            cnt = 0;
            print2( L1,la2 );
            la2[cnt] = 0;
            if( strcmp( f1,f2 ) != 0 || strcmp( la1,la2 ) != 0 )
                f = 0;
            free( L1 );
            L1 = NULL;
            puts( f ? "YES" : "NO" );
        }
        free( L );
        L = NULL;
    }
    return 0;
}
