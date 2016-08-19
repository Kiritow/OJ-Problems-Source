#include<iostream>
using namespace std;
bool f(int n)
{
    for(int i=2;i<=n/2;i++)
        if(n%i==0)
            return false;
    return true;
}
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int i,n,x;
        cin>>n;
        if(n==2||n==5)cout<<"yes"<<endl;
        else if(n<5) cout<<"no"<<endl;
        else
        for(i=2;i<=(n-1)/2;i++)
        {
            if(f(i)&&f(n-1-i)||f(n-1))
            {
                cout<<"no"<<endl;
                x=0;
                break;
            }
            x=1;
        } 
        if(x==1)
            cout<<"yes"<<endl;
    }
    return 0;
}
