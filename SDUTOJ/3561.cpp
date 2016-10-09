#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
using namespace std;
typedef long long LL;

LL a[50];
LL b[50];

/// Print Table
void init()
{
    a[0]=1;
    a[1]=2;
    for(int i=2;i<48;i++)
    {
        a[i]=a[i-1]+a[i-2];
    }
}

int _ans;
int dfs(LL cVal,int cidx,int bidx)
{
    if(cVal==0)
    {
        _ans=bidx;return 1;
    }
    if(cidx==-1) return 0;
    for(int i=cidx;i>=0;i--)
    {
        if(cVal>=a[i])
        {
            b[bidx]=a[i];
            int ret=dfs(cVal-a[i],i-1,bidx+1);
            if(ret) return 1;
        }
    }
    return 0;
}

int main()
{
    init();
    int n;
    scanf("%d",&n);
    LL t;
    for(int cc=0;cc<n;cc++)
    {
        scanf("%lld",&t);

        int ret=dfs(t,47,0);
        if(ret)
        {
            printf("%lld=",t);
            for(int i=_ans-1;i>0;i--)
            {
                printf("%lld+",b[i]);
            }
            printf("%lld\n",b[0]);
        }
        else
        {
            printf("-1\n");
        }
    }
    return 0;
}
