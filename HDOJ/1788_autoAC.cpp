#include<iostream>
using namespace std;
__int64 gcd(__int64 x,__int64 y)
{
    if(x<y)
    {
        __int64 t=x;x=y;y=t;
    }
    while(y!=0)
    {
        __int64 t=x;
        x=y;
        y=t%y;
    }
    return x;
}
__int64 work(__int64 x,__int64 y)
{
    return x/gcd(x,y)*y;
}
int main()
{
    __int64 n,a;
    while(cin>>n>>a&&(n||a))
    {
        __int64 u,v;
        cin>>u;
        for(int i=1;i<n;i++)
        {
            cin>>v;
            u=work(u,v);
        }
        cout<<u-a<<endl;
    }
    return 0;
}
