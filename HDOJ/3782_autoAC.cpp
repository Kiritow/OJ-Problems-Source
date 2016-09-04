#include <iostream>
using namespace std;
int main()
{
    int n;
    while(cin >> n && n)
    {
        int cnt = 0;
        while(n!=1)
        {
            if(n%2)
            n = (3*n+1)/2;
            else
            n = n/2;
            cnt++;
        }
        cout << cnt << endl;
    }
    return 0;
}
