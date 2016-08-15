#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <vector>
using namespace std;
struct Point
{
    double x;
    double y;
};
Point p[3];
//姹㈢Н缁瀵瑰
double cross(Point O,Point A,Point B)
{
    return fabs((A.x - O.x) *  (B.y - O.y) - (B.x - O.x) * (A.y - O.y))/2;
}
bool judge()
{
    for(int i=0; i<3; i++)
    {
        if(p[i].x!=0 || p[i].y!=0)
        {
            return true;
        }
    }
    return false;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
#endif
    while(scanf(" %lf %lf %lf %lf %lf %lf",&p[0].x,&p[0].y,&p[1].x,&p[1].y,&p[2].x,&p[2].y) && judge())
    {
        double maxX = 0,minX = 150;
        double maxY = 0,minY = 150;
        for(int i=0; i<3; i++)
        {
            if(p[i].x>maxX)
                maxX = p[i].x;
            if(p[i].y>maxY)
                maxY = p[i].y;
            if(p[i].x<minX)
                minX = p[i].x;
            if(p[i].y<minY)
                minY = p[i].y;
        }
        //姹涓瑙褰㈢㈢Н
        double area = cross(p[0],p[1],p[2]);
        int num = 0;
        for(int i=ceil(minX); i<=floor(maxX); i++)
        {
            if(i <= 0 || i>=100)
            {
                continue;
            }
            for(int j=ceil(minY); j<=floor(maxY); j++)
            {
                if(j <= 0 || j>=100)
                {
                    continue;
                }
                double s = 0;
                Point temp;
                temp.x = i;
                temp.y = j;
                s += cross(temp,p[0],p[1]);
                s += cross(temp,p[1],p[2]);
                s += cross(temp,p[2],p[0]);
                if(fabs(area-s)<=1e-8)
                {
                    num++;
                }
            }
        }
        printf("%4d\n",num);
    }
}
