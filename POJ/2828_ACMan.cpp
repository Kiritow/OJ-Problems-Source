#include<stdio.h>
#include<string.h>

#define lson l, m, rt<<1
#define rson m+1, r, rt<<1|1
#define mid int m = (l + r)>>1
#define maxn 200000

int sum[maxn<<2],pos[maxn],val[maxn],ans[maxn<<2];//ans储存插入的值；

void push_up(int rt)
{
    sum [rt] = sum[rt<<1]+sum[rt<<1|1];
}
void build(int l, int r, int rt)
{
    sum[rt]=r-l+1;
    if(l == r)return;
    mid;
    build(lson);
    build(rson);
}
void update(int pos, int val, int l, int r, int rt)
{
    if(l == r){ans[rt]=val;sum[rt]--;return;}
    mid;
    if(pos <= sum[rt<<1])update(pos, val, lson); //根据左右儿子空位的多少和插入数据的位置比较来确定插入哪个儿子
    else update(pos -sum[rt<<1], val, rson);
    push_up(rt);
}
void print(int l, int r, int rt)
{
    if(l == r){printf("%d ",ans[rt]);return;}
    mid;
    print(lson);
    print(rson);
}
int main()
{
    int n,i;
    while(~scanf("%d",&n))
    {
        for(i=0;i<n;i++)
            scanf("%d%d",&pos[i],&val[i]);
        build(1, n ,1);
        for(i=n-1;i>=0;i--)
            update(pos[i]+1, val[i], 1, n, 1);
        print(1, n, 1);
        printf("\n");
    }
    return 0;
}
