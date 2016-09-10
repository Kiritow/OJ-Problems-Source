#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
char ans[500], s[500];
char pattern[] = "_small_";
int main ( )
{
    while ( ~scanf ( "%s" ,  s ) ) 
    {
        int i = 0;
        while ( s[i] )
            if ( s[i++] == '_' ) break;
        int j = 0;
        while ( s[i] )
            ans[j++] = s[i++];
        i = 0;
        while ( pattern[i] )
            ans[j++] = pattern[i++];
        i = 0;
        scanf ( "%s" , s);
        while ( s[i] )
            if ( s[i++] == '_' ) break;
        while ( s[i] )
            ans[j++] = s[i++];
        ans[j] = 0;
        printf ( "%s\n" , ans );
    }
}
