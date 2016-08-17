#include<iostream>
using namespace std;
int order_mut[32];
int  function(int n)
{
    int i;
    order_mut[0]=1;
    for(i=1;i<=n;i++)
    {
        order_mut[i]=order_mut[i-1]*i;
        if(order_mut[i]>n)break;
    }
    return i-1;
}
int main()
{
    int i,t,n,m,ans;
    cin>>t;
    while(t--)
    {
        scanf("%d",&n);
        int m=function(n);
        ans=0;
        for(i=m;i>=1;i--)
        {
            int temp=n/order_mut[i];
            ans+=temp;
            n-=temp*order_mut[i];
            if(n==0)break;
        }
        cout<<ans<<endl;
    }
    return 0;
}
