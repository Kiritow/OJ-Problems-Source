#include <iostream>
#include <cstring>
#include <cmath>
#include <string>
#include <algorithm>
#include <map>
using namespace std;
char s[200000];
int main()
{
    int t;
    __int64 n,m,i,j,ans,carry;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%s %I64d",s,&m);
        n=0;
        for(i=0;s[i];i++)
        {
            n=n*10+s[i]-'0';
            if(n>=m)
            {
                n=m-1;
                break;
            }
        }
        ans=1;
        carry=1;
        for(i=1;i<=n;i++)
        {
            carry=(carry*i)%m;
            ans=(ans+carry)%m;
        }
        printf("%I64d\n",ans%m);
    }
    return 0;
}
