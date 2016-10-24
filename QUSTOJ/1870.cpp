#include <iostream>
using namespace std;

void act(int n,char a,char b,char c)
{
    if(n==1)
        cout<<a<<"---->"<<c<<endl;
    else
    {
        act(n-1,a,c,b);
        cout<<a<<"---->"<<c<<endl;
        act(n-1,b,a,c);
    }
}

int main()
{
    int n;
    cin>>n;
    act(n,'A','B','C');
    return 0;
}
