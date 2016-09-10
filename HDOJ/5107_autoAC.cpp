#include "stdio.h"
#include "string.h"
#include "algorithm"
#include "map"
using namespace std;
map<int,int>mp;
struct Mark
{
    int x,y,h,op,id;
}mark[60010];
struct Ans
{
    int w; 
    int h[11];
}ans;
struct node
{
    int l,r;
    Ans x;
}data[300010];
int y[60010],pri[30010];
bool cmp_mark(Mark a,Mark b)
{
    if (a.x!=b.x) return a.x<b.x;
    else
        if (a.y!=b.y) return a.y<b.y;
    else
        return a.op<b.op;
}
Ans Merge(Ans a,Ans b)
{
    int i,j,k;
    Ans c;
    i=j=k=1;
    while ((i<=a.w || j<=b.w) && k<=10)
    {
       if (j > b.w || (i <= a.w && a.h[i] < b.h[j]) )
            c.h[k++] = a.h[i++];
        else
            c.h[k++] = b.h[j++];
    }
    c.w=k-1;
    return c;
}
void build(int l,int r,int k)
{
    int mid;
    data[k].l=l;
    data[k].r=r;
    data[k].x.w=0;
    if(l==r) return ;
    mid=(l+r)/2;
    build(l,mid,k*2);
    build(mid+1,r,k*2+1);
}
void updata(int n,int op,int k)
{
    int mid;
    if (data[k].l==n && data[k].r==n)
    {
        data[k].x.w++;
        data[k].x.h[data[k].x.w]=op;
        sort(data[k].x.h+1,data[k].x.h+1+data[k].x.w);
        return ;
    }
    mid=(data[k].l+data[k].r)/2;
    if (n<=mid) updata(n,op,k*2);
    else if (n>mid) updata(n,op,k*2+1);
    data[k].x=Merge(data[k*2].x,data[k*2+1].x);
}
Ans query(int l,int r,int k)
{
    int mid;
    if (data[k].l==l && data[k].r==r)
        return data[k].x;
    mid=(data[k].l+data[k].r)/2;
    if (r<=mid) return query(l,r,k*2);
    else
        if (l>mid) return query(l,r,k*2+1);
    else
        return Merge(query(l,mid,k*2),query(mid+1,r,k*2+1));
}
int main()
{
    int n,m,i,cnt,temp;
    while (scanf("%d%d",&n,&m)!=EOF)
    {
        for (i=0;i<n;i++)
        {
            scanf("%d%d%d",&mark[i].x,&mark[i].y,&mark[i].h);
            y[i]=mark[i].y;
            mark[i].op=1;
        }
        for (i=n;i<n+m;i++)
        {
            scanf("%d%d%d",&mark[i].x,&mark[i].y,&mark[i].h);
            mark[i].id=i-n;
            y[i]=mark[i].y;
            mark[i].op=2;
        }
        cnt=n+m;
        sort(y,y+cnt);
        sort(mark,mark+cnt,cmp_mark);
        temp=unique(y,y+cnt)-y; 
        for (i=0;i<temp;i++)
            mp[y[i]]=i;
        build(0,temp-1,1);
        for (i=0;i<cnt;i++)
        {
            if (mark[i].op==1)
                updata(mp[mark[i].y],mark[i].h,1);
            else
            {
                ans=query(0,mp[mark[i].y],1); 
                if (mark[i].h<=ans.w)
                pri[mark[i].id]=ans.h[mark[i].h];
                else
                    pri[mark[i].id]=-1;
            }
        }
        for (i=0;i<m;i++)
            printf("%d\n",pri[i]);
    }
    return 0;
}
