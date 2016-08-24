#include <cstdio>
#include <iostream>
using namespace std;
int main()
{
    long long n, a, b, ans;
    while( cin >> n, n )
    {
        n--;
        a = n/3;
        b = n%3;
        ans = a*2+1;
        if( b == 2 )    ans++;
        cout << ans << endl;
    }
    return 0;
}
