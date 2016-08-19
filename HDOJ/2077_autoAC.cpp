#include <iostream>
using namespace std;
int main()
{
    long long f[21] = {0,2};
    int n,i;
    for(i = 2;i < 21;i++)
        f[i] = 3 * f[i-1] + 2;
    while(cin >> n)
    {
        while(n--)
        {
            cin >> i;
            cout << f[i-1] + 2 << endl;
        }
    }
    return 0;
}
