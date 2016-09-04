#include <stdio.h>
#include <queue>
#include <algorithm>
#include <string.h>
using namespace std;
int a[111111];
int sum[211111];
const int INF = 0x3fffffff;
int main()
{
    int t,n,m,i,j,k,head,end;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&k);
        j = n;
        sum[0] = 0;
        for(i = 1; i<=n; i++)
        {
            scanf("%d",&a[i]);
            sum[i] = sum[i-1]+a[i];
        }
        int ans = -INF;
        for(i = n+1; i<n+k;i++)
            sum[i] = sum[i-1]+a[i-n];
        n = n+k-1;
        deque<int> Q;
        Q.clear();
        for(i = 1; i<=n; i++)
        {
            while(!Q.empty() && sum[i-1]<sum[Q.back()])
                Q.pop_back();
            while(!Q.empty() && Q.front()<i-k)
                Q.pop_front();
            Q.push_back(i-1);
            if(sum[i]-sum[Q.front()]>ans)
            {
                ans = sum[i]-sum[Q.front()];
                head = Q.front()+1;
                end = i;
            }
        }
        if(end>j)
        end%=j;
        printf("%d %d %d\n",ans,head,end);
    }
    return 0;
}
