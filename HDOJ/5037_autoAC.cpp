#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#define MOD 1000000007
typedef long long ll;
using namespace std;
const int maxn=200005;
int da[maxn];
int main()
{
    int T,n,m,l,cas=0;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d%d",&n,&m,&l);
        for(int i=1;i<=n;i++)
            scanf("%d",&da[i]);
        da[++n]=m;da[0]=0;
        int ans=0;
        int k=l;
        sort(da,da+n);
        for(int i=1;i<=n;i++)
        {
            int x=(da[i]-da[i-1])%(l+1);
            int y=(da[i]-da[i-1])/(l+1);
            if(k+x>=l+1)
            {
                k=x;
                ans+=y*2+1;
            }
            else if(k+x<l+1)
            {
                k=x+k;
                ans+=y*2;
            }
        }
        printf("Case #%d: %d\n",++cas,ans);
    }
    return 0;
}
