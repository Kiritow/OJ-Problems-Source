#include <cstdio>
#include <cstring>
#include <cmath>
#include <queue>
#include <iostream>
#include <algorithm>
using namespace std;
#define lowbit(x) (x&(-x))
const int maxn=5e4+10;
struct node{
    double a,b;
    int num;
}e[maxn];
double l,r;
int c[maxn];
int cmp1(node x,node y)
{
    if(x.a==y.a)return x.b<y.b;
    return x.a<y.a;
}
int cmp2(node x,node y)
{
    if(x.b==y.b)return x.a>y.a;
    return x.b>y.b;
}
void add(int x,int val)
{
    while(x<maxn)
    {
        c[x]+=val;
        x+=lowbit(x);
    }
}
int sum(int x)
{
    int s=0;
    while(x>0)
    {
        s+=c[x];
        x-=lowbit(x);
    }
    return s;
}
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        int t,tt,i,j,ans=0;
        double x1,y1,x2,y2,k,b;
        t=tt=0;
        scanf("%lf%lf",&l,&r);
        for(i=0;i<n;i++)
        {
            scanf("%lf%lf%lf%lf",&x1,&y1,&x2,&y2);
            if(x1==x2)
            {
                if(x1<r&&x1>l)tt++;
                continue;
            }
            k=(y2-y1)/(x2-x1);
            b=y1-k*x1;
            e[t].a=l*k+b;
            e[t++].b=r*k+b;
        }
        sort(e,e+t,cmp1);
        for(i=0;i<t;i++)
            e[i].num=i+1;
        sort(e,e+t,cmp2);
        memset(c,0,sizeof(c));
        for(i=0;i<t;i++)
        {
            add(e[i].num,1);
            ans+=sum(e[i].num-1);
        }
        printf("%d\n",ans+tt*t);
    }
    return 0;
}
