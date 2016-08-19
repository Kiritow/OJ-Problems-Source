#include<stdio.h>
#include<math.h>
#include<algorithm>
using namespace std;
int main()
{
    int c;
    double h,m,s,ans;
    scanf("%d",&c);
    while(c--)
    {
        scanf("%lf%lf%lf",&h,&m,&s);
        if(h>=12) h-=12.0;
        m = m + s/60.0;
        h = h + m/60.0;
        ans = fabs(h*30.0 - m*6.0);
        printf("%d\n",(int)min(ans,360.00-ans));
    }
}
