#include<stdio.h>
#include<iostream>
#include<math.h>
#include<algorithm>
#define PI  3.1415926
using namespace std;
struct list
{
    double x;
    double y;
    int r;
    int pos;
}point[500001],tu[500001],pp;
int tops,num;
int cmp1(struct list a,struct list b)
{
    if(a.y!=b.y)return a.y<b.y;
    else return a.x<b.x;
}
int cmp2(struct list a,struct list b)
{
    if((a.x-point[0].x)*(b.y-point[0].y)==(b.x-point[0].x)*(a.y-point[0].y))
        return ((a.x-point[0].x)*(a.x-point[0].x)+(a.y-point[0].y)*(a.y-point[0].y))<((point[0].x-b.x)*(point[0].x-b.x)+(point[0].y-b.y)*(point[0].y-b.y));
    return (a.x-point[0].x)*(b.y-point[0].y)>(b.x-point[0].x)*(a.y-point[0].y);
}
int ts;
void yuan(int x,int y,int r)
{
    pp.r=r;
    for(int i=0;i<500;i++)
    {
        double du;
        du=(double)2.0*PI*i/500.0;
        pp.x=1.0*x+1.0*r*cos(du);
        pp.y=1.0*y+1.0*r*sin(du);
        pp.pos=ts;
        point[tops++]=pp;
    }
}
int pan(int z,int b,int a)
{
    double x1,y1,x2,y2;
    if(a<0)return 1;
    x1=tu[b].x-tu[a].x;
    y1=tu[b].y-tu[a].y;
    x2=point[z].x-tu[b].x;
    y2=point[z].y-tu[b].y;
    if(x1*y2>x2*y1)return 1;
    return 0;
}
double len(struct list p1,struct list p2)
{
    return (double)sqrt(1.0*((p1.x-p2.x)*(p1.x-p2.x)+1.0*(p1.y-p2.y)*(p1.y-p2.y)));
}
void init(int n,int m)
{
    int i,j;
    tops=0;
    int a,b,c;
    ts=0;
    for(i=0;i<n;i++)
    {
        scanf("%d%d%d",&a,&b,&c);
        ts++;
        yuan(a,b,c);
    }
    for(i=0;i<m;i++)
    for(j=0;j<3;j++)
    {
        scanf("%lf%lf",&point[tops].x,&point[tops].y);
        point[tops].pos=0;
        tops++;
    }
}
void jiantu()
{
    int i;
    sort(point,point+tops,cmp1);
    sort(point+1,point+tops,cmp2);
    tu[0]=point[0];
    tu[1]=point[1];
    tu[2]=point[2];
    num=3;
    for(i=3;i<tops;i++)
    {
        while(!pan(i,num-1,num-2))num--;
        tu[num++]=point[i];
    }
}
void print()
{
    double lens;
    int i;
    lens=0.0;
    for(i=0;i<num;i++)
    {
        if(tu[i].pos>0&&(tu[i].pos==tu[(i+1)%num].pos))
        {
            lens+=1.0*tu[i].r*2*PI/500.0;
        }
        else
        lens+=len(tu[i],tu[(i+1)%num]);
    }
    printf("%.5lf\n",lens);
}
int main()
{
    int n,m;
    while(~scanf("%d%d",&n,&m))
    {
        init(n,m);
        jiantu();
        print();
    }
    return 0;
}
