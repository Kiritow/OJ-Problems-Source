#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;

///完全背包问题
namespace Package2
{
    const int INF = 1e9;
    const int MAXM=10000+5;
    const int MAXN = 500+5;
    int ldp[MAXM];
    int w[MAXN];
    int v[MAXN];
    int N,M;
    inline void init()
    {
        for(int i=0;i<MAXM;i++)
        {
            ldp[i]=INF;
        }
        ldp[0]=0;
    }
    void solve()
    {
        for(int i=1;i<=N;i++)
        {
            for(int j=1;j<=M;j++)///从1到M循环
            {
                int a=ldp[j];
                int b=INF;
                if(j-w[i]>=0) b=ldp[j-w[i]]+v[i];
                ldp[j]=min(a,b);
            }
        }
    }
    int main()
    {
        int t;
        scanf("%d",&t);
        while(t--)
        {
            int E,F;
            scanf("%d %d",&E,&F);
            scanf("%d",&N);
            M=F-E;
            for(int i=1;i<=N;i++)
            {
                scanf("%d %d",&v[i],&w[i]);
            }
            init();
            solve();
            if(ldp[M]!=INF)
            {
                printf("The minimum amount of money in the piggy-bank is %d.\n",ldp[M]);
            }
            else
            {
                printf("This is impossible.\n");
            }
        }
        return 0;
    }
}
int main()
{
    return Package2::main();
}
