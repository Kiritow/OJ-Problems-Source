#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <queue>
using namespace std;
char ss[1005][55], T[2000005];
int cnt[1005];
struct Node
{
    int flag;
    Node *ch[26], *fail;
};
void getstr( char *s )
{
    int p = 0;
    char c;
    while( c = getchar(), c == '\n' ) ;
    s[p++] = c;
    while( c = getchar(), c != '\n' )
        s[p++] = c;
    s[p] = '\0';
}
Node *init(  )
{
    Node *p = new Node;
    p->flag = -1;
    p->fail = NULL;
    memset( p->ch, 0, sizeof( p->ch ) );
    return p;
}
void BuildTree( Node *p, char *in, int No )
{
    int dx = *in - 'A';
    if( *in )
    {
        if( !p->ch[dx] )
            p->ch[dx] = init();
        BuildTree( p->ch[dx], in + 1, No );
    }
    else
        p->flag = No;
}
void BuildFailPoint( Node *r )
{
    queue<Node *>q;
    q.push( r );
    while( !q.empty() )
    {
        Node *pos = q.front();
        q.pop();
        for( int i = 0; i <26; ++i )
        {
            Node *f = pos->fail;
            if( pos->ch[i] )
            {
                while( f ) 
                {
                    if( f->ch[i] )
                    {
                        pos->ch[i]->fail = f->ch[i];
                        break;
                    }
                    f = f->fail;
                }
                if( !f )
                {
                    pos->ch[i]->fail = r;
                }
                q.push( pos->ch[i] );
            }
        }
    }
}
void AcAuto( Node *r, char *text )
{
    int len = strlen( text );
    Node *f = r;
    for( int i = 0; i < len; ++i )
    {
        int dx = text[i] - 'A';
        if( dx < 0 || dx >= 26 )
        {
            f = r;
            continue;
        }
        while( f )
        {
            if( f->ch[dx] )
            {
                f = f->ch[dx]; 
                break;
            }
            f = f->fail;
        }
        if( !f )
            f = r;
        else
        {
            Node *t = f;
            while( t )
            {
                if( t->flag!= -1 )
                {
                    cnt[t->flag]++;
                }
                t = t->fail;
            }
        }
    }
}
void _free( Node *p )
{
    for( int i = 0; i < 26; ++i )
    {
        if( p->ch[i] )
            _free( p->ch[i] );
    }
    free( p );
}
int main()
{
    int N;
    while( scanf( "%d", &N ) != EOF )
    {
        Node *r = init();
        memset( cnt, 0, sizeof( cnt ) );
        for( int i = 0; i < N; ++i )
        {
            getstr( ss[i] );
            BuildTree( r, ss[i], i );
        }
        BuildFailPoint( r );
        getstr( T );
        AcAuto( r, T );
        for( int i = 0; i < N; ++i )
        {
            if( cnt[i] )
                printf( "%s: %d\n", ss[i], cnt[i] );
        }
        _free( r );
    }
    return 0;
}
