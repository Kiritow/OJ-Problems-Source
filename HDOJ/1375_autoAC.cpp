#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
struct P
{
    char s[5];
    int n;
}node[11000], get[11000];
int cmp(const void *a , const void *b)
{
    return strcmp( (*(P *)a).s, (*(P *)b).s );
}
char str[11000], str1[11000];
int n, num;
void element(char *str, int s, int t, int k, P *p);
void insert(char *s, int k, P *p)
{
    int i;
    for ( i = 0 ; i < num ; i++ )
    {
        if ( !strcmp(s, p[i].s) )
            break;
    }
    if ( i < num )
        p[i].n+=k;
    else p[num].n+=k, strcpy(p[num++].s, s);
}
void sequence(char *str, int s, int t, int k, P *p)
{
    int i = s;
    while ( i < t )
    {
        if ( '(' ==str[i] )
        {
            int ti, tk;
            for ( ti = i+1, tk= 1 ; tk ; ti++ )
            {
                if ( '(' == str[ti] )
                    tk++;
                else if ( ')' == str[ti] )
                    tk--;
            }
            if ( '0' <= str[ti] && str[ti] <= '9' )
            {
                int ttk, te= ti;
                for  ( ttk = 0; '0' <= str[ti] && str[ti] <= '9' ; ti++ )
                    ttk= ttk*10+str[ti]-'0';
                element(str, i, te, k*ttk, p);
            }
            else element(str, i, ti, k, p);
            i= ti;
        }
        else if ( 'A' <= str[i] && str[i] <= 'Z' )
        {
            int tk= i;
            i++;
            if ( 'a' <= str[i] && str[i] <= 'z' )
                i++;
            if ( '0' <= str[i] && str[i] <= '9' )
            {
                int ttk;
                for  ( ttk = 0; '0' <= str[i] && str[i] <= '9' ; i++ )
                    ttk= ttk*10+str[i]-'0';
                element(str, tk, i, k*ttk, p);
            }
            else element(str, tk, i, k, p);
        }
    }
}
void element(char *str, int s, int t, int k, P *p)
{
    if ( '(' == str[s] && ')' == str[t-1] )
        sequence(str, s+1, t-1, k, p);
    else
    {
        char tmp[5];
        tmp[0] = str[s];
        if ( 'a' <= str[s+1] && str[s+1] <= 'z' )
            tmp[1]= str[s+1], tmp[2]= 0;
        else tmp[1]= 0;
        insert(tmp, k, p);
    }
}
void slove(char *str, P *p)
{
    int len = strlen(str), i= 0, j, k;
    num= 0;
    while ( i < len )
    {
        char ch;
        ch= str[i];
        if ( '0' <= ch && ch <= '9' )
        {
            for  ( k = 0; '0' <= str[i] && str[i] <= '9' ; i++ )
                k= k*10+str[i]-'0';
            for ( j = i ; str[j] && '+' != str[j] ; j++ );
            sequence(str, i, j, k, p);
            i= j+1;
        }
        else
        {
            for ( j = i+1 ; str[j] && '+' != str[j] ; j++ );
            sequence(str, i, j, 1, p);
            i= j+1;
        }
    }
}
int main()
{
    while ( EOF!= scanf("%s", str) )
    {
        memset(node, 0, sizeof(node));
        slove(str, node);
        int m= num;
        qsort(node, m, sizeof(P), cmp);
        scanf("%d", &n);
        while ( n-- )
        {
            scanf("%s", str1);
            memset(get, 0, sizeof(get));
            slove(str1, get);
            if ( m == num )
            {
                qsort(get, m, sizeof(P), cmp);
                int i;
                for ( i = 0 ; i <= num && node[i].n == get[i].n && !strcmp(node[i].s, get[i].s) ; i++ );
                if ( i > num )
                {
                    printf("%s==%s\n", str, str1);
                    continue;
                }
            }
            printf("%s!=%s\n", str, str1);
        }
    }
    return 0;
}
