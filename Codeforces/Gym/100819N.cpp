#include <iostream>
#include <string>
using namespace std;

string str;

int main()
{
    int n,k;
    cin>>n>>k;
    int x=1;//safe
    int y=k;//break
    for(int i=0;i<n;i++)
    {
        int t;
        cin>>t>>str;
        if(str.at(0)=='B')
        {
            if(t<y) y=t;
        }
        else
        {
            if(t>x) x=t;
        }
    }
    cout<<x+1<<" "<<y-1<<endl;
    return 0;
}
