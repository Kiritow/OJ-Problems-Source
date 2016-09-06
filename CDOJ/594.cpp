#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;

#define MAXN 50100
#define MAXH 110
#define MAXVAL_H 100
#define INF 0x3f3f3f3f

int dp[2][MAXH];
int bus[MAXH];

int main()
{
    int N,C;
    while(scanf("%d %d",&N,&C)==2)
    {
        /// Main Loop
        int x;
        scanf("%d",&x);
        int index=0;
        ///由于人无法变矮，因此这部分的花费记为INF
        for(int i=0;i<x;i++) dp[index][i]=INF;
        ///大于等于x的时候可以内增高呀！
        for(int i=x;i<=MAXVAL_H;i++) dp[index][i]=(i-x)*(i-x);
        N--;
        while(N--)
        {
            ///登记一个新的身高x
            scanf("%d",&x);
            index=!index;///反转index(复用dp空间)
            int begin=0;
            int end=0;
            /// 单调队列 方向: 小(0) --> 大(N)
            for(int k=0;k<=MAXVAL_H;k++)
            {
                int cost=dp[!index][k]-k*C;
                /// Pop Back
                while(begin<end&& bus[end-1] > cost) end--;
                /// Push Back
                bus[end++]=cost;
                if(k<x) {dp[index][k]=INF;}
                ///队列最前面是值最小的
                else {dp[index][k]=bus[begin]+k*C+(k-x)*(k-x);}
            }
            /// Empty
            begin=end=0;
            for(int k=MAXVAL_H;k>=0;k--)
            {
                int cost=dp[!index][k]+k*C;
                /// Pop Back
                while(begin<end&&bus[end-1] > cost) end--;
                /// Push Back
                bus[end++]=cost;
                if(k>=x)
                {
                    dp[index][k]=min(dp[index][k],bus[begin]-k*C+(k-x)*(k-x));
                }
            }
        }
        int ans=INF;
        for(int i=0;i<=MAXVAL_H;i++)
        {
            ans=min(dp[index][i],ans);
        }
        printf("%d\n",ans);
    }
    return 0;
}
