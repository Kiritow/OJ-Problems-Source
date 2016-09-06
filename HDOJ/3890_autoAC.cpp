#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;
struct point
{
    int x,y,flag,tag;
    double c;
}p[141000];
struct tree
{
    double c;
    int num;
}T1[141000],T2[21000];
int x[141000],y[141000],xnum,ynum;
bool cmp(point a,point b)
{
    if(a.x!=b.x) return a.x<b.x;
    if(a.y!=b.y) return a.y<b.y;
    return a.flag<b.flag;
}
void Add(int index,int x,int y,int flag,int tag)
{
    p[index].x=x,p[index].y=y;
    p[index].flag=flag,p[index].tag=tag;
}
int Lowbit(int t)
{
    return t^(t&(t-1));
}
void AddNum(int index,double c)
{
    int i;
    for(i=index;i<=ynum;i+=Lowbit(i))
    {
        T1[i].num++;
        T1[i].c+=c;
    }
}
void Query(int index,int now)
{
    int i;
    for(i=index;i>0;i-=Lowbit(i))
    {
        T2[p[now].flag].c=T2[p[now].flag].c+T1[i].c*p[now].tag;
        T2[p[now].flag].num=T2[p[now].flag].num+T1[i].num*p[now].tag;
    }
}
int BiSearch(int now)
{
    int l=0,r=ynum-1,mid;
    while(l<=r)
    {
        mid=(l+r)/2;
        if(y[mid]>now) r=mid-1;
        else l=mid+1;
    }
    return l;
}
int main()
{
    int n,m,i,j,x1,y1,x2,y2;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        for(xnum=0,ynum=0,i=0;i<n;i++)
        {
            scanf("%d%d%lf",&p[i].x,&p[i].y,&p[i].c);
            p[i].flag=0;
            x[xnum++]=p[i].x;
            y[ynum++]=p[i].y;
        }
        for(i=0;i<m;i++)
        {
            scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
            x[xnum++]=x2,x[xnum++]=x1-1;
            y[ynum++]=y2,y[ynum++]=y1-1;
            Add(n+4*i,x1-1,y1-1,i+1,1);
            Add(n+4*i+1,x1-1,y2,i+1,-1);
            Add(n+4*i+2,x2,y1-1,i+1,-1);
            Add(n+4*i+3,x2,y2,i+1,1);
            T2[i+1].num=0;
            T2[i+1].c=0;
        }
        sort(x,x+xnum);
        sort(y,y+ynum);
        for(j=1,i=1;i<xnum;i++)
            if(x[i]!=x[i-1])
                x[j++]=x[i];
        xnum=j;
        for(j=1,i=1;i<ynum;i++)
            if(y[i]!=y[i-1])
                y[j++]=y[i];
        ynum=j;
        for(i=0;i<=ynum+1;i++)
        {
            T1[i].c=0;
            T1[i].num=0;
        }
        sort(p,p+n+4*m,cmp);
        for(y1=0,i=0;i<n+4*m;i++)
        {
            if(!p[i].flag)
            {
                y1=BiSearch(p[i].y);
                AddNum(y1,p[i].c);
            }
            else
            {
                y1=BiSearch(p[i].y);
                Query(y1,i);
            }
        }
        for(i=1;i<=m;i++)
        {
            if(!T2[i].num)
                printf("0.00/0\n");
            else
                printf("%.2lf/%d\n",T2[i].c,T2[i].num);
        }
    }
    return 0;
}
