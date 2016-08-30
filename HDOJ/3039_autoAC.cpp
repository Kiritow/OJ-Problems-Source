#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
double a[105][205],b[105],ans;
int main()
{
    int n,q,m;
    while(scanf("%d%d",&n,&q)!=EOF)
    {
        m=2*n;
        for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
       {
           scanf("%lf",&a[i][j]);
           if(i==j)
           a[i][n+j]=1;
           else
           a[i][n+j]=0;
       }
       for(int i=1;i<=n;i++)
       {
        int pos=i;
        for(;pos<=n;pos++)
        if(fabs(a[pos][i])>1e-6)break;
        if(pos!=i)
        for(int k=i;k<=m;k++)
        swap(a[i][k],a[pos][k]);
        double temp=a[i][i];
        for(int j=i;j<=m;j++)a[i][j]/=temp;
        for(int j=1;j<=n;j++)
        {
            if(j==i)continue;
            temp=a[j][i];
            for(int k=i;k<=m;k++)
            a[j][k]-=a[i][k]*temp;
        }
        }
        while(q--)
        {
            for(int i=1;i<=n;i++)
            scanf("%lf",&b[i]);
            for(int i=1;i<=n;i++)
            {
                ans=0;
                for(int j=n+1;j<=m;j++)
                ans+=a[i][j]*b[j-n];
                printf("%.2f%c",ans,i==n?'\n':' ');
            }
        }
    }
}
