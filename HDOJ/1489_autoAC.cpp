#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>
#include<time.h>
using namespace std;
long long s[100005];
int main()
{
    long long n,i,ans;
    while(cin>>n)
    {
        if(n==0)
        {
            break;
        }
        for(i=0;i<n;i++)
        {
            cin>>s[i];
        }
        ans=0;
        for(i=0;i<n-1;i++)
        {
            if(s[i]>0)
            {
                ans+=s[i];
                s[i+1]+=s[i];
            }
            else
            {
                ans-=s[i];
                s[i+1]+=s[i];
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
