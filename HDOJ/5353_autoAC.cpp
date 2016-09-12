#include<cstdio>
#include<cmath>
#include<iostream>
#include<queue>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
const ll maxn=100005;
ll T,n,m,a[maxn],sum,tot;
bool flag;
int f[maxn][2];
int main()
{
    scanf("%lld",&T);
    while (T--)
    {
        scanf("%lld",&n);
        sum=0;    flag=true;
        for (int i=0;i<n;i++) 
        {
            scanf("%lld",&a[i]);
            sum+=a[i];
        }
        if (sum%n) flag=false;
        else 
        {
            sum=sum/n;
            tot=0;
            for (int i=0;i<n;i++) a[i]-=sum;
            memset(f,0,sizeof(f));
            for (int i=0,j,k;i<n+n;i++)
            {
                j=i%n;    k=(i+1)%n;
                if (a[j]>0&&a[k]<=0&&!f[j][1]) { 
                    a[k]++;
                    a[j]--;
                    if (!f[k][0]) f[j][1]=1;
                      else f[k][0]=f[j][1]=0; 
                }
                else if (a[j]<0&&a[k]>=0&&!f[k][0]) {  
                    a[k]--;
                    a[j]++;
                    if (!f[j][1]) f[k][0]=1;
                      else f[j][1]=f[k][0]=0; 
                }
            }
            for (int i=0;i<n;i++) if (a[i]) {flag=false; break;}
             for (int i=0;i<n;i++) tot+=f[i][0]+f[i][1];
            if (n==2&&tot==2) flag=false;
        }
        if (flag)
        {
            printf("YES\n%d\n",tot);
            for (int i=1,j,k;i<=n;i++)
             {
                j=i-1;    if (j==0) j=n;
                k=i+1;  if (k>n) k=1;
                if (f[i-1][0]) printf("%d %d\n",i,j);
                if (f[i-1][1]) printf("%d %d\n",i,k);
             }
        }
        else printf("NO\n");
    }
    return 0;
}
