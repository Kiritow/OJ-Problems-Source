#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;

/// 0-1背包问题(一维数组空间优化)

namespace Package1_SpaceOptimized
{
    const int MAXM = 30000 + 5;
    const int MAXN = 25 + 5;
    int ldp[MAXM];
    int w[MAXN];
    int v[MAXN];
    int N,M;
    void solve()
    {
        for(int i=1;i<=N;i++)
        {
            for(int j=M;j>=1;j--)///从M到1逆序循环
            {
                int a=ldp[j];
                int b=-1;
                if(j-w[i]>=0) b=ldp[j-w[i]]+v[i];
                ldp[j]=max(a,b);
            }
        }
        printf("%d\n",ldp[M]);
    }
    int main()
    {
        scanf("%d %d",&M,&N);
        for(int i=1;i<=N;i++)
        {
            scanf("%d %d",&w[i],&v[i]);
            v[i]=w[i]*v[i];
        }
        solve();
        return 0;
    }
}

int main()
{
    return Package1_SpaceOptimized::main();
}
