#include <cstdio>
#include <cmath>
using namespace std;
struct point
{
    double x,y,z;
};
int main()
{
    int n,i;
    double xmin,xmax,ymin,ymax,zmin,zmax,xx,yy,zz,r;
    point points[10],ball;
    scanf("%d",&n);
    while(n--)
    {
        for(i=0;i<8;i++)
        scanf("%lf%lf%lf",&points[i].x,&points[i].y,&points[i].z);
        scanf("%lf%lf%lf%lf",&ball.x,&ball.y,&ball.z,&r);
        xmin=ymin=zmin=1000000;xmax=ymax=zmax=-1;
        for(i=0;i<8;i++)
        {
            if(xmin>points[i].x) xmin=points[i].x;
            if(xmax<points[i].x) xmax=points[i].x;
            if(ymin>points[i].y) ymin=points[i].y;
            if(ymax<points[i].y) ymax=points[i].y;
            if(zmin>points[i].z) zmin=points[i].z;
            if(zmax<points[i].z) zmax=points[i].z;
        }
        if(ball.x<xmin) xx=xmin;
        else if(ball.x>xmax) xx=xmax;
        else xx=ball.x;
        if(ball.y<ymin) yy=ymin;
        else if(ball.y>ymax) yy=ymax;
        else yy=ball.y;
        if(ball.z<xmin) zz=zmin;
        else if(ball.z>zmax) zz=zmax;
        else zz=ball.z;
        double diss=sqrt((xx-ball.x)*(xx-ball.x)+(yy-ball.y)*(yy-ball.y)+(zz-ball.z)*(zz-ball.z));
        if(diss>r) printf("No\n");
        else printf("Yes\n");
    }
    return 0;
}
