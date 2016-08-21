#include<iostream>
using namespace std;
long long C(int m,int n)
{
    long long s=1;
    for(int i=n,j=1;j<=m;--i,++j)
        s=s*i/j;
    return s;
}
int main()
{
    int n;
    long long ans;
    while(cin>>n)
    {
        ans=0;
        for(int i=2;i<=n;++i)
            ans+=C(i,n)*(i-1);
        cout<<ans<<endl;
    }
    return 0;
}
