#include <iostream>
using namespace std;
int main()
{
    int n,w,d,s,cha,yuan,ans;
    while((cin>>n>>w>>d>>s)>0)
    {
        yuan=w*n*(n-1)/2;
        cha=yuan-s;
        ans=cha/d;
        if(!ans)
            cout<<n<<endl;
        else
            cout<<ans<<endl;
    }
    return 0;
}
