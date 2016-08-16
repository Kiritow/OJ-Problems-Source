#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;
#define MAXINTERVAL 512
int a[MAXINTERVAL];
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        memset(a,0,sizeof(a));
        int n;
        scanf("%d",&n);
        int max=0;
        for(int i=0;i<n;i++)
        {
            int s,t;
            scanf("%d %d",&s,&t);
            if(t<s) swap(t,s);
            t=(t+1)/2;
            s=(s+1)/2;
            for(int j=s;j<=t;j++)
            {
                ++a[j];
                if(a[j]>max) max=a[j];
            }
        }
        printf("%d\n",max*10);
    }
    return 0;
}
