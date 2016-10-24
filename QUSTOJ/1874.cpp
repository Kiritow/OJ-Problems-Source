#include <iostream>
#include <string>
using namespace std;

int main()
{
    int x;
    cin>>x;
    while(x>=1000)
    {
        cout<<"M";
        x-=1000;
    }
    while(x>=500)
    {
        cout<<"D";
        x-=500;
    }
    while(x>=100)
    {
        cout<<"C";
        x-=100;
    }
    while(x>=50)
    {
        cout<<"L";
        x-=50;
    }
    while(x>=10)
    {
        cout<<"X";
        x-=10;
    }
    while(x>=5)
    {
        cout<<"V";
        x-=5;
    }
    while(x>=1)
    {
        cout<<"I";
        x-=1;
    }
    cout<<endl;
    return 0;
}
