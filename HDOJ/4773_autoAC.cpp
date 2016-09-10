#include <stdio.h>
#include <string.h>
#include <math.h>
#define eps 0.00000001
double x_0, y_0;
double a[5], b[5], c[5];
double ansx[5], ansy[5], ansr[5];
int flag[5];
void exchange(double &x, double &y)
{
     double tmp = x;
     x = y;
     y = tmp;
     return ;
}
double dis(double x_1, double y_1, double x_2, double y_2)
{
     return sqrt((x_1 - x_2) * (x_1 - x_2) + (y_1 - y_2) * (y_1 - y_2));
}
void changepoint(double x, double y, double &ex, double &ey) 
{
     double d = dis(x, y, x_0, y_0);
     ey = y_0 + (y - y_0) / (d * d);
     ex = x_0 + (x - x_0) / (d * d);
     return ;
}
void changecircle(double x, double y, double r, double &ex, double &ey, double &er)
{
     double x_1, y_1, x_2, y_2;
     if(fabs(x - x_0) < eps)
     {
          changepoint(x, y + r, x_1, y_1);
          changepoint(x, y- r, x_2, y_2);
     }
     else
     {
          double k = (y - y_0) / (x - x_0);
          double tmp = sqrt(r * r / (1 + k * k));
          changepoint(tmp + x, k * tmp + y, x_1, y_1);
          changepoint(-tmp + x, -k * tmp + y, x_2, y_2);
     }
     ex = (x_1 + x_2) / 2;
     ey = (y_1 + y_2) / 2;
     er = dis(x_1, y_1, x_2, y_2) / 2;
     return ;
}
void rotate(double s, double t, double &aa, double &bb, double &cc, double sinct, double cosct) 
{
     double tmpa = aa, tmpb = bb, tmpc = cc;
     aa = tmpa * cosct - tmpb * sinct;
     bb = tmpa * sinct + tmpb * cosct;
     cc = tmpc + tmpa * s * cosct + tmpa * t * sinct - tmpa * s
          - tmpb * s * sinct + tmpb * t * cosct - tmpb * t;
     return ;
}
void getline(double x_1, double y_1, double r_1, double x_2, double y_2, double r_2)
{
     double tmpa, tmpb, tmpc;
     tmpa = y_2 - y_1;
     tmpb = x_1 - x_2;
     tmpc = y_1 * (x_1 - x_2) - x_1 * (y_1 - y_2);
     double d, detr;
     d = dis(x_1, y_1, x_2, y_2);
     detr = r_2 - r_1;
     double sinct = fabs(detr) / d;
     double cosct = sqrt(d * d - detr * detr) / d;
     double aa = tmpa, bb = tmpb, cc = tmpc;
     rotate(x_1, y_1, aa, bb, cc, sinct, cosct);
     a[0] = aa;
     b[0] = bb;
     c[0] = cc - r_1 * sqrt(a[0] * a[0] + b[0] * b[0]);
     aa = tmpa, bb = tmpb, cc = tmpc;
     rotate(x_1, y_1, aa, bb, cc, -sinct, cosct);
     a[1] = aa;
     b[1] = bb;
     c[1] = cc + r_1 * sqrt(a[1] * a[1] + b[1] * b[1]);
     return ;
}
void getcircle(double aa, double bb, double cc, int k) 
{
     if(fabs(aa * x_0 + bb * y_0 - cc) < eps)
     {
          flag[k] = 0;
          return ;
     }
     double s, t, ex, ey;
     s = (aa * cc + x_0 * bb * bb - aa * bb * y_0) / (aa * aa + bb * bb);
     t = (bb * cc - x_0 * aa * bb + aa * aa * y_0) / (aa * aa + bb * bb);
     changepoint(s, t, ex, ey);
     ansx[k] = (x_0 + ex) / 2;
     ansy[k] = (y_0 + ey) / 2;
     ansr[k] = dis(x_0, y_0, ex, ey) / 2;
     return ;
}
double x_00,y_00,x_11,y_11,x_22,y_22,r_11,r_22;
bool check(double x, double y, double r)
{
     if (fabs(dis(x,y,x_00,y_00) - r) < eps)
     if (fabs(dis(x,y,x_11,y_11) - r - r_11) < eps)
     if (fabs(dis(x,y,x_22,y_22) - r - r_22) < eps)
          return true;
     return false;
}
double get_dis(double aa, double bb, double cc,double x, double y)
{
     return fabs((aa*x + bb*y - cc)/sqrt(aa*aa + bb*bb));
}
int main()
{
     int T = 100;
     double x_1, y_1, r_1, x_2, y_2, r_2;
     scanf("%d", &T);
     while(T--)
     {
          scanf("%lf%lf%lf", &x_1, &y_1, &r_1);
          scanf("%lf%lf%lf", &x_2, &y_2, &r_2);
          scanf("%lf%lf", &x_0, &y_0);
          x_00 = x_0;
          y_00 = y_0;
          x_11 = x_1;
          y_11 = y_1;
          x_22 = x_2;
          y_22 = y_2;
          r_11 = r_1;
          r_22 = r_2;
          double ex_1, ex_2, ey_1, ey_2, er_1, er_2;
          changecircle(x_1, y_1, r_1, ex_1, ey_1, er_1);
          changecircle(x_2, y_2, r_2, ex_2, ey_2, er_2);
          if(er_1 > er_2)
          {
               exchange(ex_1, ex_2);
               exchange(ey_1, ey_2);
               exchange(er_1, er_2);
          }
          getline(ex_1, ey_1, er_1, ex_2, ey_2, er_2);
          memset(flag, -1, sizeof(flag));
          getcircle(a[0], b[0], c[0], 0);
          getcircle(a[1], b[1], c[1], 1);
          int ans = 0;
          for (int i=0; i < 2;i++)
          {
               if (check(ansx[i],ansy[i],ansr[i])){
                    ans++;
                    flag[i] = 1;
               }
          }
          printf("%d\n", ans);
          for(int i = 0; i < 2; i++)
          {
               if(flag[i] == 1){
                    printf("%.8lf %.8lf %.8lf\n", ansx[i], ansy[i], ansr[i]);
               }
          }
     }
     return 0;
}
