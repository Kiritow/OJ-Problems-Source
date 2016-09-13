#include <cstdio>
#include <cstdlib>
#include <cstring>

#include <algorithm>
using namespace std;

#define MAXN 1000100
#define INF 0x3f3f3f3f

long long a[MAXN];
long long dp[MAXN];

long long t[MAXN];
int tbegin,tend;

int main()
{
    int N;
    long long M;
    scanf("%d %I64d",&N,&M);
    tbegin=tend=0;
    long long blocksum=0;
    int blockbegin=0;
    for(int i=1;i<=N;i++)
    {
        scanf("%I64d",&a[i]);
        ///如果整个数列中任何一个数超过M，那么是无论如何都不能划分的(没有负数存在)
        if(a[i]>M)
        {
            printf("-1\n");
            return 0;
        }
        blocksum+=a[i];
        while(blocksum>M)
        {
            ///如果现在假设的连续区块 ID: blockbegin, blockbegin+1 ... i
            ///求和超过M，那么这是一个非法区块，需要减去最左端的区块(向右收缩)
            blockbegin++;///【疑问】为什么blockbegin要在前面?
            blocksum-=a[blockbegin];
        }
        ///队列用于维护每个区块中最大的值的ID
        while(tbegin<tend&&a[t[tend-1]]<=a[i]) tend--;
        t[tend++]=i;
        ///队列中最左端的值的ID在blockbegin的左端，弹出
        while(tbegin<tend&&t[tbegin]<=blockbegin) tbegin++;

        ///未进行DP前初始化为INF
        dp[i]=INF;

        int maxvalbegin=blockbegin;

        for(int index=tbegin;index<tend;index++)
        {
            long long tmp=dp[maxvalbegin]+a[t[index]];
            dp[i]=min(dp[i],tmp);
            maxvalbegin=t[index];
        }
    }
    printf("%I64d\n",dp[N]);
    return 0;
}
