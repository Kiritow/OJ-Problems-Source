#include <iostream>
#include <string.h>
using namespace std;
void add ( char a[], char b[] )
{
    char sum[1010] = {' '};
    int flg = 0;
    int temp = 0;
    int len_a = strlen ( a );
    int len_b = strlen ( b );
    int i = len_a;
    int j = len_b;
    for ( ; i > 0; i-- )
    {
        if ( j > 0 )
        {
            temp = a[i-1] + b[j-1] + flg - 96;
            j--;
        }
        else temp = a[i-1] + flg - 48;
        if ( temp >= 10 )
        {
            flg = 1;
        }
        else flg = 0;
        temp = temp % 10;
        sum[i] = temp + 48;
    }
    if ( flg == 1 ) sum[0] = 49;
    i = 0;
    while ( i <= len_ )
    {
        if ( sum[i] != ' ' ) cout << sum[i];
        i++;
    }
    cout << endl;
}
int main()
{
    int N;
    while ( cin >> N )
    {
        for ( int i = 1; i <= N; i++ )
        {
            char a[1000];
            char b[1000];
            cin >> a;
            cin >> b;
            int len_a = strlen ( a );
            int len_b = strlen ( b );
            cout << "Case " << i << ":\n" << a << " + " << b << " = ";
            if ( len_a >= len_ )
            {
                add ( a, b );
            }
            else add ( b, a );
            if ( i != N ) cout << endl;
        }
    }
    return 0;
}
