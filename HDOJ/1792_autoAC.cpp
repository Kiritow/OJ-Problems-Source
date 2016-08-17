#include <iostream>
using namespace std;
int main()
{
    int n,m,s,k;
    while(cin>>n>>m)
    {
        s=n*m-n-m;
        cout<<s<<" "<<(n-1)*(m-1)/2<<endl;
    }
    return 0;
}
