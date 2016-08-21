#include<stdio.h>
#include<algorithm>
using namespace std;
struct rice
{
    int p;
    int h;
};
int cmp(rice x,rice y)
{return x.p<y.p;}
int main()
{
    int c,n,m,i;
    double sum;
    rice st[1001];
    scanf("%d",&c);
    while(c--)
    {
        scanf("%d%d",&n,&m);
        sum=0;
        for(i=0;i<m;i++)
        {
            scanf("%d",&st[i].p);
            scanf("%d",&st[i].h);
        }
        sort(st,st+m,cmp);
        for(i=0;i<m;i++)
        {
            if(n>st[i].p*st[i].h)
            {
                sum+=st[i].h;
                n-=st[i].h*st[i].p;
            }
            else
            {
                sum+=n*1.0/st[i].p;
                break;
            }
        }
        printf("%.2lf\n",sum);
    }
return 0;
}
