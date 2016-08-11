#include <cstdio>
#include <cstdlib>
#include <cstring>

#include <algorithm>
#include <cmath>
using namespace std;

const int MAXN = 1000005;

int n,ndev;
int a[MAXN];

const int MAXDEV = 25;

int minsum[MAXN][MAXDEV];

void RMQ() //预处理->O(nlogn)
{
    for(int j = 1; j <= ndev; ++j)
        for(int i = 1; i <= n; ++i)
            if(i + (1 << j) - 1 <= n)
            {
                //maxsum[i][j] = max(maxsum[i][j - 1], maxsum[i + (1 << (j - 1))][j - 1]);
                minsum[i][j] = min(minsum[i][j - 1], minsum[i + (1 << (j - 1))][j - 1]);
            }
}
int RMQ(int i,int j)
{
    int k=log2( j - i + 1);
    //return max(maxsum[i ][ k], maxsum[ j - 2 ^ k + 1][ k]);
    return min(minsum[i ][ k], minsum[ j - (1<<k) + 1][ k]);
}
void Init()
{
    for(int i=1;i<=n;i++)
    {
        minsum[i][0]=a[i];
    }
}
int main()
{
    scanf("%d",&n);
    ndev=0;
    int p=n;
    if(p&1) p++;
    while(p>1)
    {
        p>>=1;
        ndev++;
    }
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
    }
    Init();
    RMQ();
    int t;
    scanf("%d",&t);
    for(int i=0;i<t;i++)
    {
        int L,R;
        scanf("%d %d",&L,&R);
        int ans=RMQ(L,R);
        printf("%d\n",ans);
    }
    return 0;
}
