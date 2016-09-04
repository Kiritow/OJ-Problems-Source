#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
int a[1000005],x,len;
int main()
{
    int n,i,cas = 1,ans,j;
    while(~scanf("%d",&n))
    {
        ans = 0;
        for(i = 0; i<n; i++)
            scanf("%d",&a[i]);
        if(a[0]==0)
            ans++;
        for(i = 1; i<n; i++)
        {
            if(a[i]==0)
                ans++;
            else
            {
                for(j = i-1; j>=0; j--)
                {
                    if(a[i]>a[j])
                        break;
                    else if(a[i]==a[j])
                    {
                        ans++;
                        break;
                    }
                }
            }
        }
        printf("Case %d: %d\n",cas++,n-ans);
    }
    return 0;
}
