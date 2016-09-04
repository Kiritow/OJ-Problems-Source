#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN = 100010;
const long long INF = 1LL<<62;
int A[MAXN],B[MAXN];
int main()
{
    int n;
    while(~scanf("%d",&n))
    {
        for(int i=0;i<n;i++)
            scanf("%d",&A[i]);
        for(int i=0;i<n;i++)
            scanf("%d",&B[i]);
        sort(A,A+n);
        sort(B,B+n);
        long long ans=-INF;
        int ka=lower_bound(A,A+n,0)-A;
        int kb=lower_bound(B,B+n,0)-B;
        int d1=min(n-ka,kb);
        int a1=n-1,b1=d1-1;
        for(int cnt=0;cnt<d1;cnt++)
        {
            ans=max(ans,(long long)A[a1--]*B[b1--]);
        }
        int d2=min(ka,n-kb);
        int a2=d2-1,b2=n-1;
        for(int cnt=0;cnt<d2;cnt++)
        {
            ans=max(ans,(long long)A[a2--]*B[b2--]);
        }
        a1=n-1-d1,b1=d1;
        for(int cnt=0;cnt<n-d1-d2;cnt++)
        {
            ans=max(ans,(long long)A[a1--]*B[b1++]);
        }
        printf("%I64d\n",ans);
    }
    return 0;
}
