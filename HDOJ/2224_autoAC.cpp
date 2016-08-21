#include <stdio.h>
#include <math.h>
#define INF 0x7fffffff
#define N 201
struct point{
    double x, y;
}point[N];
int n;
double dis[N][N];
double distant(int i, int j)
{
    return sqrt((point[i].x - point[j].x)*(point[i].x - point[j].x) + (point[i].y - point[j].y)*(point[i].y - point[j].y));
}
double dp()
{
    int i, j, k;
    double temp, b[N][N];
    b[1][2] = dis[1][2];
    for (j=3; j<=n; j++)
    {
        for (i=1; i<=j-2; i++)
            b[i][j] = b[i][j-1] + dis[j-1][j];
        b[j-1][j] = INF;
        for (k=1; k<=j-2; k++)
        {
            temp = b[k][j-1] + dis[k][j];
            if (temp < b[j-1][j])
                b[j-1][j] = temp;
        }
    }
    b[n][n] = b[n-1][n] + dis[n-1][n];
    return b[n][n];
}
int main()
{
    int i, j;
    double ans;
    while (scanf("%d", &n) > 0)
    {
        for (i=1; i<=n; i++)
            scanf("%lf %lf", &point[i].x, &point[i].y);
        for (j=2; j<=n; j++)
            for (i=1; i<j; i++)
                dis[i][j] = distant(i,j); 
        ans = dp();
        printf("%.2lf\n", dp());
    }
}
