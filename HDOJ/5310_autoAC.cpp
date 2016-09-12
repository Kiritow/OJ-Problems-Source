#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int main()
{
    int m,n,q,t,p;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d%d%d",&n,&m  ,&p,&q);
        int sum=0;
        double op=q/m;
        if(op<p)
        {
            sum+=(n/m)*q;
            int pl=n%m;
            sum+=min(p*pl,q);
            cout<<sum<<endl;
        }
        else
            cout<<p*n<<endl;
    }
    return 0;
}
