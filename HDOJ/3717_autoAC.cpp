#include<iostream>
#define maxn 50005
#define ll long long
using namespace std;
ll cnt[maxn];
ll num[maxn];
int n,k,t;
bool check(ll x)
{
    ll sum_2=0,sum_1=0,sum=0,ans=0;
    int j=n-1;
    for(int i=n-1;i>=0;i--)
    {
        if(j>i)
        {
            while((j-i)*(j-i)>=x)
            {
                sum_2-=cnt[j]*(j-i-1)*(j-i-1);
                sum_1-=cnt[j]*(j-i-1);
                sum-=cnt[j];
                j--;
            }
        }
        sum_2+=2*sum_1+sum;
        sum_1+=sum;
        ll y=num[i]-sum*x+sum_2;
        if(y<0)cnt[i]=0;
        else cnt[i]=y/x+1;
        sum+=cnt[i];
        ans+=cnt[i];
    }
    return ans<=k;
}
int main()
{
    cin>>t;
    while(t--)
    {
        cin>>n>>k;
        for(int i=0;i<n;i++)cin>>num[i];
        ll l=1,r=1e12;
        while(l<r)
        {
            ll mid=(l+r)>>1;
            if(check(mid))r=mid;
            else l=mid+1;
        }
        cout<<l<<endl;
    }
    return 0;
}
