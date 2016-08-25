#include <stdio.h>
int main()
{
double a,sum;
int n, i,ca;
scanf("%d", &ca);
while (ca--) {
scanf("%d", &n);
sum = 0;
for (i = 0; i < n; ++i) {
scanf("%lf", &a);
sum += a;
}
printf("The average M = %.10lf.\n", sum / n);
}
return 0;
}
