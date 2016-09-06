#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
unsigned int a,b,k,n,l,last;
unsigned int mod;
bool v[21000000];
int main()
{
    while(cin>>n>>l>>a>>b>>mod)
    {
        for(unsigned int i=1;i<=n;i++)
        v[i]=false;
        unsigned int ans=0;unsigned int max=0,t;
        last=b;
        for(unsigned int i=1;i<=n;i++)
        {
            t=(last+a)%mod;
            if(t*2<=l)
            {
                ans++;v[i]=true;
                if(t>max)max=t;
            }
            last=t;
        }
        last=b;
        for(unsigned int i=1;i<=n;i++)
        {
            t=(last+a)%mod;
            if((!v[i])&&t+max<=l){ans++;break;}
            last=t;
        }
        cout<<ans<<endl;
    }
    return 0;
}
