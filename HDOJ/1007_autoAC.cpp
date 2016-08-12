#include <algorithm>   
using namespace std;  
#include <stdio.h>   
#include <math.h>   
struct Point  
{  
    double x;  
    double y;  
};  
int num;  
Point points[100001];  
Point assist[100001];  
inline bool cmpx(Point a ,Point b )   
{   
    return a.x < b.x;  
}   
inline bool cmpy(Point a ,Point b )   
{   
    return a.y < b.y;  
}   
inline double space(Point a, Point b)  
{  
    return (a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y);  
}  
inline double minBinary(double a,double b)  
{  
    return a<b?a:b;  
}  
double binarySlove(int l,int r,Point* p)  
{  
    if(r-l==1)  
        return space(p[l],p[r]);  
    if(r-l==2)  
        return minBinary(minBinary(space(p[l],p[l+1]),space(p[l],p[r])),space(p[l+1],p[r]));  
    int half=(l+r)/2;  
    double min=minBinary(binarySlove(l,half,p),binarySlove(half+1,r,p));  
    double sqrtMin=sqrt(min);  
    int cnt=0;  
    for (int i=l;i<=r;i++)  
        if(points[i].x<points[half].x+sqrtMin&&points[i].x>points[half].x-sqrtMin)  
            assist[cnt++]=points[i];  
    sort(assist,assist+cnt,cmpy);  
    for (int i=0;i<cnt;i++)  
        for (int j=i+1;j<cnt;j++)  
        {  
            if(assist[j].y-assist[i].y>sqrtMin)  
                break;  
            min=minBinary(min,space(assist[i],assist[j]));  
        }  
        return min;  
}  
int main()  
{    
    while(scanf("%d",&num)!=EOF&&num)  
    {  
        int min=0;  
        for (int i=0;i<num;i++)  
        {  
            scanf("%lf%lf",&(points[i].x),&(points[i].y));  
        }  
        sort(points,points+num,cmpx);  
        double result=binarySlove(0,num-1,points);  
        printf("%.2lf\n",sqrt(result)/2);  
    }  
    return 0;  
}
