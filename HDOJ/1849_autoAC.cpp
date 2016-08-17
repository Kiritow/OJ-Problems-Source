#include<iostream>
const int MAX=1001;
int s[MAX];
using namespace std;
int main()
{
    int n,m,i;
    while(cin>>n,n)
    {
        m=0; 
        for(i=1;i<=n;i++)
        cin>>s[i],m^=s[i];
        if(m)
        cout<<"Rabbit Win!"<<endl;
        else
        cout<<"Grass Win!"<<endl;
    }
    return 0;
}
