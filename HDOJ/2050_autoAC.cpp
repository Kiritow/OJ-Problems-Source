#include <iostream>
using namespace std;
int main()
{
    int n, m;
    cin >>n;
    while(n--)
    {
        cin >>m;
        cout <<2*m*m - m + 1 <<endl;
    }
    return 0;
}
