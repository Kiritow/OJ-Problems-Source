#include <iostream>
#include <cstdio>
#include <cmath>
#define IP 3.1415926
using namespace std;
int main()
{
    double r, h;
    while( scanf("%lf %lf", &h, &r) != EOF)
    {
        double ans = asin(0.01 * r / (4 * h));
        printf("%0.2lf\n", 180 * ans / IP);
    }
}
