#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn=200005;
struct node
{
    int x,y;
} p[maxn];
int main()
{
    int n;
    int i;
    while(scanf("%d",&n),n)
    {
    for(i=1; i<=n; i++)
    {
        scanf("%d%d",&p[i].x,&p[i].y);
    }
    int sum=0;
    int ans=0;
    for(i=1; i<=n; i++)
    {
        if((p[i].x<p[n/2+1].x&&p[i].y>p[n/2+1].y)||(p[i].x>p[n/2+1].x&&p[i].y<p[n/2+1].y))
        {
            sum++;
        }
        else if((p[i].x<p[n/2+1].x&&p[i].y<p[n/2+1].y)||(p[i].x>p[n/2+1].x&&p[i].y>p[n/2+1].y))
        {
            ans++;
        }
    }
    cout<<ans<<" "<<sum<<endl;
    }
    return 0;
}
