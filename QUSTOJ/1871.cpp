#include <iostream>
using namespace std;

int main()
{
    int x,y,n,m;
    cin>>x>>y>>n>>m;
    while(m--)
    {
        int t;
        cin>>t;
        n+=t;
        while(n<x) n+=y-x+1;
        while(n>y) n-=y-x+1;
        cout<<n<<endl;
    }
    return 0;
}
