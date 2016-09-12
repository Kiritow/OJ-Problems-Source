#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    int T,a,b;
    cin>>T;
    for(int k=1; k<=T; k++)
    {
        int sum,ans=0;
        for(int i=2; i<=5; i++)
        {
            cin>>a>>b;
            sum=2*i*(250-a)-50*b;
            ans+=max(sum,(int)(0.4*i*500));
        }
        cout<<"Case #"<<k<<": "<<ans<<endl;
    }
    return 0;
}
