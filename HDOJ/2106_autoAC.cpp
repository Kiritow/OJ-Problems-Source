#include <iostream>
#include <cstring>
#include <cmath>
#include <cstdio>
using namespace std;
const int N = 100001;
char str[N];
int main ()
{
    int n, sum, digit, len, t;
    while ( scanf("%d", &n) != EOF )
    {
        sum = 0;
        while ( n-- )
        {
            scanf("%s", str);
            digit = 0;
            if ( str[strlen(str) - 2] == '0' )
            {
                digit = 10;
                len = strlen(str) - 5;
            }
            else
            {
                digit = str[strlen(str) - 2] - '0';
                len = strlen(str) - 4;
            }
            t = 1;
            for ( int i = len; i >= 0; i-- )
            {
                sum += ( str[i] - '0' ) * t;
                t *= digit;
            }
        }
        printf("%d\n", sum);
    }
    return 0;
}
