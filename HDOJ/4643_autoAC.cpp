#include<stdio.h>
#include<algorithm>
#include<math.h>
using namespace std;
const double eps=1e-11;
struct point
{
    double x,y;
}city[55],base[55];
int N,M,K,a,b;
struct node
{
    int i,j;
    point p;
    double dist;
}jiao[3000];
inline bool mo_ee(double x,double y)
{
    double ret=x-y;
    if(ret<0) ret=-ret;
    if(ret<eps) return 1;
    return 0;
}
inline bool mo_gg(double x,double y)  {   return x > y + eps;} // x > y   
inline bool mo_ll(double x,double y)  {   return x < y - eps;} // x < y   
inline bool mo_ge(double x,double y) {   return x > y - eps;} // x >= y   
inline bool mo_le(double x,double y) {   return x < y + eps;}     // x <= y   
inline double min(double a,double b)
{
    if(a<b) return a;
    return b;
}
inline double max(double a,double b)
{
    if(a>b) return a;
    return b;
}
point getxiang(point xiang)
{
    point a;
    if(mo_ee(xiang.x,0))
    {
        a.x=1;
        a.y=0;
        return a;
    }else if(mo_ee(xiang.y,0))
    {
        a.x=0;
        a.y=1;
        return a;
    }else
    {
        a.x=1;
        a.y=-1.0*xiang.x/xiang.y;
        return a;
    }
}
inline double mo_distance(point p1,point p2)
{
    return sqrt((p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y));
}
point mo_intersection(point u1,point u2,point v1,point v2)
{
    point ret=u1;
    double t=((u1.x-v1.x)*(v1.y-v2.y)-(u1.y-v1.y)*(v1.x-v2.x))
             /((u1.x-u2.x)*(v1.y-v2.y)-(u1.y-u2.y)*(v1.x-v2.x));
    ret.x+=(u2.x-u1.x)*t;
    ret.y+=(u2.y-u1.y)*t;
    return ret;
}
int segjiao(point &ji,point a,point b,point c,point d)
{
    ji=mo_intersection(a,b,c,d);
    if(mo_ll(ji.x,min(c.x,d.x))) return 0;
    if(mo_ll(ji.y,min(c.y,d.y))) return 0;
    if(mo_gg(ji.x,max(c.x,d.x))) return 0;
    if(mo_gg(ji.y,max(c.y,d.y))) return 0;
    return 1;
}
node jiaojiao(int a,int b,int ii,int jj)
{
    node cur;
    point xiang1,xiang2;
    xiang1.x=city[b].x-city[a].x,xiang1.y=city[b].y-city[a].y;
    xiang2.x=base[jj].x-base[ii].x,xiang2.y=base[jj].y-base[ii].y;
    if(mo_ee(xiang1.x*xiang2.x,xiang1.y*xiang2.y))
    {
        cur.i=-1;
        return cur;
    }
    xiang2=getxiang(xiang2);
    point zhong;
    zhong.x=(base[ii].x+base[jj].x)/2,zhong.y=(base[ii].y+base[jj].y)/2;
    point zhongxia;
    zhongxia.x=zhong.x+xiang2.x;
    zhongxia.y=zhong.y+xiang2.y;
    point jiaodian;
    int jjao=segjiao(jiaodian,zhong,zhongxia,city[a],city[b]);
    if(jjao==0)
    {
        cur.i=-1;
        return cur;
    }
    cur.p=jiaodian;
    cur.i=ii;
    cur.j=jj;
    cur.dist=mo_distance(jiaodian,city[a]);
    return cur;
}
bool cmp(const node &aa,const node &bb)
{
    if(mo_ee(aa.dist,bb.dist))
    {
        point temp;
        temp.x=(base[aa.i].x+base[aa.j].x)/2;
        temp.y=(base[aa.i].y+base[aa.j].y)/2;
        double dist1=mo_distance(aa.p,temp);
        temp.x=(base[bb.i].x+base[bb.j].x)/2;
        temp.y=(base[bb.i].y+base[bb.j].y)/2;
        double dist2=mo_distance(bb.p,temp);
        return mo_ll(dist1,dist2);
    }
    return mo_ll(aa.dist,bb.dist);
}
inline int nextno(int j,int no)
{
    if(jiao[j].i==no) return jiao[j].j;
    if(jiao[j].j==no) return jiao[j].i;
    return no;
}
int main()
{
    int i,j,ncase;
    while(scanf("%d%d",&N,&M)!=EOF)
    {
        for(i=1;i<=N;++i)
        {
            scanf("%lf%lf",&city[i].x,&city[i].y);
        }
        for(i=1;i<=M;++i)
        {
            scanf("%lf%lf",&base[i].x,&base[i].y);
        }
        scanf("%d",&K);
        for(ncase=0;ncase<K;++ncase)
        {
            int yong=0;
            scanf("%d%d",&a,&b);
            for(i=1;i<=M;++i)
            {
                for(j=i+1;j<=M;++j)
                {
                    if(i==j) continue;
                    node cur=jiaojiao(a,b,i,j);
                    if(cur.i<0)
                    {
                        continue;
                    }else
                    {
                        jiao[yong++]=cur;
                    }
                }
            }
            sort(jiao,jiao+yong,cmp);
            double mindist=-1;
            int minno;
            for(i=1;i<=M;++i)
            {
                double disttemp=sqrt((city[a].x-base[i].x)*(city[a].x-base[i].x)+(city[a].y-base[i].y)*(city[a].y-base[i].y));
                if(mindist<0||mo_ll(disttemp,mindist))
                {
                    mindist=disttemp;
                    minno=i;
                }
            }
            int dang=minno,ret=0;
            for(i=0;i<yong;++i)
            {
                int xinno=nextno(i,dang);
                if(xinno!=dang)
                {
                    dang=xinno;
                    ret++;
                }
            }
            printf("%d\n",ret);
        }
    }
    return 0;
}
