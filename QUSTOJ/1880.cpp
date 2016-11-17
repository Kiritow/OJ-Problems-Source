#include <iostream>
#include <string>
using namespace std;
string str1;
int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=0; i<n; i++)
    {
        int w=1,t=0;
        cin>>str1;
        int sz=str1.size();
        for(int j=0; j<sz; j++)
        {
            if(str1.at(j)=='S')
                t++;
            else
                t--;
            if(t>m||t<0)
            {
                w=0;
                break;
            }
        }
        if(w==1&&t==0)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
    return 0;
}
