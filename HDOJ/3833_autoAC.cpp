#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
int a[10005];
int has[10005];
int main()
{
    int t,n,i,j;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(i = 0; i<n; i++)
        {
            scanf("%d",&a[i]);
            has[a[i]] = i;
        }
        int flag = 0;
        for(i = 0; i<n; i++)
        {
            for(j = i+1; j<n; j++)
            {
                int s = a[i]+a[j];
                if(s%2)
                continue;
                if(has[s/2]>i && has[s/2]<j)
                {
                    flag = 1;
                    break;
                }
            }
            if(flag)
                break;
        }
        printf("%s\n",flag?"Y":"N");
    }
    return 0;
}
