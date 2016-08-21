#include<iostream>
#include<algorithm>
#include<cmath>
const int MAXNUM=20000;
const double PI=atan2(0.0,-1.0);
using namespace std;
int N,K;
struct Point
{
    int x,y;
    double angle,dist;
}ps[MAXNUM];
double minangle;
bool found[MAXNUM];
int cmp(Point a,Point b)
{
    if(a.angle==b.angle)
        return a.dist<b.dist;
    else
        return a.angle<b.angle;
}
void calMin()
{
    if(K==0||K==1)
    {
        minangle=0.00;
        return;
    }
    minangle=1e100;
    int end,scount,start;
    int size=N+N;
    double newm;
    for(int i=0;i<N;i++)
    {
        end=-1; scount=0;start=0;
        for(int j=0;j<size;j++)
            if(ps[j].dist<=ps[i].dist)
            {
                scount++;
                if(scount==K)
                {
                   end=j;
                   break;
                }
            }
        if(end!=-1)
        {
            scount--;end--;
            for(int q=end+1;q<size;q++)
            {
                if(ps[q].dist<=ps[i].dist)
                {
                   scount++;
                   while(ps[start].dist>ps[i].dist)start++;
                   if(scount>K)
                   {
                    scount--;
                    start++;
                    while(ps[start].dist>ps[i].dist)start++;
                   }
                }
                if((q-start+1)<=N)
                {
                    newm=(ps[q].angle-ps[start].angle)*ps[i].dist;
                    if(newm<minangle)
                        minangle=newm;
                }
            }
        }           
    }
}
int main()
{
    int casenum=1;
        scanf("%d%d",&N,&K);
    while(N||K)
    {
       for(int i=0;i<N;i++)
       {
           scanf("%d%d",&ps[i].x,&ps[i].y);
           ps[i].angle=atan2((double)(ps[i].y),(double)(ps[i].x));
           ps[i].dist=ps[i].x*ps[i].x+ps[i].y*ps[i].y;
       }           
       sort(ps,ps+N,cmp);
       for(int j=0;j<N;j++)
        {
        ps[N+j]=ps[j];
        ps[N+j].angle+=PI+PI;
        }       
       calMin();
       printf("Case #%d: %.2lf\n",casenum++,minangle/2.0);
       scanf("%d%d",&N,&K);
    }
    return 0;
}
