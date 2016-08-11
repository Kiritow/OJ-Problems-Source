#include<iostream>
using namespace std;
#define N 200005
int h,w,n;
struct
{
    int l,r;
    int num;
}tree[N*4];
int maxn(int h,int n)
{
    if(h>n)
        return n;
    else
        return h;
}
int maxx(int a,int b)
{
    if(a>b)
        return a;
    else
        return b;
}
void creat(int i,int l,int r)
{
    int mid=(l+r)/2;
    tree[i].l=l;
    tree[i].r=r;
    tree[i].num=w;
    if(l==r)
        return;
    creat(i*2,l,mid);
    creat(i*2+1,mid+1,r);
}
int gethigh(int len,int i)
{
    if(tree[i].l==tree[i].r)
    {
        tree[i].num-=len;
        return tree[i].l;
    }
    else
    {
        int sum1=0,sum2=0;
        if(len<=tree[i*2].num)            //当海报宽度小于树的左边区域宽度时，说明左边是可以贴海报的
            sum1=gethigh(len,i*2);
        else
            if(len<=tree[i*2+1].num)       //同理，右边也是如此......
                sum2=gethigh(len,i*2+1);
        tree[i].num=maxx(tree[i*2].num,tree[i*2+1].num);          //需要更新回溯
        return sum1+sum2;                                
    }
}
int main()
{
    while(scanf("%d%d%d",&h,&w,&n)>0)
    {
        int len;
        creat(1,1,maxn(h,n));
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&len);
            if(tree[1].num>=len)
                printf("%d\n",gethigh(len,1));
            else
                printf("-1\n");
        }
    }
    return 0;
}
