#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <deque>
#include <list>
using namespace std;
#define MAXWORKER 110
#define MAXBENCH 16005

#define dprintf(x,args...)
struct _worker
{
    int L,P,S;
};
bool operator < (const _worker& inca,const _worker& incb)
{
    return inca.S<incb.S;
}
_worker worker[MAXWORKER];
int dp[MAXWORKER][MAXBENCH];

int main()
{
    int N,K;
    while(scanf("%d %d",&N,&K)==2)
    {
        for(int i=1;i<=K;i++)
        {
            scanf("%d %d %d",&worker[i].L,&worker[i].P,&worker[i].S);
        }

        sort(worker+1,worker+K+1);
        /// DP Init
        memset(dp,0,sizeof(dp));

        /*
        /// Enumerate By Worker (K)
        for(int i=0;i<K;i++)
        {

        }
        */

        /// dp[i][j] means the MAX income while
        ///     i worker have operated j benches.
        for(int i=1;i<=K;i++)
        {
            dprintf(">>>>>>> i=%d\n",i);
            deque<int> pbus;
            pbus.push_back(max(0,worker[i].S-worker[i].L));
            for(int j=1;j<=N;j++)
            {
                dprintf(">>> j=%d (i=%d)\n",j,i);

                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);

                /// i-th Worker cannot reach j-th bench
                /// !!!  Must include 'equal' (=) !!!
                if(worker[i].L+worker[i].S<=j) continue;

                while(!pbus.empty()&&pbus.front()+worker[i].L<j) pbus.pop_front();

                if(j<worker[i].S)
                {
                    while(!pbus.empty()&&
                          dp[i-1][pbus.back()]-pbus.back()*worker[i].P
                          <
                          dp[i-1][j]-j*worker[i].P
                          )
                            pbus.pop_back();
                    pbus.push_back(j);
                    continue;
                }

                dp[i][j]=max(dp[i][j],dp[i-1][pbus.front()]+worker[i].P*(j-pbus.front()));

                /*
                /// Output DP
                for(int pi=1;pi<=K;pi++)
                {
                    for(int pj=1;pj<=N;pj++) printf("%d ",dp[pi][pj]);
                    printf("\n");
                }
                */
            }
        }
        printf("%d\n",dp[K][N]);

    }/// End of Main Loop
    return 0;
}
