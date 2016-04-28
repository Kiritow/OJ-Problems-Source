#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>

using namespace std;

const double PI=3.1415926;

typedef struct
{
    double x,y;
    int vis;
}point_struct;

point_struct point[105];

int main()
{
    //Initialize
    memset(point,0,sizeof(point_struct)*105);
    double r;
    double line_length=0;
    int n;
    //Input
    scanf("%d %lf",&n,&r);
    for(int i=0;i<n;i++)
    {
        scanf("%lf %lf",&point[i].x,&point[i].y);
    }
    //Now start with the first point, currently : All of point.vis is 0 (false)
    //At first we need some value to save states.
    int isfirst=1;//It's the first point
    double min_distance;
    int min_distance_point;
    int checked_point=0;
    int checking_point=0;
    while(checked_point<n-1)
    {
        //Now is checking "checking_point"
        isfirst=1;
        for(int i=0;i<n;i++)
        {
            if(point[i].vis||i==checking_point)
            {
                continue;
            }
            if(isfirst)
            {
                isfirst=0;
                min_distance=sqrt((point[checking_point].x-point[i].x)*(point[checking_point].x-point[i].x)+(point[checking_point].y-point[i].y)*(point[checking_point].y-point[i].y));
                min_distance_point=i;
            }
            else
            {
                double this_distance=sqrt((point[checking_point].x-point[i].x)*(point[checking_point].x-point[i].x)+(point[checking_point].y-point[i].y)*(point[checking_point].y-point[i].y));
                if(min_distance>this_distance)
                {
                    min_distance=this_distance;
                    min_distance_point=i;
                }
            }
        }
        point[checking_point].vis=1;
        line_length+=min_distance;
        checking_point=min_distance_point;
        checked_point++;
    }
    double final_distance=sqrt((point[checking_point].x-point[0].x)*(point[checking_point].x-point[0].x)+(point[checking_point].y-point[0].y)*(point[checking_point].y-point[0].y));
    line_length+=final_distance;
    line_length+=2*PI*r;
    printf("%.2lf\n",line_length);
    return 0;
}
