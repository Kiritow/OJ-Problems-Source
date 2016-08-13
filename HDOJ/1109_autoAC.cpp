#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>
#include <set>
#include<map>
#include<ctime>
using namespace std;
const int NUM=20;
const int RAD=1000;
struct point
{
    double x,y,val;
    point(){}
    point(double _x,double _y):x(_x),y(_y){}
}p[10001],May[NUM],e1,e2;
int n;
double X,Y;
double dis(point a,point b)
{
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
double judge(point t)
{
    double len;
    len=1LL<<45;
    for(int i=0;i<n;i++)
    len=min(len,dis(t,p[i]));
    return len;
}
double Rand(){return rand()%(RAD+1)/(1.0*RAD);}
point Rand_point(point a,point b)
{
    double xx=a.x+(b.x-a.x)*Rand();
    double  yy=a.y+(b.y-a.y)*Rand();
    point tmp=point(xx,yy);
    tmp.val=judge(tmp);
    return tmp;
}
void solve(double D)
{
    May[0]=point(0,0);
    May[1]=point(X,Y);
    May[2]=point(0,Y);
    May[3]=point(X,0);
    for(int i=4;i<NUM;i++)
    May[i]=Rand_point(May[0],May[1]);
    while(D>0.01)
    {
        for(int i=0;i<NUM;i++)
        for(int j=0;j<NUM;j++)
        {
            point tmp=Rand_point(point(max(0.0,May[i].x-D),max(0.0,May[i].y-D)),point(min(X,May[i].x+D),min(Y,May[i].y+D)));
            if(tmp.val>May[i].val)
            {
                May[i]=tmp;
            }
        }
        D*=0.9;
    }
    point ans;
    ans.val=0;
    for(int i=0;i<NUM;i++)
    if(May[i].val>ans.val)
    ans=May[i];
    printf("The safest point is (%.1f, %.1f).\n",ans.x,ans.y);
}
int main()
{
    srand(time(0));
    e2=point(0,0);
    int Case;
    scanf("%d",&Case);
    while(Case--)
    {
        scanf("%lf%lf%d",&X,&Y,&n);
        for(int i=0;i<n;i++)
        {
        scanf("%lf%lf",&p[i].x,&p[i].y);
        }
        solve(max(Y,X));
    }
}
