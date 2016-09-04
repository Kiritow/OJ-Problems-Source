#include<cstdio>
const int N = 1000;
bool g[N][N];
int n , next[N];
bool expand( int s )
{
    for( int i = 0 ; i < n ; next[i++] = -1 );
    int front = s , back = front;
    for( int i = 0 ; i < n ; i++ )
    {
        if( i == s )    continue;
        if( g[i][front] )   next[i] = front , front = i;
        else
        {
            int a = front , b = next[front];
            while( b != -1 && g[b][i] )
                a = b , b = next[b];
            next[a] = i;
            next[i] = b;
            if( b == -1 )   back = i;
        }
    }
    if( g[back][front] )
    {
        next[back] = front;
        return true;
    }
    return false;
}
bool solve()
{
    for( int i = 0 ; i < n ; i++ )
        if( expand(i) )  return true;
    return false;
}
int main()
{
    while( scanf("%d",&n) , n )
    {
        for( int i = 0 ; i < n ; i++ )
            for( int j = 0 ; j < n ; j++ )
                scanf("%d",&g[i][j]);
        if( n == 1 )   puts("1");
        else if( n == 2 || !solve() )    puts("-1");
        else
            for( int i = 0 , j = 0 ; i < n ; i++ , j = next[j] )
                printf("%d%c",j+1,i==n-1?'\n':' ');
    }
    return 0;
}
