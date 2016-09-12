#include <iostream>
#include <stdio.h>
using namespace std;
long long ans=0x3f3f3f3f3f3f3f;
void dfs(long long L,long long R,long long RR)
{
    if(L<0||R>2*RR)
        return;
    if(ans&&ans<=R)
        return;
    if(L==0)
    {
        ans=min(ans,R);
        return;
    }
    if (2*L<R+1)
        return;
    dfs(2*L-R-1,R,RR);
    dfs(2*L-R-2,R,RR);
    dfs(L,2*R-L+1,RR);
    dfs(L,2*R-L,RR);
}
int main()
{
    long long L,R;
    while(~scanf("%I64d %I64d",&L,&R))
    {
        dfs(L,R,R);
        if(ans==0x3f3f3f3f3f3f3f)
        {
            printf("-1\n");
        }
        else
        {
            printf("%I64d\n",ans);
        }
        ans=0x3f3f3f3f3f3f3f;
    }
    return 0;
}
