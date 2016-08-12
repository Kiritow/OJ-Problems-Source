#include <iostream>
#include <math.h>
using namespace std;
int main()
{
    int t;
    while(cin>>t)
    {
        while(t--)
        {
            unsigned long n;
            cin>>n;
            double x=n*log10(n*1.0);
            x-=(__int64)x;
            int a=pow(10.0, x);
            cout<<a<<endl;
        }
    }
    return 0;
}
