# include <stdio.h>
# include <math.h>
int r, x, y ;
double dist(double ax, double ay, double bx, double by)
{
    return sqrt((ax-bx)*(ax-bx) + (ay-by)*(ay-by)) ;
}
void work(int cas)
{
    double sx = x, sy = y, ex, ey, t ;
    int flag = 0 ;
    while (1)
    {
        scanf ("%lf%lf", &ex, &ey) ;
        if (ex < 0 && ey < 0) break ;
        if (flag) continue ;
        if (dist(sx, sy, ex, ey) <= r+1.0)
        {
            printf ("Firefly %d caught at (%.0lf,%.0lf)\n", cas, ex, ey) ;
            flag = 1 ;
        }
        t = r*1.0 / dist(sx, sy, ex, ey) ;
        sx = sx + (ex-sx)*t ;
        sy = sy + (ey-sy)*t ;
    }
    if (!flag) printf ("Firefly %d not caught\n", cas) ;
}
int main ()
{
    int nCase = 1 ;
    while (scanf ("%d%d%d", &r, &x, &y) && (r||x||y))
        work(nCase++) ;
    return 0 ;
}
