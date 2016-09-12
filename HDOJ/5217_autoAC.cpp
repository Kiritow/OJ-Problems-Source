#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
#define N 200010
char str[N];
struct Node
{
    Node(int l=0,int r=0){lnum=l;rnum=r;}
    int lnum,rnum;
}node[N<<2];
void pushup(int rt)
{
    int matched=min(node[rt<<1].lnum,node[rt<<1|1].rnum);
    node[rt].lnum=node[rt<<1].lnum+node[rt<<1|1].lnum-matched;
    node[rt].rnum=node[rt<<1].rnum+node[rt<<1|1].rnum-matched;
}
void build(int l,int r,int rt)
{
    if(l==r)
    {
        node[rt].lnum=node[rt].rnum=0;
        if(str[l]=='(')node[rt].lnum=1;
        else node[rt].rnum=1;
        return ;
    }
    int mid=(l+r)/2;
    build(l,mid,rt<<1);
    build(mid+1,r,rt<<1|1);
    pushup(rt);
}
Node query(int L,int R,int l,int r,int rt)
{
    if(L<=l&&r<=R)
        return node[rt];
    int mid=(l+r)/2;
    Node ret;
    if(L<=mid)ret=query(L,R,l,mid,rt<<1);
    if(R>mid)
    {
        Node tmp=query(L,R,mid+1,r,rt<<1|1);
        int matched=min(ret.lnum,tmp.rnum);
        ret.lnum+=tmp.lnum-matched;
        ret.rnum+=tmp.rnum-matched;
    }
    return ret;
}
void change(int x,int l,int r,int rt)
{
    if(l==r&&r==x)
    {
        swap(node[rt].lnum,node[rt].rnum);
        return;
    }
    int mid=(l+r)/2;
    if(x<=mid)change(x,l,mid,rt<<1);
    else change(x,mid+1,r,rt<<1|1);
    pushup(rt);
    return;
}
int lsearch(int L,int R,int K,Node &Val,int l,int r,int rt)
{
    if(L<=l&&r<=R)
    {
        int mid=(l+r)/2;
        if(l==r)
        {
            int matched=min(Val.lnum,node[rt].rnum);
            int lnum=Val.lnum+node[rt].lnum-matched;
            int rnum=Val.rnum+node[rt].rnum-matched;
            if(rnum==K)return l;
            else
            {
                Val.lnum=lnum;
                Val.rnum=rnum;
                return 0;
            }
        }
        int matched=min(Val.lnum,node[rt<<1].rnum);
        int lnum=Val.lnum+node[rt<<1].lnum-matched;
        int rnum=Val.rnum+node[rt<<1].rnum-matched;
        if(K<=rnum)
        {
            return lsearch(L,R,K,Val,l,mid,rt<<1);
        }
        else
        {
            Val.lnum=lnum;
            Val.rnum=rnum;
            return lsearch(L,R,K,Val,mid+1,r,rt<<1|1);
        }
    }
    int mid=(l+r)/2;
    if(R<=mid)return lsearch(L,R,K,Val,l,mid,rt<<1);
    if(L>mid)return lsearch(L,R,K,Val,mid+1,r,rt<<1|1);
    int ret=lsearch(L,R,K,Val,l,mid,rt<<1);
    if(ret)return ret;
    else return lsearch(L,R,K,Val,mid+1,r,rt<<1|1);
}
int rsearch(int L,int R,int K,Node &Val,int l,int r,int rt)
{
     if(L<=l&&r<=R)
    {
        int mid=(l+r)/2;
        if(l==r)
        {
             int matched=min(Val.rnum,node[rt].lnum);
             int lnum=Val.lnum+node[rt].lnum-matched;
             int rnum=Val.rnum+node[rt].rnum-matched;
             if(lnum==K)return l;
            else
            {
                Val.lnum=lnum;
                Val.rnum=rnum;
                return 0;
            }
        }
        int matched=min(Val.rnum,node[rt<<1|1].lnum);
        int lnum=Val.lnum+node[rt<<1|1].lnum-matched;
        int rnum=Val.rnum+node[rt<<1|1].rnum-matched;
        if(K<=lnum)
        {
            return rsearch(L,R,K,Val,mid+1,r,rt<<1|1);
        }
        else
        {
            Val.lnum=lnum;
            Val.rnum=rnum;
            return rsearch(L,R,K,Val,l,mid,rt<<1);
        }
    }
    int mid=(l+r)/2;
    if(R<=mid)return rsearch(L,R,K,Val,l,mid,rt<<1);
    if(L>mid)return rsearch(L,R,K,Val,mid+1,r,rt<<1|1);
    int ret=rsearch(L,R,K,Val,mid+1,r,rt<<1|1);
    if(ret)return ret;
    else return rsearch(L,R,K,Val,l,mid,rt<<1);
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,q;
        scanf("%d%d",&n,&q);
        scanf(" %s",&str[1]);
        int len=strlen(&str[1]);
        build(1,len,1);
        for(int i=0;i<q;i++)
        {
            int type;
            scanf("%d",&type);
            if(type==1)
            {
                int x;
                scanf("%d",&x);
                change(x,1,len,1);
            }
            else
            {
                int a,b,k;
                scanf("%d%d%d",&a,&b,&k);
                Node tp(0,0),qry=query(a,b,1,len,1);
                int cnt=qry.lnum+qry.rnum;
                if(cnt<k){printf("-1\n");continue;}
                if(k<=qry.rnum)
                {
                    printf("%d\n",lsearch(a,b,k,tp,1,len,1));
                }
                else
                {
                    printf("%d\n",rsearch(a,b,cnt-k+1,tp,1,len,1));
                }
            }
        }
    }
}
