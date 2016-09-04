#include<stdlib.h>
#include <math.h>
#include<stdio.h>
#include <algorithm>
using namespace std;
#define maxN 300
const double eps = 1e-8;
typedef struct
{
    double x,y;
}point;
point l[maxN*2];
double direction(point p1,point p2, point p3)
{
    return (p3.x-p1.x)*(p2.y-p1.y)-(p2.x-p1.x)*(p3.y-p1.y);
}
bool online(point p1,point p2,point p3)
{
    return (min(p1.x,p2.x)<=p3.x&&p3.x<=max(p1.x,p2.x))&&(min(p1.y,p2.y)<=p3.y&&p3.y<=max(p1.y,p2.y));
}
bool insect(point p1,point p2,point p3,point p4)
{
    double d3=direction(p1,p2,p3);
    double d4=direction(p1,p2,p4);
    if(d3*d4<0)
        return true;
    else if(d3==0) return true;
    else if(d4==0) return true;
    return false ;
}
int main()
{
    int cnt = 0;
    int N,n,i,j,k;
    bool flag;
    scanf("%d",&N);
    while(N--)
    {
        cnt ++;
        scanf("%d",&n);
        for(i=0;i<2*n-1;i+=2)
        {
            scanf("%lf%lf%lf%lf",&l[i].x,&l[i].y,&l[i+1].x,&l[i+1].y);
        }
        bool issame = true;
        flag = false;
        for(i=0;i< 2*n -1 && flag==false;i++)
            for(j=i+1;j < 2*n && flag==false;j++)
                {
                    if (fabs(l[i].x-l[j].x) <= eps && fabs(l[i].y-l[j].y) <= eps)
                        continue;
                    issame = false;
                    flag=true;
                    for(k=0;k<2*n-1;k+=2)
                    {
                        if(insect(l[i],l[j],l[k],l[k+1]) == false)
                         {flag=false;
                           break;}
                    }
                }
        if(flag==true || issame)
            {printf("Yes\n");}
        else printf("No\n");
    }
    return 0;
}
