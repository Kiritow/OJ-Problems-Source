#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

int h,w,n;
int ans;

struct node
{
    int l,r,n;
} a[1000000];

void init(int l,int r,int i,int w)//建树
{
    a[i].l=l;
    a[i].r=r;
    a[i].n=w;
    if(l!=r)
    {
        int mid=(l+r)/2;
        init(l,mid,2*i,w);
        init(mid+1,r,2*i+1,w);
    }
}

void insert(int i,int x)
{
    if(a[i].l == a[i].r)//到了叶子节点，叶子节点的值既是层数
    {
        a[i].n-=x;//该层宽度减少
        ans = a[i].l;
        return ;
    }
    if(x<=a[2*i].n)//符合要求搜左子树
        insert(2*i,x);
    else//否则右子树
        insert(2*i+1,x);
    a[i].n = max(a[2*i].n,a[2*i+1].n);//将左右子树里能放的最大长度存入父亲节点，进行更新
}

int main()
{
    int i,k;
    while(~scanf("%d%d%d",&h,&w,&n))
    {
       if(h>n)//根据题意，因为最多放n个公告，占用的最大高度也只有n，如果根据h的大小建树，由于h太大，这个树根本就建不起来，所以在这里就优化建树的高度
            h = n;
        init(1,h,1,w);
        ans = -1;
        for(i = 1; i<=n; i++)
        {
            scanf("%d",&k);
            if(a[1].n>=k)//如果这个公告没有超出公告板的长度，那么才能放入
                insert(1,k);
            printf("%d\n",ans);
            ans = -1;
        }
    }

    return 0;
}
