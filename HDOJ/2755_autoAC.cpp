#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;
#define PI 3.14159265358979
#define EPSILON 1e-6
typedef struct Point
{
    double x,y;
    Point(double a = 0,double b = 0):x(a),y(b) {}
    Point(const Point & p):x(p.x),y(p.y) {}
    friend Point operator + (const Point &p1, const Point & p2)
    {
        return Point(p1.x+p2.x,p1.y+p2.y);
    }
    Point & operator += (const Point & p)
    {
        x += p.x;
        y += p.y;
        return *this;
    }
    friend Point operator * (const Point & p, int u)
    {
        return Point(p.x*u,p.y*u);
    }
    Point & operator = (const Point & p)
    {
        x = p.x;
        y = p.y;
        return * this;
    }
    friend bool operator == (const Point & p1, const Point & p2)
    {
        if(fabs(p1.x-p2.x)<EPSILON && fabs(p1.y-p2.y)<EPSILON)
            return true;
        return false;
    }
}Vector;
struct Logo
{
    char str[6];
    int u;
};
Logo ls[1000];
int num;
char cmd[6];
Point Test(double theta, Vector v,Point pt,int j,int degree)
{
    if(cmd[0] == 'l')
    { theta+=degree; v = Vector(cos(PI*theta/180),sin(PI*theta/180));}
    else
    { theta-=degree; v = Vector(cos(PI*theta/180),sin(PI*theta/180)); } 
    for(int k = j+1; k<num; k++)
    {
        int t = ls[k].u;
        switch(ls[k].str[0])
        {
        case 'f': pt += v*t; break;
        case 'b': pt += v*(-t); break;
        case 'l': theta+=t; v = Vector(cos(PI*theta/180),sin(PI*theta/180));
            break;
        case 'r': theta-=t; v = Vector(cos(PI*theta/180),sin(PI*theta/180));
            break;
        }
    }
    return pt;
}
int main()
{
    int test,i,j,k,t;
    char unit[128];
    while(scanf("%d",&test)==1)
    {
        for(i = 0; i<test; i++)
        {
            scanf("%d",&num);
            Point pt;
            Vector v(1,0);
            Vector vx;
            double theta = 0.0;
            for(j = 0; j<num; j++)
            {
                scanf("%s %s",cmd,unit);
                if(unit[0] == '?')
                    break;
                t = atoi(unit);
                switch(cmd[0])
                {
                case 'f': pt += v*t; break;
                case 'b': pt += v*(-t); break;
                case 'l': theta+=t; v = Vector(cos(PI*theta/180),sin(PI*theta/180));
                    break;
                case 'r': theta-=t; v = Vector(cos(PI*theta/180),sin(PI*theta/180));
                    break;
                }
            }
            for(k = j+1; k<num; k++)
            {
                scanf("%s %d",ls[k].str,&ls[k].u);
            }
            if(cmd[0] == 'l' || cmd[0] == 'r')
            {
                for(int degree = 0; degree < 360; degree++)
                {
                    if(Test(theta,v,pt,j,degree) == Point(0.0,0.0) )
                    {
                        printf("%d\n",degree);
                        break;
                    }
                }
            }
            else
            {
                vx = v;
                for(k = j+1; k<num; k++)
                {
                    t = ls[k].u;
                    switch(ls[k].str[0])
                    {
                    case 'f': pt += v*t; break;
                    case 'b': pt += v*(-t); break;
                    case 'l': theta+=t; v = Vector(cos(PI*theta/180),sin(PI*theta/180));
                        break;
                    case 'r': theta-=t; v = Vector(cos(PI*theta/180),sin(PI*theta/180));
                        break;
                    }
                }
                printf("%d\n",(int)(sqrt(pt.x*pt.x + pt.y*pt.y)+0.5));
            }
        }
    }
    return 0;
}
