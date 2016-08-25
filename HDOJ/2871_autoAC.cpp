#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define MAXN 50010
struct node
{
    int left,right,sum,lazy,s,e,cnt,cover;
};
node tree[MAXN<<2];
inline void PushUp(int mid,int L,int R,int rt)
{
    tree[rt].left=tree[rt<<1].left;
    tree[rt].right=tree[rt<<1|1].right;
    if(tree[rt].left==mid-L+1)
        tree[rt].left+=tree[rt<<1|1].left;
    if(tree[rt].right==R-mid)
        tree[rt].right+=tree[rt<<1].right;
    tree[rt].sum=max(tree[rt<<1].sum,tree[rt<<1|1].sum);
    tree[rt].sum=max(tree[rt].sum,tree[rt<<1].right+tree[rt<<1|1].left);
}
inline void PushDown(int mid,int L,int R,int rt)
{
    if(tree[rt].lazy!=-1)
    {
        tree[rt<<1].lazy=tree[rt<<1|1].lazy=tree[rt].lazy;
        tree[rt<<1].sum=tree[rt<<1].left=tree[rt<<1].right=(mid-L+1)*tree[rt].lazy;
        tree[rt<<1|1].sum=tree[rt<<1|1].left=tree[rt<<1|1].right=(R-mid)*tree[rt].lazy;
        tree[rt<<1].s=tree[rt<<1|1].s=tree[rt].s;
        tree[rt<<1].e=tree[rt<<1|1].e=tree[rt].e;
        tree[rt].lazy=-1;
    }
}
void Update(int x,int y,int val,int L,int R,int rt)
{
    if(x<=L&&R<=y)
    {
        tree[rt].lazy=val;
        tree[rt].sum=tree[rt].left=tree[rt].right=val*(R-L+1);
        if(val)
            tree[rt].s=tree[rt].e=-1;
        else
        {
            tree[rt].s=x;
            tree[rt].e=y;
        }
    }
    else
    {
        int mid=(L+R)>>1;
        PushDown(mid,L,R,rt);
        if(x<=mid)
            Update(x,y,val,L,mid,rt<<1);
        if(y>mid)
            Update(x,y,val,mid+1,R,rt<<1|1);
        PushUp(mid,L,R,rt);
    }
}
int New(int x,int L,int R,int rt)
{
    if(L==R)
        return L;
    int mid=(L+R)>>1;
    PushDown(mid,L,R,rt);
    if(tree[rt<<1].sum>=x)
        return New(x,L,mid,rt<<1);
    else if(tree[rt<<1].right+tree[rt<<1|1].left>=x)
        return mid-tree[rt<<1].right+1;
    else
        return New(x,mid+1,R,rt<<1|1);
}
int Free(int x,int L,int R,int rt)
{
    if(L==R)
        return rt;
    int mid=(L+R)>>1;
    PushDown(mid,L,R,rt);
    if(x<=mid)
        return Free(x,L,mid,rt<<1);
    else
        return Free(x,mid+1,R,rt<<1|1);
}
inline void CountUp(int rt)
{
    tree[rt].cnt=tree[rt<<1].cnt+tree[rt<<1|1].cnt;
}
inline void CountDown(int rt)
{
    if(tree[rt].cover)
    {
        tree[rt<<1].cnt=tree[rt<<1|1].cnt=0;
        tree[rt<<1].cover=tree[rt<<1|1].cover=1;
        tree[rt].cover=0;
    }
}
int Get(int x,int L,int R,int rt)
{
    if(L==R)
        return L;
    else
    {
        int mid=(L+R)>>1;
        CountDown(rt);
        if(tree[rt<<1].cnt>=x)
            return Get(x,L,mid,rt<<1);
        else
            return Get(x-tree[rt<<1].cnt,mid+1,R,rt<<1|1);
    }
}
void Count(int x,int val,int L,int R,int rt)
{
    if(L==R)
        tree[rt].cnt=val;
    else
    {
        int mid=(L+R)>>1;
        CountDown(rt);
        if(x<=mid)
            Count(x,val,L,mid,rt<<1);
        else
            Count(x,val,mid+1,R,rt<<1|1);
        CountUp(rt);
    }
}
inline void Reset(int n)
{
    Update(1,n,1,1,n,1);
    tree[1].cover=1;
    tree[1].cnt=0;
}
int main()
{
    char s[12];
    int n,m,x,y;
    while(~scanf("%d%d",&n,&m))
    {
        Reset(n);
        while(m--)
        {
            scanf(" %s",s);
            if(!strcmp(s,"Reset"))
            {
                Reset(n);
                puts("Reset Now");
            }
            else if(!strcmp(s,"New"))
            {
                scanf("%d",&x);
                if(tree[1].sum>=x)
                {
                    y=New(x,1,n,1);
                    printf("New at %d\n",y);
                    Count(y,1,1,n,1);
                    Update(y,y+x-1,0,1,n,1);
                }
                else
                    puts("Reject New");
            }
            else if(!strcmp(s,"Free"))
            {
                scanf("%d",&x);
                y=Free(x,1,n,1);
                if(tree[y].s<0)
                    puts("Reject Free");
                else
                {
                    printf("Free from %d to %d\n",tree[y].s,tree[y].e);
                    Count(tree[y].s,0,1,n,1);
                    Update(tree[y].s,tree[y].e,1,1,n,1);
                }
            }
            else
            {
                scanf("%d",&x);
                if(x>tree[1].cnt)
                    puts("Reject Get");
                else
                    printf("Get at %d\n",Get(x,1,n,1));
            }
        }
        putchar('\n');
    }
    return 0;
}
