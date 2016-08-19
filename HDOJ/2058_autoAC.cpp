#include <iostream>
#include<string>
#include<cstdio>
using namespace std;
int main()
{
    double n,m,a1,a2,t,i;
    while(cin>>n>>m,n,m)
    {
        for(i=0;i<m;i++)
        {
            a1=m/i-(i-1)/2;
            if(a1<1) break;
        }
        for(t=i-1;t>=0;t--)
        {
            a1=m/t-(t-1)/2;
            if(a1-(int)a1==0.0) cout<<"["<<(int)a1<<","<<(int)a1+(int)t-1<<"]"<<endl;
        }
        cout<<endl;
    }
    return 0;
}
