#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
#define LL(x) (x<<1)
#define RR(x) (x<<1|1)
#define MID(a,b) (a+((b-a)>>1))
#define INF (1<<30)
const int N=10000+5;
typedef long long LL;
struct node
{
    int lft,rht;
    LL level,mx,flag,need;
    int mid(){return MID(lft,rht);}
    void init(){level=1;mx=0;flag=0;}
    void fun(LL valu)
    {
        mx+=level*valu;
        need-=valu;
        flag+=valu;
    }
};
int n,m,k;
LL ned[12];
struct Segtree
{
    node tree[N*4];
    void down(int ind)
    {
        if(tree[ind].flag)
        {
            tree[LL(ind)].fun(tree[ind].flag);
            tree[RR(ind)].fun(tree[ind].flag);
            tree[ind].flag=0;
        }
    }
    void up(int ind)
    {
        tree[ind].mx=max(tree[LL(ind)].mx,tree[RR(ind)].mx);
        tree[ind].level=max(tree[LL(ind)].level,tree[RR(ind)].level);
        tree[ind].need=min(tree[LL(ind)].need,tree[RR(ind)].need);
    }
    void build(int lft,int rht,int ind)
    {
        tree[ind].lft=lft;    tree[ind].rht=rht;
        tree[ind].init();     tree[ind].need=ned[2];
        if(lft!=rht)
        {
            int mid=tree[ind].mid();
            build(lft,mid,LL(ind));
            build(mid+1,rht,RR(ind));
        }
    }
    void updata(int st,int ed,int ind,int valu)
    {
        int lft=tree[ind].lft,rht=tree[ind].rht;
        if(st<=lft&&rht<=ed)
        {
            if(valu>=tree[ind].need)
            {
                if(lft==rht)
                {
                    LL &now=tree[ind].level;
                    tree[ind].mx+=now*valu;
                    while(tree[ind].mx>=ned[now+1]) now++;
                    LL tmp=ned[now+1]-tree[ind].mx;
                    tree[ind].need=tmp/now+(tmp%now!=0);
                }
                else 
                {
                    down(ind);
                    int mid=tree[ind].mid();
                    if(st<=mid) updata(st,ed,LL(ind),valu);
                    if(ed> mid) updata(st,ed,RR(ind),valu);
                    up(ind);
                }
            }
            else 
            {
                tree[ind].fun(valu);
            }
        }
        else 
        {
            down(ind);
            int mid=tree[ind].mid();
            if(st<=mid) updata(st,ed,LL(ind),valu);
            if(ed> mid) updata(st,ed,RR(ind),valu);
            up(ind);
        }
    }
    LL query(int st,int ed,int ind)
    {
        int lft=tree[ind].lft,rht=tree[ind].rht;
        if(st<=lft&&rht<=ed) return tree[ind].mx;
        else 
        {
            down(ind);
            int mid=tree[ind].mid();
            LL mx1=0,mx2=0;
            if(st<=mid) mx1=query(st,ed,LL(ind));
            if(ed> mid) mx2=query(st,ed,RR(ind));
            up(ind);
            return max(mx1,mx2);
        }
    }
}seg;
int main()
{
    int t,t_cnt=0;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d%d",&n,&k,&m);
        ned[1]=0; ned[k+1]=((LL)1<<60);
        for(int i=2;i<=k;i++) scanf("%I64d",&ned[i]);
        printf("Case %d:\n",++t_cnt);
        seg.build(1,n,1);
        while(m--)
        {
            char cmd[5];
            int a,b,c;
            scanf("%s",cmd);
            if(cmd[0]=='W')
            {
                scanf("%d%d%d",&a,&b,&c);
                seg.updata(a,b,1,c);
            }
            else 
            {
                scanf("%d%d",&a,&b);
                printf("%I64d\n",seg.query(a,b,1));
            }
        }
        puts("");
    }
    return 0;
}
