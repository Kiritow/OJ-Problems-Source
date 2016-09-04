#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define L 1000100
int a[L],b[L],p[L];
long long min(long long x,long long y)
{
    if (x<y) return x;
    return y;
}
int main()
{
    int T;
    int cas=1;
    scanf("%d",&T);
    while(T--)
    {
        int n;
        scanf("%d",&n);
        for(int i=1;i<=n;i++)  scanf("%d",&a[i]);
        int len=1;
        b[len]=a[1];
        for(int i=2;i<=n;i++)  if(a[i]!=a[i-1])  b[++len]=a[i];
        p[1]=0;
        for(int i=2;i<=len;i++)  p[i]=b[i]-b[i-1];
        long long sum=0,ans=0;
        for(int i=2;i<=len;i++)
        {
            if(p[i]*sum<0)  ans+=min(abs(sum),abs(p[i]));
            sum+=p[i];
        }
        sum=abs(sum);
        ans+=sum;
        printf("Case %d: %I64d %I64d\n",cas++,ans,sum+1);
    }
    return 0;
}
