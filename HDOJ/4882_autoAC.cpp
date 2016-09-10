#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define N 101000
using namespace std;
struct YYC
{
    int x,y;
    bool operator < (const YYC &a)const
    {return x*a.y<y*a.x;}
}fev[N];
int n;
long long ans,sum;
int main()
{
    int i;scanf("%d",&n);
    for(i=1;i<=n;i++)scanf("%d",&fev[i].x);
    for(i=1;i<=n;i++)scanf("%d",&fev[i].y);
    sort(fev+1,fev+n+1);
    for(i=1;i<=n;i++)sum+=fev[i].x,ans+=sum*fev[i].y;
    cout<<ans<<endl;
    return 0;
}
