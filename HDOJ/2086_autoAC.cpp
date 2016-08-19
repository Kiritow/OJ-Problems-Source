#include<stdio.h>
int main()
{
    int n,i;
    double  a1,an,c[3001],s,x;
    while(~scanf("%d",&n))
    {
        scanf("%lf%lf",&a1,&an);
        for(i=1;i<=n;i++)
            scanf("%lf",&c[i]);
        s=n*a1+an;x=0;
        for(i=1;i<=n;i++)
            x+=(n-i+1)*c[i];
        s=(s-2*x)/(n+1);
        printf("%.2lf\n",s);
    }
    return 0;
}
