#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cmath>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<iomanip>
#include<string>
#include<cstring>
using namespace std;
int Gcd(__int64 x,__int64 y)
{
    if(y==0)
    return x;
    else
    return Gcd(y,x%y);
}
int main()
{
    __int64 x,y,t,m;
    while(cin>>x>>y&&(x||y))
    {
        if(x<y)
        {
            t=x;
            x=y;
            y=t;
        }
        if(Gcd(x,y)==1)
        {
            m=x*y-(x+y);
            cout<<m<<endl;
        }
        else
        cout<<"Inf"<<endl;
    }
    return 0;
}
