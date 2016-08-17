#include<iostream>
using namespace std;
int main()
{
    int  n,m,a,b;
    while(cin>>n>>m)
    {
        a=n;
        b=m;
        while(a!=b)
        {
            if(a>b)
            a-=b;
            else
            b-=a;
        }
        cout<<n+m-a<<endl;
    }
    return 0;
}
