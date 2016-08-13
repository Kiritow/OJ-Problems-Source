#include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    while(n--)
    {
        int x,y;
        cin>>x>>y;
        if(x==0&&y==0)
            cout<<"0\n";
        else if(x==y)
        {
            if(x%2==1)
               cout<<(2*x-1)<<endl;
            else
                cout<<(2*x)<<endl;
        }
        else if(x==(y+2))
        {
            if(x%2==0)
                cout<<(2*x-2)<<endl;
            else
                cout<<(2*x-3)<<endl;
        }
        else
            cout<<"No Number\n";
    }
    return 0;
}
