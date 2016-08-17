/// Problem Q -Excellence
#include <cstdio>
#include <cstdlib>
#include <cstring>

#include <algorithm>
using namespace std;

#define MAXN 100005
#define INF 0x3f3f3f3f
int pool[MAXN];

int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&pool[i]);
    }
    sort(pool,pool+n);
    int ans=INF;
    for(int i=0,j=n-1;i<j;i++,j--)
    {
        ans=min(ans,pool[i]+pool[j]);
    }
    printf("%d\n",ans);
    return 0;
}
