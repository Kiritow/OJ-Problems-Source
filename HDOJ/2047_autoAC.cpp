#include<iostream>
using namespace std;
int main()
{
    __int64 ans[100] = {0,3,8};
    int n;
    for (int i = 3; i < 100; i++)
        ans[i] = 2 * (ans[i - 1] + ans[i - 2]);
    while (cin>>n)
    {
        cout << ans[n] << endl;
    }
    return 0;
}
