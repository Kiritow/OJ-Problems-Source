#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
#define N 1010
#define min(a,b)a>b?b:a
int n;
int main()
{
    int T;
    scanf("%d",&T);
    int i,j,n,m,k,a[N],b;
    for(i=1;i<=T;i++)
    {
        scanf("%d%d%d",&n,&m,&k);
        double ans=0;
        double sum=0;
        for(j=1;j<=n;j++)
        {
            scanf("%d",&a[j]);
            sum+=a[j];
        }
        if(k<=n)
            ans=sum*1.0*m/n;
        else
        {
            ans+=m/k*sum;
            if(m%k<n)
                ans+=sum/n*(m%k);
            else
                ans+=n;
        }
        printf("Case %d: %.5lf\n",i,ans*1.0);
    }
}
