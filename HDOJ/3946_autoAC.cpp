#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
int a[10005], b[10005];
int res, pre, as[10005];
bool cmp(int x, int y)
{
    return x>y;
}
int main()
{
    int n, m, an, bn, t=1, ca, i, end, lef, tmp;
    scanf("%d", &ca);
    while(ca-->0)
    {
        scanf("%d%d%d%d", &n, &m, &an, &bn);
        for(i=0; i<an; i++)
            scanf("%d", &a[i]);
        for(i=0; i<bn; i++)
            scanf("%d", &b[i]);
        sort(a, a+an, cmp);
        sort(b, b+bn, cmp);
        memset(as, 0, sizeof(as));
        for(i=1; i<=an; i++)as[i]=as[i-1]+a[i-1];
        end=n*m/3;
        if(((n==2)&&(m%3==2))||((m==2)&&(n%3==2)))end--;
        end=min(end, bn);
        res=as[min(n*m/2, an)];
        pre=0;
        for(i=1; i<=end; i++)
        {
            pre+=b[i-1];
            lef=min((n*m-3*i)/2, an);
            tmp=pre+as[lef];
            if(tmp>res)res=tmp;
        }
        printf("Case #%d: %d\n", t++, res);
    }
    return 0;
}
