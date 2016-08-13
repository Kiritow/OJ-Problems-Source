#include<iostream>
#include<stdio.h>
using namespace std;
const int Max = 110;
struct Point
{
    double x, y;
};
struct Segment
{
    Point s, e;
};
Segment s[Max];
double product(Point &a, Point &b, Point &c)
{
    double x1, y1, x2, y2;
    x1 = a.x - c.x, y1 = a.y - c.y;
    x2 = b.x - c.x, y2 = b.y - c.y;
    return x1 * y2 - y1 * x2;
}
bool intersect(Segment &a, Segment &b)
{
    return product(a.s, a.e, b.s) * product(a.s, a.e, b.e) <= 0 && 
        product(b.s, b.e, a.s) * product(b.s, b.e, a.e) <= 0;
}
int main()
{
    int n, cnt;
    while(scanf("%d", &n) && n)
    {
        for(int i=0; i<n; i++) 
            scanf("%lf %lf %lf %lf", &s[i].s.x, &s[i].s.y, &s[i].e.x, &s[i].e.y);
        cnt = 0;
        for(int i=0; i<n; i++)
            for(int j=i+1; j<n; j++)
                if(intersect(s[i], s[j])) cnt ++;
        printf("%d\n", cnt);
    }
    return 0;
}
