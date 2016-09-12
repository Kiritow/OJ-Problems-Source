#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main()
{
    LL m,n;
    while(~scanf("%I64d %I64d",&m,&n))
    {
        LL ans = m/2*(m-m/2);

        if( ans <=  n)  puts("T");
        else           puts("F");
    }
    return 0;
}
