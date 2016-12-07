#include <iostream>
#include <complex>
using namespace std;

int main()
{
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    complex<int> x(a,b);
    complex<int> y(c,d);
    cout<<x+y<<" "<<x-y<<endl;
    return 0;
}
