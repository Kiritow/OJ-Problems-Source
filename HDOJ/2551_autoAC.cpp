#include <iostream>
using namespace std;
int main()
{
    int t,x;
    cin>>t;
    while(t--)
    {
        cin>>x;
        long long s=0,i=1;
        while(s<x)
        {
            s+=i*i*i;
            i++;
        }
        cout<<i-1<<endl;
    }
    return 0;
}
