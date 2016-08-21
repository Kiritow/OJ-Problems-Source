#include<iostream>
using namespace std;
int f[31];
void xx()
{
    f[1]=1;
    f[2]=3;
    for(int i=3;i<=30;++i)
        f[i]=f[i-1]+2*f[i-2];
}
int main()
{
    xx();
    int t,n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        cout<<f[n]<<endl;
    }
    return 0;
}
