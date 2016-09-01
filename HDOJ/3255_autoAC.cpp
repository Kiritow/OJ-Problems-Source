#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define MAX 150105
#define lch(i) ((i)<<1)
#define rch(i) ((i)<<1|1)
struct rec{
    __int64 x1,y1,x2,y2,v;
};
struct segment{
    __int64 l,r,h,val;
};
struct tree{
    int l,r,cnt,sum;
    int mid()
    { return (l+r)>>1;  }
};
typedef struct rec rec;
typedef struct segment segment;
typedef struct tree tree;
rec rr[MAX];
segment ss[MAX];
tree tt[MAX];
__int64 pos[MAX]; 
__int64 v[MAX]; 
int N,M; 
int cmp_rec(rec a ,rec b)
{ return a.v < b.v; }
int cmp_segment(segment a , segment b)
{ return a.h < b.h; }
void input()
{
    scanf("%d%d",&N,&M);
    for(int i=1; i<=M; i++) scanf("%I64d",&v[i]);
    for(int i=0; i<N; i++)
    {
        int k;
        scanf("%I64d%I64d%I64d%I64d%d",&rr[i].x1, &rr[i].y1, &rr[i].x2, &rr[i].y2, &k);
        rr[i].v=v[k];
    }
}
void build(int l ,int r ,int rt)
{
    tt[rt].l=l; tt[rt].r=r; 
    tt[rt].cnt=0; tt[rt].sum=0;
    if(l==r) return ; 
    int mid=tt[rt].mid();
    build(l, mid, lch(rt));
    build(mid+1, r, rch(rt));
}
int binary(int key ,int low, int high)
{
    int mid;
    while(low<=high)
    {
        mid=(low+high)>>1;
        if(pos[mid]==key) return mid;
        else if(key < pos[mid]) high=mid-1;
        else low=mid+1;
    }
    return -1;
}
void cal(int rt)
{
    if(tt[rt].cnt) 
        tt[rt].sum=pos[tt[rt].r+1]-pos[tt[rt].l];
    else if(tt[rt].l==tt[rt].r)
        tt[rt].sum=0;
    else 
        tt[rt].sum=tt[lch(rt)].sum + tt[rch(rt)].sum;
}
void updata(int l , int r , int val ,int rt)
{
    if(tt[rt].l==l && tt[rt].r==r) 
    {
        tt[rt].cnt += val ; 
        cal(rt); 
        return ;
    }
    int mid=tt[rt].mid();
    if(r<=mid)
        updata(l,r,val,lch(rt));
    else if(l>mid)
        updata(l,r,val,rch(rt));
    else
    {
        updata(l,mid,val,lch(rt));
        updata(mid+1,r,val,rch(rt));
    }
    cal(rt);
}
__int64 solve(int nn)
{
    int m=0;
    for(int i=nn; i<N; i++)
    {
        ss[m].l=rr[i].x1;   ss[m].r=rr[i].x2;   ss[m].h=rr[i].y1;   ss[m].val=1;
        ss[m+1].l=rr[i].x1; ss[m+1].r=rr[i].x2; ss[m+1].h=rr[i].y2; ss[m+1].val=-1;
        pos[m]=rr[i].x1;    pos[m+1]=rr[i].x2;
        m+=2;
    }
    sort(pos,pos+m); 
    sort(ss,ss+m,cmp_segment); 
    int mm=1;
    for(int i=1; i<m; i++) 
        if(pos[i]!=pos[i-1])
            pos[mm++]=pos[i];    
    build(0,mm-1,1);
    __int64 ans=0,res=0;
    for(int i=0; i<m-1; i++) 
    {
        int l=binary(ss[i].l,0,mm-1);    
        int r=binary(ss[i].r,0,mm-1)-1;  
        if(l<=r) updata(l,r,ss[i].val,1);
        res += tt[1].sum * (ss[i+1].h-ss[i].h);
    }
    return res;
}
int main()
{
    int T;
    scanf("%d",&T);
    for(int t=1; t<=T; t++)
    {
        input();
        sort(rr,rr+N,cmp_rec);
        int s[MAX],kk;
        s[1]=0; kk=1;
        for(int i=1; i<N; i++) 
            if(rr[i].v!=rr[i-1].v)
                s[++kk]=i;        
        __int64 ans=0,res;
        for(int k=1; k<=kk; k++) 
        {
            res=solve(s[k]);
            if(k==1) ans += res * rr[s[k]].v;
            else     ans += res * ( rr[s[k]].v - rr[s[k-1]].v );
        }
        printf("Case %d: %I64d\n",t,ans);
    }
    return 0;
}
