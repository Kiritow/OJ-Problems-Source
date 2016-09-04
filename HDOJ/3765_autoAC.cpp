#include <stdio.h>
#include <math.h>
int a[200];
int n;
int ans;
int sum[200];
void Divide(int p,int differ,int hav)
{
    int i,j,n;
    if (differ==0)
    {
        if (hav>ans) ans=hav;
    }
    if (p<0) return;
    if (abs(differ)>sum[p]) return;
    if (sum[p]+hav<ans) return;
    Divide(p-1,differ+a[p],hav+a[p]);
    Divide(p-1,differ-a[p],hav+a[p]);
    Divide(p-1,differ,hav);
}
int Solve()
{
    ans=0;
    Divide(n-1,0,0);
    return sum[n-1]-ans;
}
int main()
{
    int i,j;
    while(1)
    {
        scanf("%d",&n);
        if (n==0) break;
        for (i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
            if (i==0) sum[i]=a[i];
            else sum[i]=sum[i-1]+a[i];
        }
        printf("%d\n",Solve());
    }
    return 0;
}
