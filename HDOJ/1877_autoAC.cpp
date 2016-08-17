#include<iostream>
#include<cstdlib>
using namespace std;
int main()
{
    int m;
    __int64 A,B;
    char ans[30];
    while(cin>>m&&m)
    {
        cin>>A>>B;
        A+=B;
        itoa(A,ans,m);
        cout<<ans<<endl;
    }
    return 0;
}
