#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
const double dd = sqrt(2.0)/2*10;
int ti;
double x,y;
double d;
double dis(double x1, double y1, double x2, double y2)
{
    return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}
void dfs(double x1,double y1,int dir,int tt)
{
    double aa;
    dir %= 8;
    aa=dis(x1,y1,x,y);
    if(aa < d)
    {
        d = aa;
    }
    if(tt==ti ||(aa-10*(ti-tt)>d))
    {
        return ;
    }
    if(dir == 0)
    {
        dfs(x1+10,y1,dir,tt+1);
    }
    else if(dir == 1)
    {
        dfs(x1+dd,y1-dd,dir,tt+1);
    }
    else if(dir == 2)
    {
        dfs(x1,y1-10,dir,tt+1);
    }
    else if(dir == 3)
    {
        dfs(x1-dd,y1-dd,dir,tt+1);
    }
    else if(dir == 4)
    {
        dfs(x1-10,y1,dir,tt+1);
    }
    else if(dir == 5)
    {
        dfs(x1-dd,y1+dd,dir,tt+1);
    }
    else if(dir == 6)
    {
        dfs(x1,y1+10,dir,tt+1);
    }
    else if(dir == 7)
    {
        dfs(x1+dd,y1+dd,dir,tt+1);
    }
    dfs(x1,y1,dir+1,tt+1);
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%lf%lf",&ti,&x,&y);
        d = dis(0,0,x,y);
        dfs(0,0,0,0);
        printf("%.6lf\n",d);
    }
    return 0;
}
