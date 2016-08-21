#include <iostream>
using namespace std;
int main()
{
    int a[41],t,n;
    a[1]=3;a[2]=9;
    for(int i=3;i<=40;i++)
        a[i]=2*a[i-1]+a[i-2];
    cin>>t;
    while(t--)
    {
        cin>>n;
        cout<<a[n]<<endl;
    }
    return 0;
}
