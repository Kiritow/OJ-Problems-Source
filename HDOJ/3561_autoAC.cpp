#include<iostream>  
#include<vector>  
#include<math.h>  
using namespace std;  
#define eps 1e-8  
const int maxn=105;  
struct point  
{  
    double x,y;  
};  
struct circle  
{  
    point p;  
    double r;  
}c[maxn];  
vector<point>v;  
double dis(point p1,point p2)  
{  
    return sqrt((p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y));  
}  
point intersection(point u1,point u2,point v1,point v2)  
{  
    point ret=u1;  
    double t=((u1.x-v1.x)*(v1.y-v2.y)-(u1.y-v1.y)*(v1.x-v2.x))/((u1.x-u2.x)*(v1.y-v2.y)-(u1.y-u2.y)*(v1.x-v2.x));  
    ret.x+=(u2.x-u1.x)*t;  
    ret.y+=(u2.y-u1.y)*t;  
    return ret;  
}  
int intersect_circle_circle(point c1,double r1,point c2,double r2)  
{  
    return dis(c1,c2)<r1+r2+eps&&dis(c1,c2)>fabs(r1-r2)-eps;  
}  
void intersection_line_circle(point c,double r,point l1,point l2,point &p1,point &p2)  
{  
    point p=c;  
    double t;  
    p.x+=l1.y-l2.y;  
    p.y+=l2.x-l1.x;  
    p=intersection(p,c,l1,l2);  
    t=sqrt(r*r-dis(p,c)*dis(p,c))/dis(l1,l2);  
    p1.x=p.x+(l2.x-l1.x)*t;  
    p1.y=p.y+(l2.y-l1.y)*t;  
    p2.x=p.x-(l2.x-l1.x)*t;  
    p2.y=p.x-(l2.y-l1.y)*t;  
}  
void intersection_circle_circle(point c1,double r1,point c2,double r2,point &p1,point &p2)  
{  
    point u,v;  
    double t;  
    t=(1+(r1*r1-r2*r2)/dis(c1,c2)/dis(c1,c2))/2;  
    u.x=c1.x+(c2.x-c1.x)*t;  
    u.y=c1.y+(c2.y-c1.y)*t;  
    v.x=u.x+c1.y-c2.y;  
    v.y=u.y-c1.x+c2.x;  
    intersection_line_circle(c1,r1,u,v,p1,p2);  
}  
int main()  
{  
    int n;  
    while(scanf("%d",&n)!=EOF)  
    {  
        int cnt=0;  
        v.clear();  
        for(int i=0;i<n;i++)  
        {  
            cin>>c[i].p.x>>c[i].p.y>>c[i].r;  
            v.push_back(c[i].p);  
        }  
        for(int i=0;i<n;i++)  
            for(int j=0;j<i;j++)  
                if(intersect_circle_circle(c[i].p,c[i].r,c[j].p,c[j].r))  
                {  
                    point x,y;  
                    intersection_circle_circle(c[i].p, c[i].r, c[j].p, c[j].r, x, y);  
                    v.push_back(x);v.push_back(y);  
                }  
        int maxt=-1;  
        for(int i=0;i<v.size();i++)  
        {  
            int cnt=0;  
            for(int j=0;j<n;j++)  
                cnt+=dis(v[i],c[j].p)<c[j].r+eps;  
            maxt=max(cnt,maxt);  
        }  
        cout<<maxt<<endl;  
    }  
    return 0;  
}
