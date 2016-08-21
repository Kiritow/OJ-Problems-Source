#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <cstring>
#include <list>
#include <queue>
#include <stack>
#include <cmath>
using namespace std;
#define PF(x) (scanf("%d",&x))
#define PT(x,y) (scanf("%d%d",&x,&y))
#define PR(x) (printf("%d\n",x))
#define PRT(x,y)(printf("%d %d\n",x,y))
#define M 1000
int n;
struct P
{
    int x,y;
    void in()
    {
        PT(x,y);
    }
};
P ar[1000];
int mul(P a,P b,P c)
{
    return (a.x-c.x)*(b.y-c.y)-(b.x-c.x)*(a.y-c.y);
}
double area(P a,P b,P c)
{
    return fabs((double)mul(a,b,c))/2.0;
}
void init()
{
    while(scanf("%d",&n)!=EOF)
    {
        for(int i=0;i<n;i++)
            ar[i].in();
        double areas = 0.0;
        for(int i=0;i<n;i++)
            for(int j = i+1;j<n;j++)
                for(int k = j+1;k<n;k++)
                {
                    if(areas<area(ar[i],ar[j],ar[k]))
                        areas = area(ar[i],ar[j],ar[k]);
                }
                printf("%.1lf\n",areas);
    }
    return ;
}
int main()
{
    init();
    return 0;
}
