#include <stdio.h>
#include <algorithm>
using namespace std;
struct TT
{
    int c,d;
    bool operator < (const TT& s)const
    {
        return d < s.d;
    }
}A[100002];
int main()
{
    int z,n;
    __int64 t,ans;
    scanf("%d",&z);
    for(int k=1;k<=z;k++)
    {
        scanf("%d",&n);
        for(int i=0;i<n;i++)
            scanf("%d%d",&A[i].c,&A[i].d);
        sort(A,A+n);
        t = ans = 0;
        for(int i=0;i<n;i++)
        {
            t += A[i].c;
            if(ans < t - A[i].d)
                ans = t - A[i].d;
        }
        printf("Case %d: %I64d\n",k,ans);
    }
    return 0;
}
