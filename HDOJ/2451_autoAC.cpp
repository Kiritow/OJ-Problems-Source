#include <cstdio>
#include <cstring>
#include <cmath>
#include <map>
#include <queue>
#include <stack>
#include <iostream>
#include <algorithm>
using namespace std;
const int maxn=20;
char a[20];
int c[20];
int main()
{
    int i,j,k,n;
    c[1]=3;
    for(i=2;i<=10;i++)
        c[i]=c[i-1]*4;
    while(cin>>a)
    {
        n=strlen(a);
        int ans=0;
        for(i=0;i<n;i++)
        {
            if(i==0&&i!=n-1)
            {
                if(a[i]>'3'){ans+=4*c[n-i-1];break;}
                ans+=(a[i]-'0')*c[n-i-1];
            }
            else if(i==n-1)
            {
                if(a[i]>'3'){ans+=3;break;}
                ans+=a[i]-'0';
            }
            else
            {
                if(a[i]>'3'){ans+=4*c[n-i-1];break;}
                ans+=(a[i]-'0')*c[n-i-1];
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
