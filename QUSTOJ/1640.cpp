#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;
//We have to say this is a mash-up of terrible code. But at least, it solves the problem.
typedef struct
{
    double x,y;
} point;
typedef struct
{
    double k,b;
} line_s;
point inc[3];
line_s line[3];
int main()
{
    int x,y;
    int count=0;
    while(scanf("%lf %lf %lf %lf %lf %lf",&inc[0].x,&inc[0].y,&inc[1].x,&inc[1].y,&inc[2].x,&inc[2].y)==6)
    {
        line[0].k=(inc[1].y-inc[0].y)/(inc[1].x-inc[0].x);
        line[0].b=inc[0].y-line[0].k*inc[0].x;
        line[1].k=(inc[2].y-inc[1].y)/(inc[2].x-inc[1].x);
        line[1].b=inc[1].y-line[1].k*inc[1].x;
        line[2].k=(inc[0].y-inc[2].y)/(inc[0].x-inc[2].x);
        line[2].b=inc[2].y-line[2].k*inc[2].x;
        if(!(inc[0].x!=inc[1].x&&inc[1].x!=inc[2].x&&inc[0].x!=inc[2].x))
        {
            if(inc[0].x==inc[1].x)
            {
                count=0;
                for(x=1; x<100; x++)
                {
                    for(y=1; y<100; y++)
                    {
                        if((x-inc[0].x)*(inc[2].x-inc[0].x)>=0)
                        {
                            if((y-line[1].k*x-line[1].b)*(inc[0].y-line[1].k*inc[0].x-line[1].b)>=0)
                            {
                                if((y-line[2].k*x-line[2].b)*(inc[1].y-line[2].k*inc[1].x-line[2].b)>=0)
                                {
                                    count++;
                                }
                            }
                        }
                    }
                }
            }
            else if(inc[1].x==inc[2].x)
            {
                count=0;
                for(x=1; x<100; x++)
                {
                    for(y=1; y<100; y++)
                    {
                        if((x-inc[1].x)*(inc[0].x-inc[1].x)>=0)
                        {
                            if((y-line[0].k*x-line[0].b)*(inc[2].y-line[0].k*inc[2].x-line[0].b)>=0)
                            {
                                if((y-line[2].k*x-line[2].b)*(inc[1].y-line[2].k*inc[1].x-line[2].b)>=0)
                                {
                                    count++;
                                }
                            }
                        }
                    }
                }
            }
            else if(inc[2].x==inc[0].x)
            {
                count=0;
                for(x=1; x<100; x++)
                {
                    for(y=1; y<100; y++)
                    {
                        if((x-inc[2].x)*(inc[1].x-inc[2].x)>=0)
                        {
                            if((y-line[0].k*x-line[0].b)*(inc[2].y-line[0].k*inc[2].x-line[0].b)>=0)
                            {
                                if((y-line[1].k*x-line[1].b)*(inc[0].y-line[1].k*inc[0].x-line[1].b)>=0)
                                {
                                    count++;
                                }
                            }
                        }
                    }
                }
            }
            printf("%d\n",count);
            continue;
        }
        count=0;
        for(x=1; x<100; x++)
        {
            for(y=1; y<100; y++)
            {
                if((y-line[0].k*x-line[0].b)*(inc[2].y-line[0].k*inc[2].x-line[0].b)>=0)
                {
                    if((y-line[1].k*x-line[1].b)*(inc[0].y-line[1].k*inc[0].x-line[1].b)>=0)
                    {
                        if((y-line[2].k*x-line[2].b)*(inc[1].y-line[2].k*inc[1].x-line[2].b)>=0)
                        {
                            count++;
                        }
                    }
                }
            }
        }
        printf("%d\n",count);
    }
}
