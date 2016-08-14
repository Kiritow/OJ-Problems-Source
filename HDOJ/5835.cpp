#include <cstdio>
using namespace std;
int main()
{
    int t;
    scanf("%d",&t);
    for(int test=1;test<=t;test++)
    {
        int n;
        scanf("%d",&n);
        long long ans=0;
        for(int i=0;i<n;i++)
        {
            int tmp;
            scanf("%d",&tmp);
            ans+=tmp;
        }
        ans/=2;
        printf("Case #%d: %lld\n",test,ans);
    }
    return 0;
}
