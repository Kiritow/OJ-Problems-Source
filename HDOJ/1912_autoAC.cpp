#include <iostream>
#include <stdio.h>
#include <cmath>
#include <algorithm>
#include <string.h>
using namespace std;
int L,d;
struct I
{
    double l,r;
}inter[10000];
bool cmp(I a ,I b)
{
    if(a.r<b.r)
        return true;
    else if(a.r==b.r)
    {
        if(a.l>b.l)
            return true;
        return false;
    }
    return false;
}
int main()
{
    double x,y;
    while(scanf("%d",&L)!=EOF)
    {
        scanf("%d",&d);
        int n;
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            scanf("%lf%lf",&x,&y);
            inter[i].l=x-sqrt(d*d-y*y);
            inter[i].r=x+sqrt(d*d-y*y);
        }
        sort(inter+1,inter+1+n,cmp);
        int ans=1;
        double temp=inter[1].r;
        for(int i=2;i<=n;i++)
        {
            if(temp>L)
                temp=L;
            if(temp<inter[i].l)
            {
                ans++;
                temp=inter[i].r;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
