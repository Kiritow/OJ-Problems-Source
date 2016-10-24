#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int a,b,c;
    cin>>a>>b>>c;
    int x=(-b+sqrt(b*b-4*a*c))/2*a;
    int y=(-b-sqrt(b*b-4*a*c))/2*a;
    if(x<y) swap(x,y);
    cout<<x;
    if(y!=x) cout<<" "<<y;
    cout<<endl;
    return 0;
}
