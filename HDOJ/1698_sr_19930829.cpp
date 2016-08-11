#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
const int maxn=100002;
int col[maxn<<2];//用来标记每个节点，为0则表示没有标记，否则为标记，以颜色的价值作为标记。
int sum[maxn<<2];//求和

void PushUp(int rt)//向上更新和
{
    sum[rt]=sum[rt<<1]+sum[rt<<1|1];
}

void PushDown(int rt,int m)//对某一个区间进行改变，如果被标记了，在查询的时候就得把改变传给子节点，因为查询的并不一定是当前区间
{//m为区间长度
    if(col[rt])//已经标记过，该区间被改变过
    {
        col[rt<<1]=col[rt<<1|1]=col[rt];//标记子节点
        sum[rt<<1]=(m-(m>>1))*col[rt];//更新左儿子的和
        sum[rt<<1|1]=(m>>1)*col[rt];//更新右儿子的和
        col[rt]=0;
    }
}

void build(int l,int r,int rt)
{
    col[rt]=0;//初始化为所有节点均未标记
    sum[rt]=1;//初始值为1
    if(l==r)
        return;
    int m=(l+r)>>1;
    build(lson);
    build(rson);
}

void update(int L,int R,int c,int l,int r,int rt)
{
    if(L<=l&&r<=R)
    {
        col[rt]=c;
        sum[rt]=c*(r-l+1);//更新代表某个区间的节点和，该节点不一定是叶子节点
        return ;
    }
    PushDown(rt,r-l+1);//向下传递
    int m=(l+r)>>1;
    if(L<=m)
        update(L,R,c,lson);//更新左儿子
    if(R>m)
        update(L,R,c,rson);//更新右儿子
    PushUp(rt);//向上传递更新和
}
int main()
{
    int k;cin>>k;
    int n,c,add,a,b;
    for(int i=1;i<=k;i++)
    {
        scanf("%d",&n);
        build(1,n,1);
        scanf("%d",&c);
        for(int j=1;j<=c;j++)
        {
            scanf("%d%d%d",&a,&b,&add);
            update(a,b,add,1,n,1);
        }
        printf("Case %d: The total value of the hook is %d.\n",i,sum[1]);
    }
    return 0;
}
