#include<cstdio>
#include<cstring>
#include<iostream>
#include<cmath>
#define eps 1e-6
#define pi acos(-1)
using namespace std;
struct node
{
    double x,y;
};
node p[4];
double getdis(node p1,node p2)
{
    return sqrt((p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y));
}
double getang(double a,double b,double c)
{
    double ang= (a*a+b*b-c*c)/(2*a*b);
    return acos(ang);
}
int main()
{
    char str[1000];
    while(gets(str)&&strcmp(str,"END")!=0)
    {
        sscanf(str,"%lf%lf",&p[0].x,&p[0].y);
        scanf("%lf%lf%lf%lf",&p[1].x,&p[1].y,&p[2].x,&p[2].y);
        getchar();
        double dis1=getdis(p[0],p[1]);
        double dis2=getdis(p[1],p[2]);
        double dis3=getdis(p[0],p[2]);
        double ang1=getang(dis1,dis2,dis3);
        double ang2=getang(dis2,dis3,dis1);
        double ang3=getang(dis1,dis3,dis2);
        for(int i=3; i<=1000; i++)
        {
            if(ang1*i/pi-(int)(ang1*i/pi+eps)<eps && ang2*i/pi-(int)(ang2*i/pi+eps)<eps && ang3*i/pi-(int)(ang3*i/pi+eps)<eps)
            {
                printf("%d\n",i);
                break;
            }
        }
    }
    return 0;
}
