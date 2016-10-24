#include <iostream>
#include <string>
using namespace std;

int main()
{
    int h,r;
    const double pi=3.14;
    cin>>h>>r;
    cout<<pi*r*r*h<<" "<<pi*r*r*2+2*pi*r*h<<endl;
    return 0;
}
