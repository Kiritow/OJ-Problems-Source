#include<cstdio>
#include<cstring>
#include<vector>
#include<cmath>
using namespace std;
const int maxn=100005;
int a[maxn];
int b[maxn];
int c[maxn];
int num[maxn];
int n;
vector<int> f[maxn];
void init()
{
    int i,j;
    for(i=1;i<maxn;i++)
        for(j=1;j<=sqrt((double)i);j++)
        {
            if(i%j==0)
            {
                f[i].push_back(j);
                f[i].push_back(i/j);
            }
        }
}
int main()
{
    init();
    while(scanf("%d",&n)&&n)
    {
        int i,j;
        memset(num,0,sizeof(num));
        for(i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
        }
        for(i=1;i<=n;i++)
        {
            int sz=f[a[i]].size();
            if(num[a[i]]==0) b[i]=a[i];
            else b[i]=a[num[a[i]]];
            for(j=0;j<sz;j++)
            {
                num[f[a[i]][j]]=i;
            }
        }
        memset(num,0,sizeof(num));
        for(i=n;i>0;i--)
        {
            int sz=f[a[i]].size();
            if(num[a[i]]==0) c[i]=a[i];
            else c[i]=a[num[a[i]]];
            for(j=0;j<sz;j++)
            {
                num[f[a[i]][j]]=i;
            }
        }
        long long ans=0;
        for(i=1;i<=n;i++)
        {
            ans=(long long)ans+((long long)b[i]*(long long)c[i]);
        }
        printf("%I64d\n",ans);
    }
    return 0;
}
