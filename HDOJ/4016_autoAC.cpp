#include<iostream>
#include<algorithm>
#define N 45
using namespace std;
__int64 MAX=0x7fffffffffffffff;
__int64 a[N],sum[N],ans;
int k,n;
void dfs(int t,int d,__int64 num)
{
    if(ans>num) ans=num;
    if(t==n+1||d==k) return;
       __int64 s=num;
   s &= sum[t];
   if(s>=ans)return;
   dfs(t+1,d+1,num&a[t]);
   dfs(t+1,d,num);
}
int main()
{
    int cas,T=0;
    cin>>cas;
    while(cas--)
    {
        scanf("%d %d",&n,&k);
        for(int i=1;i<=n;i++)
            scanf("%I64d",&a[i]);
        sort(a+1,a+n+1);
        sum[n]=a[n];
        for(int i=n-1;i>=1;i--)
            sum[i]=a[i]&sum[i+1];
        ans=MAX;
        dfs(1,0,MAX);
        printf("Case #%d: ",++T);
        printf("%I64d\n",ans);
    }
    return 0;
}
