#include<iostream>
#include<cmath>
using namespace std;
struct point{
    double x,y,z;
    point(double xx=0,double yy=0,double zz=0){ 
        x=xx,y=yy,z=zz;
    }
    point operator ^(double h){
        return point(x*h,y*h,z*h);
    }
    double operator ^(point h){ 
        return x*h.x+y*h.y+z*h.z;
    }
    point operator +(point h){
        return point(x+h.x,y+h.y,z+h.z);
    }
    point operator -(point h){
        return point(x-h.x,y-h.y,z-h.z);
    }
    point operator *(point b){ 
        return point(y*b.z-b.y*z, z*b.x-b.z*x, x*b.y-b.x*y);
    }
    double len2()const{
        return x*x+y*y+z*z;
    }
    double len()const{
        return sqrt(len2());
    }
    point turnlen(double l)const {  
        double r=l/len();
        return point(x*r,y*r,z*r);
    }
    void input()
    {
        scanf("%lf%lf%lf",&x,&y,&z);
    }
}p1,p2,ans;
struct sphere{
    point c;
    double r;
    void input(){
        c.input();
        scanf("%lf",&r);
    }
}sph[110];
int n;
const double eps=1e-8;
int sgn(double x)
{
    if(fabs(x)<eps) return 0;
    return x>0?1:-1;
}
bool intersection(sphere s,point p1,point p2,point &c)
{
    double d=((p1-s.c)*(p2-s.c)).len()/(p1-p2).len();
    if(sgn(d-s.r)>=0)
        return false;    
    point pp=(sgn(d)==0? s.c:s.c+((p1-s.c)*(p2-s.c)*(p1-p2)).turnlen(d) );     if(sgn((pp-p1)^(p2-p1))<=0)  
        return false;
    c=pp+(p1-p2).turnlen(sqrt(s.r*s.r-d*d));
    return true;
}
point reflection(point p1,point rep,point c) 
{
    double d=((rep-p1)*(c-p1)).len()/(rep-c).len();
    return p1+((rep-p1)*(c-p1)*(rep-c)).turnlen(d*2.0);
}
void compute()
{
    while(true){
        point c;
        int k=-1;
        for(int i=0;i<n;i++)  
        {
            point tmp;
            if(intersection(sph[i],p1,p2,tmp)){
                if(k==-1 || sgn((tmp-p1).len()-(c-p1).len())<0){
                    c=tmp;
                    k=i;
                }
            }
        }
        if(k==-1)
            break;
        p2=reflection(p1,sph[k].c,c);  
        p1=c;  
    }
    ans=p1;
}
int main()
{
    while(scanf("%d",&n),n)
    {
        p1=point();
        p2.input();
        for(int i=0;i<n;i++)
            sph[i].input();
        compute();
        printf("%.8lf %.8lf %.8lf\n",ans.x,ans.y,ans.z);
    }
    return 0;
}
