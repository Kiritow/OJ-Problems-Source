#include <iostream>
using namespace std;
int main()
{
    int a[6],i,n;
    cin>>n;
    while(n--)
    {
        for(i=0;i<6;i++)
            cin>>a[i];
        if(a[0]-a[1]+a[2]-a[3]+a[4]-a[5]==0)
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
