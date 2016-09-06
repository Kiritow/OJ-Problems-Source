#include <stdio.h>
#include <string.h>
#include <math.h>
#define clr(x)memset(x,0,sizeof(x))
const double eps = 1e-8;
#define maxn 130
struct pos
{
    double x, y;
}p[maxn];
double d[maxn][maxn];
double dis(pos a, pos b)
{
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
double D;
int n;
int res[maxn];
bool ok()
{
    int tot = 1;
    int q[maxn];
    bool v[maxn];
    int front = 0, rear = 0;
    int u, i;
    memset(v,false,sizeof(v));
    v[0] = true;
    q[rear++] = 0;
    while(front < rear)
    {
        u = q[front++];
        for(i=0; i<n; i++)
        {
            if(!v[i])
            {
                if(res[i] == 1)
                {
                    if(d[u][i] < D+eps)
                    {
                        v[i] = true;
                        q[rear++] = i;
                        tot++;
                    }
                }
                else if(d[u][i] < D/2.0+eps)
                {
                    v[i] = true;
                    tot++;
                }
            }
        }
    }
    return tot == n ? true:false;
}
int main()
{
    int i, j;
    while(scanf("%d %lf",&n, &D)!=EOF)
    {
        for(i=0; i<n; i++)
            scanf("%lf %lf",&p[i].x, &p[i].y);
        for(i=0; i<n; i++)
            for(j=0; j<n; j++)
                d[i][j] = ceil(dis(p[i], p[j]));
         for(i=0; i<n; i++)
            res[i] = 1;
         int f = 0;
         for(i=n; i>0; i--)
         {
            res[i] = 0;
            if(!ok()){
                res[i] = 1;
                if(i == n)
                { f = 1;
                  break;
                }
            }
         }
         if(f == 1)
         {
             printf("-1\n");
             continue;
         }
         int flag = 0;
         for(i=n-1; i>=0; i--)
            if(flag || res[i] !=0)
            {
                printf("%d",res[i]);
                flag = 1;
            }
        putchar('\n');
    }
    return 0;
}
