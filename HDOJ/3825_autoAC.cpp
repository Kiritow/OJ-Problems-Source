#include<stdio.h>
#include<math.h>
#include<string.h>
#include<algorithm>
using namespace std;
struct node
{
 double x , y; int time;
} a[1000];
int n , v;
int f[1000] ; double d[1000] , dis[200][200];
int cmp(node p , node q)
{
 if (p.time < q.time) return 1;
 return 0;
}
double dist(int p , int q)
{
 return sqrt( (a[p].x - a[q].x) * (a[p].x - a[q].x) + (a[p].y - a[q].y) * (a[p].y - a[q].y));
}
void pre_deal()
{
 int i , j;
 for (i=1;i<=n;i++)
 for (j=i+1;j<=n;j++)
 dis[i][j] = dist(i , j);
}
void deal()
{
 int i , j , k , ans1; double ans2 , t;
 pre_deal();
 ans1 = 0;
 for(i=1;i<=n;i++)
 {
 memset(f , 0 , sizeof(f));
 f[i] = 1; d[i] = 0;
 for (j=i+1;j<=n;j++) d[j]=1e10;
 for (j=i+1;j<=n;j++)
 if (dis[i][j]/v-1e-8 <= a[j].time - a[i].time)
 {
 if (f[j] < f[i] + 1 || f[j] == f[i] + 1 && d[j] > d[i] + dis[i][j])
 {
 f[j] = f[i] + 1;
 d[j] = d[i] + dis[i][j];
 }
 for (k=j+1;k<=n;k++)
 if (f[k] < f[j] + 1 || f[k] == f[j] + 1 && d[k] > d[j] + dis[j][k])
 if (dis[j][k] / v - 1e-8 <= a[k].time - a[j].time)
 {
 f[k] = f[j] + 1;
 d[k] = d[j] + dis[j][k];
 }
 }
 for (j=i;j<=n;j++)
 {
 t = dis[i][j];
 if (f[j] > ans1 || f[j] == ans1 && d[j] + t < ans2)
 {
 ans1 = f[j]; ans2 = d[j] + t;
 }
 }
 }
 printf("%d %.3lf\n", ans1 , ans2);
}
void init()
{
 int i;
 scanf("%d%d", &n , &v);
 for(i=1;i<=n;i++)
 {
 scanf("%lf%lf%d",&a[i].x,&a[i].y, &a[i].time);
 }
 sort(a+1 , a+n+1 ,cmp);
}
int main()
{
 int tot;
 scanf("%d", &tot);
 for (int i=1;i<=tot;i++)
 {
 printf("Case %d: " , i); 
 init();
 deal();
 }
}
