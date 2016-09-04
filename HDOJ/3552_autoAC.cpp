#include <stdio.h>
#include <algorithm>
using namespace std;
struct TT
{
    int a,b;
    bool operator <(const TT&s)const
    {
        return a > s.a;
    }
}S[100005];
int main()
{
    int z,n,ncase=0;
    scanf("%d",&z);
    while(z--)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
            scanf("%d%d",&S[i].a,&S[i].b);
        sort(S+1,S+1+n);
        int ans = 0x7fffffff , B = 0;
        S[n+1].a = 0;
        for(int i=1;i<=n+1;i++)
        {
            B = max(B,S[i-1].b);
            ans = min(ans,S[i].a+B);
        }
        printf("Case %d: %d\n",++ncase,ans);
    }
    return 0;
}
