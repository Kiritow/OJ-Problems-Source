#include<stdio.h>
int main()
{
    int n, i, cas = 0, d, p, l, v;
    while(~scanf("%d%d",&n,&d), n+d)
    {
        double ans = d*1.0;
        for(i = 0; i < n; i++)
        {
            scanf("%d%d%d",&p, &l, &v);
            ans -= l;  
            ans += 2.0*l / v; 
        }
        printf("Case %d: %.3lf\n\n",++cas, ans);
    }
    return 0;
}
