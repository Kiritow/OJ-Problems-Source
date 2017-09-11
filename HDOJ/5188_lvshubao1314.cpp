/**
hdu5188 有限制条件的01背包问题
题目大意：有n道题i题用时ti秒，得分vi，在li时间点之前不能做出来，而且一道题不能分开几次做（一旦开始做，必须在ti时间内把它做完）
          问得到w分的最小用时是多少
解题思路：很像01背包的基本题，但是有一个li分钟前不能AC的限制，因此第i道题必须在最早第（li-ti）时刻做，我们按照l-t递增排序，然后按照经典解法来做
          就行了
*/
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
using namespace std;

struct note
{
    int t,v,l;
    bool operator <(const note &other)const
    {
        return l-t<other.l-other.t;
    }

}node[35];

int n,m;
int dp[3000005];

int main()
{
    while(~scanf("%d%d",&n,&m))
    {
        int sum=0,ans=0,up=0;
        for(int i=0;i<n;i++)
        {
            scanf("%d%d%d",&node[i].t,&node[i].v,&node[i].l);
            sum+=node[i].v;
            ans+=node[i].t;
            up=max(up,node[i].l);
        }
        if(m>sum)
        {
            printf("zhx is naive!\n");
            continue;
        }
        sort(node,node+n);
        up=max(up,ans);
        memset(dp,0,sizeof(dp));
        for(int i=0;i<n;i++)
        {
            for(int j=up;j>=node[i].l;j--)
            {
                if(j>=node[i].t)
                {
                    dp[j]=max(dp[j],dp[j-node[i].t]+node[i].v);
                }
            }
        }
        int flag=0;
        for(int i=0;i<=up;i++)
        {
            if(dp[i]>=m)
            {
                printf("%d\n",i);
                flag=1;
                break;
            }
        }
        if(flag==0)
        {
            printf("zhx is naive!\n");
        }
    }
    return 0;
}
