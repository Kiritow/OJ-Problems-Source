#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

const int L = 111111;
int n,m,s[L];

struct node
{
    int l,r,c;//左右边界与连续的长度
    int ln,rn;//左右边界的值
    int ls,rs,ms,;//左右最大LCIS，和区间最大LCIS
} a[L<<2];

void pushup(int i)
{
    a[i].ls = a[2*i].ls;
    a[i].rs = a[2*i+1].rs;
    a[i].ln = a[2*i].ln;
    a[i].rn = a[2*i+1].rn;
    a[i].ms = max(a[2*i].ms,a[2*i+1].ms);
    if(a[2*i].rn<a[2*i+1].ln)//如果左子树的右边界值小于右子树的左边界值，要合并左子树的右边界和右子树的左边界进行计算
    {
        if(a[2*i].ls == a[2*i].c)
            a[i].ls+=a[2*i+1].ls;
        if(a[2*i+1].rs == a[2*i+1].c)
            a[i].rs+=a[2*i].rs;
        a[i].ms = max(a[i].ms,a[2*i].rs+a[2*i+1].ls);
    }
}

void init(int l,int r,int i)//建树
{
    a[i].l = l;
    a[i].r = r;
    a[i].c = r-l+1;
    if(l == r)
    {
        a[i].ln = a[i].rn = s[l];
        a[i].ls = a[i].rs = a[i].ms = 1;
        return;
    }
    int mid = (a[i].l+a[i].r)>>1;
    init(l,mid,2*i);
    init(mid+1,r,2*i+1);
    pushup(i);
}

void insert(int i,int t,int m)
{
    if(a[i].l == a[i].r)
    {
        a[i].ln = a[i].rn = m;
        return;
    }
    int mid = (a[i].l+a[i].r)>>1;
    if(t<=mid)
        insert(2*i,t,m);
    if(t>mid)
        insert(2*i+1,t,m);
    pushup(i);
}

int query(int l,int r,int i)//查询最大的LCIS
{
    if(a[i].l>=l && a[i].r<=r)
    {
        return a[i].ms;
    }
    int mid = (a[i].l+a[i].r)>>1,ans = 0;
    if(l<=mid)
        ans = max(ans,query(l,r,2*i));
    if(r>mid)
        ans = max(ans,query(l,r,2*i+1));
    if(a[2*i].rn < a[2*i+1].ln)
        ans = max(ans , min(mid-l+1,a[2*i].rs)+min(r-mid,a[2*i+1].ls));
    return ans;
}


int main()
{
    int t,i,l,r;
    char str[5];
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        for(i = 1; i<=n; i++)
            scanf("%d",&s[i]);
        init(1,n,1);
        while(m--)
        {
            scanf("%s%d%d",str,&l,&r);
            if(str[0] == 'Q')
                printf("%d\n",query(l+1,r+1,1));
            else
                insert(1,l+1,r);
        }
    }

    return 0;
}
