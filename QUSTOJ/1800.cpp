#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;
#define NINF 0xc0c0c0c0
inline int MaxSum(int n,int *a)
{
    int sum=NINF,b=0;
    for(int i=0; i<n; i++)
    {
        if(b>0)
        {
            b+=a[i];
        }
        else
        {
            b=a[i];
        }
        if(b>sum)
        {
            sum = b;
        }
    }
    return sum;
}
#define MAXN 1024000
int A[MAXN];
int main()
{
    int N;
    while(scanf("%d",&N)==1)
    {
        for(int i=0;i<N;i++)
        {
            scanf("%d",&A[i]);
        }
        int ans=MaxSum(N,A);
        printf("%d\n",ans);
    }
    return 0;
}
