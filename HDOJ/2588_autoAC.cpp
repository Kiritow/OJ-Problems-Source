#include<iostream>
#include<cstdio>
using namespace std;
#define LL long long
#define M 1000010
int euler(int n)
{
    int res=n,i;
    for(i=2;i*i<=n;i++)
    {
        if(n%i==0)
        {
            res=res-res/i;
            while(n%i==0)
                n/=i;
        }
    }
    if(n>1)
        res=res-res/n;
    return res;
}
int main()
{
    int t,p,q,sum;
    LL n,m;
    cin>>t;
    while(t--)
    {
        sum=0;
        cin>>n>>m;
        for(int i=1;i*i<=n;i++)
        {
            if(n%i==0)
            {
                if(i>=m)
                    sum=sum+euler(n/i);
                if((n/i)!=i&&(n/i)>=m)
                    sum=sum+euler(i);
            }
        }
        cout<<sum<<endl;
    }
    return 0;
}
