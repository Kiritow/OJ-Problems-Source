#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int N=1000;
int a1[N],p1[N],a2[N],p2[N],res[N],a[N],b[N];
int m;
void dp(int k)
{
 int i,j;
 memset(res,-1,sizeof(res));
 res[0]=0;
 while (k>0)
 {
 if (k&1)
 {
 for (i=0; i<=m; i++) b[i]=res[i];
 memset(res,-1,sizeof(res));
 for (i=0; i<=m; i++)
 for (j=0; j<=i; j++)
 if (b[j]>-1 && a[i-j]>-1)
 res[i]=max(res[i],b[j]+a[i-j]);
 }
 for (i=0; i<=m; i++) b[i]=a[i];
 memset(a,-1,sizeof(a));
 for (i=0; i<=m; i++)
 for (j=0; j<=i/2; j++)
 if (b[j]>-1 && b[i-j]>-1)
 a[i]=max(a[i],b[j]+b[i-j]);
 k>>=1;
 }
}
int main()
{
 int n,n1,n2,i,j,ans;
 while (scanf("%d%d",&n,&m)==2)
 {
 if (n==0 && m==0) break;
 scanf("%d",&n1);
 for (i=1; i<=n1; i++) scanf("%d%d",&a1[i],&p1[i]);
 scanf("%d",&n2);
 for (i=1; i<=n2; i++) scanf("%d%d",&a2[i],&p2[i]);
 memset(a,-1,sizeof(a));
 for (i=1; i<=n1; i++)
 for (j=1; j<=n2; j++)
 if (a1[i]+a2[j]<=m)
 a[a1[i]+a2[j]]=max(a[a1[i]+a2[j]],p1[i]+p2[j]);
 dp(n);
 ans=0;
 for (i=0; i<=m; i++) ans=max(ans,res[i]);
 printf("%d\n",ans);
 }
}
