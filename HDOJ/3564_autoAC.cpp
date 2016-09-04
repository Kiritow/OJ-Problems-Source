#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
int n,s[1000000],dp[1000000],ans[1000000],len;
struct node
{
    int l,r,n;
} a[1000000];
void init(int l,int r,int i)
{
    a[i].l = l;
    a[i].r = r;
    if(l == r)
    {
        a[i].n = 1;
        return ;
    }
    int mid = (l+r)>>1;
    init(l,mid,i*2);
    init(mid+1,r,i*2+1);
    a[i].n = a[i*2].n+a[i*2+1].n;
}
void insert(int i,int x,int m)
{
    if(a[i].l == a[i].r)
    {
        ans[m] = a[i].l;
        a[i].n=0;
        return;
    }
    a[i].n--;
    if(x<=a[2*i].n)
        insert(2*i,x,m);
    else
        insert(2*i+1,x-a[2*i].n,m);
}
int bin(int k)
{
    int l = 1,r = len;
    while(l<=r)
    {
        int mid = (l+r)>>1;
        if(k>dp[mid])
            l = mid+1;
        else
            r = mid-1;
    }
    return l;
}
int main()
{
    int t,i,j,cas = 1;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(i = 1; i<=n; i++)
        {
            scanf("%d",&s[i]);
            dp[i] = 0;
        }
        init(1,n,1);
        printf("Case #%d:\n",cas++);
        for(i = n; i>0; i--)
            insert(1,s[i]+1,i);
        len = 0;
        for(i = 1; i<=n; i++)//LIS()
        {
            int k = bin(ans[i]);
            len = max(len,k);
            dp[k] = ans[i];
            printf("%d\n",len);
        }
        printf("\n");
    }
    return 0;
}
