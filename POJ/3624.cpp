#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;

namespace Package1_SpaceOptimized
{
    const int MAXM = 12880 + 5;
    const int MAXN = 3402 + 5;
    int ldp[MAXM];
    int w[MAXN];
    int v[MAXN];
    int N,M;
    void solve()
    {
        for(int i=1;i<=N;i++)
        {
            for(int j=M;j>=1;j--)
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
        scanf("%d %d",&N,&M);
        for(int i=1;i<=N;i++)
        {
            scanf("%d %d",&w[i],&v[i]);
        }
        solve();
        return 0;
    }
}

int main()
{
    return Package1_SpaceOptimized::main();
}
