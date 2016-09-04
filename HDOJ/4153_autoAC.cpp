#include"stdio.h"
#include"string.h"
int main()
{
    int n,m;
    int i;
    int a[101];
    int mark[101];
    int s1,s2;
    int max;
    while(scanf("%d%d",&n,&m)!=-1,n||m)
    {
        memset(mark,0,sizeof(mark));
        max=0;
        for(i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
            mark[a[i]/m]++;
            if(max<a[i])max=a[i];
        }
        s2=max/m;
        max=0;
        for(i=0;i<=s2;i++)
        {
            if(mark[i]>max)
                max=mark[i];
        }
        s1=max;
        double ans;
        ans=0.01;
        for(i=0;i<=s2;i++)
        {
            ans+=(i*1.0/s2)*(mark[s2-i]*1.0/s1);
        }
        printf("%.6f\n",ans);
    }
    return 0;
}
