#include<iostream>
using namespace std;
int main()
{
    double n;
    while(cin>>n)
    {
        while(n>18)
        n/=18;
        if(n<=9)
        cout<<"Stan wins."<<endl;
        else
        cout<<"Ollie wins."<<endl;
    }
    return 0;
}
