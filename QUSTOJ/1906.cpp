#include <iostream>
#include <string>
using namespace std;

int main()
{
    int n;
    cin>>n;
    while(n--)
    {
        string a;
        cin>>a;
        int sz=a.size();
        int c=0;
        for(int i=0;i<sz;i++) if((a.at(i)>='A'&&a.at(i)<='Z')||(a.at(i)>='a'&&a.at(i)<='z')) ++c;
        cout<<c<<endl;
    }
    return 0;
}
