#include <cstdio>
#include <iostream>
using namespace std;
int n, m;
int c[60000];
char str[60000];
int lowbit ( int x )  
{  
    return x & ( -x );  
}  
void update ( int x, int v )  
{  
    for ( int i = x; i <= n; i += lowbit(i) )  
        c[i] += v;   
} 
int getSum ( int x )  
{  
    int sum = 0;  
    for ( int i = x; i > 0; i -= lowbit(i) )  
        sum += c[i];  
    return sum;  
}  
bool check ( char x, char y, char z )
{
    if ( x == 'w' && y == 'b' && z == 'w' )
        return true;
    return false;
}
void init ()
{
    for ( int i = 3; i <= n; i++ )
        if ( check(str[i-2],str[i-1],str[i]) )
            update ( i, 1 );
}
int main()
{
    char change;
    int t, l, r, pos, oper;
    int cnt = 0;
    scanf("%d",&t);
    while ( t-- )
    {
        scanf("%d%d",&n,&m);
        scanf("%s",str+1);
        memset(c,0,sizeof(c));
        init();
        printf("Case %d:\n",++cnt);
        while ( m-- )
        {
            scanf("%d",&oper);
            if ( oper == 0 )
            {
                scanf("%d%d",&l,&r);
                l++; r++;
                if ( l > r )  swap ( l, r );
                if ( r - l < 2 )  printf("0\n");
                else printf ("%d\n", getSum(r) - getSum(l+1) ); 
            }
            else
            {
                int i;
                scanf("%d %c",&pos, &change);
                pos++;
                if ( str[pos] == change ) continue;
                i = pos;
                if ( 3 <= i && i <= n )
                {
                    if ( check(str[i-2],str[i-1],str[i]) && !check(str[i-2],str[i-1],change) )
                        update(i,-1);
                    if ( !check(str[i-2],str[i-1],str[i]) && check(str[i-2],str[i-1],change) )
                        update(i,1);
                }
                i = pos + 1;
                if ( 3 <= i && i <= n )
                {
                    if ( check(str[i-2],str[i-1],str[i]) && !check(str[i-2],change,str[i]) )
                        update(i,-1);
                    if ( !check(str[i-2],str[i-1],str[i]) && check(str[i-2],change,str[i]) )
                        update(i,1);
                }
                i = pos + 2;
                if ( 3 <= i && i <= n )
                {
                    if ( check(str[i-2],str[i-1],str[i]) && !check(change,str[i-1],str[i]) )
                        update(i,-1);
                    if ( !check(str[i-2],str[i-1],str[i]) && check(change,str[i-1],str[i]) )
                        update(i,1);
                }
                str[pos] = change;
            }
        }
    }
    return 0;
}
