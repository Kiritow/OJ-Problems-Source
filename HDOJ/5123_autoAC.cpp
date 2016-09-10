#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int a[110];
int main()
{
    int t,n;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        memset(a,0,sizeof(a));
        int max=0;
        for(int i=0;i<n;i++)
        {
            int x;
            scanf("%d",&x);
            a[x]++;
            if(a[x]>max)
            max=a[x];
        }
        int ans;
        for(int i=0;i<=n;i++)
        if(a[i]==max)
        {
            ans=i;
            break;
        }
        printf("%d\n",ans);
    }
    return 0;
}
