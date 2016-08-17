#include <cstdlib>
#include <iostream>
using namespace std;
struct node
{
    int d;
    __int64 w;
};
node f[1000002];       
__int64 v[1000002];
int main()
{
    int t,n;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
        {
            scanf("%I64d",&v[i]);
            f[i].d=0;
        }
        f[1].w=v[1];
        for(int i=2;i<=n;i++)
        {
            if(f[i-1].w>=0)
            {
                f[i].w=f[i-1].w+v[i];
                f[i].d=f[i-1].d+1;
            }
            else f[i].w=v[i];
        }
        int Max=1;
        for(int i=2;i<=n;i++)
        {
            if(f[i].w>f[Max].w) Max=i;
            else if(f[i].w==Max&&(i-f[i].d<Max-f[Max].d))
                Max=i;
        }
        printf("%I64d %d %d\n",f[Max].w,Max-f[Max].d,Max);
    }                               
    return 0;
}
