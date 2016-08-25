#include <set>
#include <map>
#include <list>
#include <stack>
#include <cmath>
#include <vector>
#include <queue>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long LL;
const int INF = 0x3f3f3f3f;
const double eps = 1e-5;
int n,m;
int sum;
int Dp[110000];
int a[110];
int main()
{
    int T;
    while(~scanf("%d",&T))
    {
        while(T--)
        {
            scanf("%d %d",&m,&n);
            sum=0;
            for(int i=1;i<=n;i++)
            {
                scanf("%d",&a[i]);
                sum=max(sum,a[i]);
            }
            sum+=m;
            memset(Dp,INF,sizeof(Dp));
            Dp[0]=0;
            for(int i=1;i<=n;i++)
            {
                for(int j=sum;j>=a[i];j--)
                {
                    if(Dp[j-a[i]]!=INF)
                    {
                        Dp[j]=min(Dp[j],Dp[j-a[i]]+1);
                    }
                }
            }
            for(int i=m;;i++)
            {
                if(Dp[i]!=INF)
                {
                    printf("%d %d\n",i,Dp[i]);
                    break;
                }
            }
        }
    }
    return 0;
}
