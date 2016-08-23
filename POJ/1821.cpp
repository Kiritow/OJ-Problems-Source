#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <queue>
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

int static_list[MAXBENCH];
int static_list_front;
int static_list_end;

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
            //list<int> pbus;
            static_list_front=0;
            static_list[0]=max(0,worker[i].S-worker[i].L);
            static_list_end=1;

            for(int j=1;j<=N;j++)
            {
                dprintf(">>> j=%d (i=%d)\n",j,i);

                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);

                /// i-th Worker cannot reach j-th bench
                /// !!!  Must include 'equal' (=) !!!
                if(worker[i].L+worker[i].S<=j) continue;

                while(static_list_front<static_list_end&&static_list[static_list_front]+worker[i].L<j)
                    static_list_front++;

                if(j<worker[i].S)
                {
                    while(static_list_front<static_list_end&&
                          dp[i-1][static_list[static_list_end-1]]-static_list[static_list_end-1]*worker[i].P
                          <
                          dp[i-1][j]-j*worker[i].P
                          )
                            static_list_end--;
                    static_list[static_list_end++]=j;
                    continue;
                }

                dp[i][j]=max(dp[i][j],dp[i-1][static_list[static_list_front]]+worker[i].P*(j-static_list[static_list_front]));

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
