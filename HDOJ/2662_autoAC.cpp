#include <iostream>
using namespace std;
typedef unsigned long long int longint;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        longint n, m;
        cin >> n >> m;
        longint ans;
        ans = (n * m) - n - m;
        cout << ans << endl;
    }
    return 0;
}
