#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
const int L = 1000000+10;
int k,n;
int ans[L],len;
struct node
{
    int l,r,n,lazy;
} a[L<<2];
void set_up(int i)
{
    a[i].n = max(a[2*i].n,a[2*i+1].n);
}
void set_down(int i)
{
    if(a[i].lazy)
    {
        a[2*i].n += a[i].lazy;
        a[2*i].lazy+=a[i].lazy;
        a[2*i+1].n += a[i].lazy;
        a[2*i+1].lazy+=a[i].lazy;
        a[i].lazy = 0;
    }
}
void init(int l,int r,int i)
{
    a[i].l = l;
    a[i].r = r;
    a[i].n = 0;
    a[i].lazy = 0;
    if(l!=r)
    {
        int mid = (l+r)>>1;
        init(l,mid,2*i);
        init(mid+1,r,2*i+1);
    }
}
void insert(int l,int r,int i)
{
    if(a[i].l == l && a[i].r == r)
    {
        a[i].n++;
        a[i].lazy++;
        return;
    }
    set_down(i);
    int mid = (a[i].l+a[i].r)>>1;
    if(r<=mid)
        insert(l,r,2*i);
    else if(l>mid)
        insert(l,r,2*i+1);
    else
    {
        insert(l,mid,2*i);
        insert(mid+1,r,2*i+1);
    }
    set_up(i);
}
int query(int l,int r,int i)
{
    if(a[i].l == l && a[i].r == r)
        return a[i].n;
    set_down(i);
    int mid = (a[i].l+a[i].r)>>1;
    if(r<=mid)
        return query(l,r,2*i);
    else if(l>mid)
        return query(l,r,2*i+1);
    else
        return max(query(l,mid,2*i),query(mid+1,r,2*i+1));
}
int main()
{
    int t,cas = 1,i,a,b;
    for(scanf("%d",&t); t--;)
    {
        len = 0;
        scanf("%d%d",&k,&n);
        init(1,1000000,1);
        for(i = 1; i<=n; i++)
        {
            scanf("%d%d",&a,&b);
            b--;
            if(query(a,b,1)<k)
            {
                ans[len++] = i;
                insert(a,b,1);
            }
        }
        printf("Case %d:\n",cas++);
        for(i = 0; i<len; i++)
            printf("%d ",ans[i]);
        printf("\n\n");
    }
    return 0;
}
