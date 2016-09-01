#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;

struct Point {
    double x, y;
} P[20010], o;

int cmp(Point a, Point b) {
    if(a.x == b.x)
        return a.y < b.y;
    return a.x < b.x;
}

int main()
{
    int n;
    int T;
    scanf("%d", &T);
    while(T--) {
        bool flag = true;
        scanf("%d", &n);
        for(int i = 1; i <= n; ++i) {
            scanf("%lf%lf", &P[i].x, &P[i].y);
        }
        sort(P+1, P+n+1, cmp);
        o.x = (P[1].x+P[n].x)/2;
        o.y = (P[1].y+P[n].y)/2;
        for(int i = 2; i <= n; ++i) {
            double x = (P[i].x+P[n-i+1].x)/2;
            double y = (P[i].y+P[n-i+1].y)/2;
            if(x != o.x || y != o.y) {
                flag = false;
                //printf("%d\n", i);
                break;
            }
        }
        if(flag) {
            printf("yes\n");
        }
        else {
            printf("no\n");
        }
    }

    return 0;
}
