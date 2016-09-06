#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <math.h>
#include <stdlib.h>
using namespace std;
struct Point
{
    int x,y;
    Point(int _x = 0,int _y = 0)
    {
        x = _x; y = _y;
    }
};
int dis(Point a,Point b)
{
    return abs(a.x-b.x)+abs(a.y-b.y);
}
Point p1[2000];
Point p2[2000];
char str[50][50];
int main()
{
    int n,m;
    while(scanf("%d%d",&n,&m) == 2)
    {
        if(n == 0 && m == 0)break;
        for(int i = 0;i < n;i++)
            scanf("%s",str[i]);
        int uN = 0, vN = 0;
        for(int i = 0;i < n;i++)
            for(int j = 0;j < m;j++)
            {
                if(str[i][j] == 'H')p1[uN++] = Point(i,j);
                else if(str[i][j] == 'C') p2[vN++] = Point(i,j);
            }
        int ans1 = 0,ans2 = 0;
        int Min = 100000000;
        for(int i = 0;i < uN;i++)
            for(int j = 0;j < vN;j++)
            {
                if(dis(p1[i],p2[j]) < Min)
                {
                    Min = dis(p1[i],p2[j]);
                    ans1 = i;
                    ans2 = j;
                }
            }
        printf("%d %d %d %d\n",p1[ans1].x,p1[ans1].y,p2[ans2].x,p2[ans2].y);
    }
    return 0;
}
