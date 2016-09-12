#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<queue>
#include<map>
using namespace std;
#define MOD 1000000007
const int INF=0x3f3f3f3f;
const double eps=1e-5;
typedef long long ll;
#define cl(a) memset(a,0,sizeof(a))
#define ts printf("*****\n");
const int MAXN=100005;
int n,m,tt;
int a[MAXN],b[MAXN];
bool check(int mid)
{
    for(int i=1;i<=n;i++)
    {
        b[i]=a[i];
    }
    for(int i=1;i<=n;i++)
    {
        if(i==1)
        {
            b[i]-=mid;
            continue;
        }
        if(b[i]<=b[i-1])
        {
            if((b[i-1]+1)-b[i]<=mid)
                b[i]=b[i-1]+1;
            else
            {
                return 0;
            }
        }
        if(b[i]-mid>b[i-1])
        {
            b[i]=b[i]-mid;
        }
        else
        {
            b[i]=b[i-1]+1;
        }
    }
    return 1;
}
int main()
{
    int i,j,k;
    int ca=1;
    scanf("%d",&tt);
    while(tt--)
    {
        printf("Case #%d:\n",ca++);
        scanf("%d",&n);
        for(i=1;i<=n;i++)   scanf("%d",a+i);
        int l=0;
        int r=1000005;
        int ans=0;
        while(l<=r)
        {
            int mid=(l+r)>>1;
            if(check(mid))
            {
                ans=mid;
                r=mid-1;
            }
            else
                l=mid+1;
        }
        printf("%d\n",ans);
    }
}
