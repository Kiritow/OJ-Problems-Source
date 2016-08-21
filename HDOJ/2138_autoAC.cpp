#include <iostream>
#include <cmath>
using namespace std;
int prime(int x)
{
    if(x==1)
        return 0;
    for(int i=2; i<=sqrt(x); i++)
        if(x%i==0)
            return 0;
    return 1;
}
int main()
{
    int n,x;
    while((cin>>n)>0)
    {
        int sum=0;
        while(n--)
        {
            cin>>x;
            sum+=prime(x);
        }
        cout<<sum<<endl;
    }
    return 0;
}
