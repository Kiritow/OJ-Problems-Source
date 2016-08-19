#include <iostream>
#include <string.h>
#include <cstdio>
using namespace std;
typedef long long LL;
const int MS=1001;
int main()
{
    LL n;
    int T;
    cin>>T;
    while(T--)
    {
        cin>>n;
        cout<<n*n*n<<" "<<(n+1)*(n+1)*(n+1)<<endl;
    }
    return 0;
}
