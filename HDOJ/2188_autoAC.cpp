#include <iostream>
using namespace std;
int main()
{
    int c,n,m;
    cin>>c;
    while(c--)
    {
        cin>>n>>m;
       if(n%(m+1)==0)
        cout<<"Rabbit"<<endl;
       else
        cout<<"Grass"<<endl;
    }
}
