#include <iostream>
using namespace std;
int main()
{
    int n;
    while(cin>>n)
        if(n%8 == 2||n%8 == 6)
            cout<<"yes"<<endl;
        else
            cout<<"no"<<endl;
    return 0;
}
