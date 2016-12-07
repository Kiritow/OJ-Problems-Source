#include <iostream>
#include <string>
using namespace std;

int main()
{
    int n;
    cin>>n;
    while(n--)
    {
        string a,b;
        int x;
        cin>>a>>b>>x;
        if(x==1) cout<<b<<a<<endl;
        else cout<<a.substr(0,x-1)<<b<<a.substr(x-1)<<endl;
    }
    return 0;
}
