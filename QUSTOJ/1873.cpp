#include <iostream>
#include <string>
using namespace std;

int main()
{
    int a,b;
    string c;
    cin>>a>>b>>c;
    for(int i=1;i<=a;i++)
    {
        for(int j=0;j<b;j++)
        {
            cout<<c;
        }
        if(i-a)cout<<endl;
    }
    return 0;
}
