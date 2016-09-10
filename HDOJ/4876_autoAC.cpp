#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
int n,k,l,r;
int vis[500],a[500],tem[500],s[500];
void set(int len,int sum)
{
    vis[sum] = 1;
    if(len == k)
        return ;
    set(len+1,sum^tem[len]);
    set(len+1,sum);
}
int check()
{
    memset(vis,0,sizeof(vis));
    set(0,0);
    for(int i = l; i<=r; i++)
        if(!vis[i])
            return 0;
    return 1;
}
void solve()
{
    if(!check()) return ;
    int i,j;
    for(i = 0; i<k; i++)
        s[i] = tem[i];
    do
    {
        memset(vis,0,sizeof(vis));
        for(i = 0; i<k; i++)
        {
            int ans = 0;
            for(j = i; j<k+i; j++)
            {
                ans^=s[(j%k)];
                vis[ans] = 1;
            }
        }
        for(i = l; i<=128; i++)
            if(!vis[i])
            {
                r = max(r,i-1);
                break;
            }
    }
    while(next_permutation(s+1,s+k));
}
void dfs(int now,int len)
{
    if(len == k)
    {
        solve();
        return ;
    }
    for(int i = now; i<n; i++)
    {
        tem[len] = a[i];
        dfs(i+1,len+1);
    }
}
int main()
{
    int i,j;
    while(~scanf("%d%d%d",&n,&k,&l))
    {
        for(i = 0; i<n; i++)
            scanf("%d",&a[i]);
        sort(a,a+n);
        r = l-1;
        dfs(0,0);
        if(r<l)
            printf("0\n");
        else
            printf("%d\n",r);
    }
    return 0;
}
