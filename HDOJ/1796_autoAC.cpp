#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int a[15];
int n,m;
int gcd(int a,int b)
{
    if(!b)
        return a;
    else
        return gcd(b,a%b);
}
int ans;
int kk;
void dfs(int val,int s,int k,int cnt)
{
    if(cnt>k)
        return;
    if(k==cnt)
    {
        if(cnt%2)
            ans+=m/val;
        else
            ans-=m/val;
        return;
    }
    for(int i=s+1;i<=kk;i++)
        dfs(val/gcd(a[i],val)*a[i],i,k,cnt+1);
}
int main()
{
    int i;
    while(scanf("%d%d",&m,&n)!=EOF)
    {
        m--;
        kk=0;
        for(i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
            if(a[i])
                a[++kk]=a[i];
        }
        ans=0;
        for(i=1;i<=kk;i++)
            dfs(1,0,i,0);
        printf("%d\n",ans);
    }
    return 0;
}
