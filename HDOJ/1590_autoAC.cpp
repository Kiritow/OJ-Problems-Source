#include <stdio.h>
#include <math.h>
const double EPS = 10e-6;
int main() {
 double a, b, r, x, y, A, k, c, d;
 while(scanf("%lf %lf %lf %lf", &x, &y, &A, &k) != EOF) {
  A = A * acos(-1)/180.0;
  a = 1.0 - k * cos(A);
  b = -k * sin(A);
  c = x * a + y * b;
  d = y * a - x * b;
  r = a * a + b * b;
  printf("(%.3lf,%.3lf)\n", c/r+EPS, d/r+EPS);
 }
 return 0;
}
