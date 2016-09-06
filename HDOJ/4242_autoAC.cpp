#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
char a[20];
double funx(double x1,double y1,double x2,double y2,double x3,double y3,double x4,double y4){
    return (y4-y2+(y1-y2)*x2/(x1-x2)-(y3-y4)*x4/(x3-x4))/((y1-y2)/(x1-x2)-(y3-y4)/(x3-x4));
}
double funy(double x1,double y1,double x2,double y2,double x3,double y3,double x4,double y4){
    return y2+(y1-y2)*(funx(x1,y1,x2,y2,x3,y3,x4,y4)-x2)/(x1-x2);
}
double area(double x0,double y0,double x1,double y1,double x2,double y2){
    return fabs(x0*y1+x2*y0+x1*y2-x2*y1-x0*y2-x1*y0);
}
double dis(double x1,double y1,double x2,double y2){
    return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}
int main(){
    double ax=0.0,ay=0.0,bx,by=0.0,cx,cy,dx,dy;
    double aax,aay,bbx,bby,ccx,ccy,ddx,ddy;
    int t,n;
    while(~scanf("%d",&t)){
        while(t--){
            scanf("%d%lf%lf%lf%lf%lf",&n,&bx,&cx,&cy,&dx,&dy);
            aax=(bx+cx)/2;
            aay=(by+cy)/2;
            bbx=(cx+dx)/2;
            bby=(cy+dy)/2;
            ccx=(ax+dx)/2;
            ccy=(ay+dy)/2;
            ddx=(ax+bx)/2;
            ddy=(ay+by)/2;
            double x1=funx(ax,ay,aax,aay,bx,by,bbx,bby);
            double y1=funy(ax,ay,aax,aay,bx,by,bbx,bby);
            double x2=funx(bx,by,bbx,bby,cx,cy,ccx,ccy);
            double y2=funy(bx,by,bbx,bby,cx,cy,ccx,ccy);
            double x3=funx(cx,cy,ccx,ccy,dx,dy,ddx,ddy);
            double y3=funy(cx,cy,ccx,ccy,dx,dy,ddx,ddy);
            double x4=funx(ax,ay,aax,aay,dx,dy,ddx,ddy);
            double y4=funy(ax,ay,aax,aay,dx,dy,ddx,ddy);
            double al,bob,chas,dave,emily;
            al  =area(ax,ay,bx,by,x1,y1)/2/160;
            bob =area(bx,by,cx,cy,x2,y2)/2/160;
            chas=area(cx,cy,dx,dy,x3,y3)/2/160;
            dave=area(dx,dy,ax,ay,x4,y4)/2/160;
            double all=(area(ax,ay,bx,by,cx,cy)+area(ax,ay,cx,cy,dx,dy))/2/160;
            emily=all-al-bob-chas-dave;
            int d=(int)ceil((dis(x1,y1,x2,y2)+dis(x2,y2,x3,y3)+dis(x3,y3,x4,y4)+dis(x4,y4,x1,y1))*16.5);
            printf("%d %.3f %.3f %.3f %.3f %.3f %d\n",n,al,bob,chas,dave,emily,d);
        }
    }
    return 0;
}
