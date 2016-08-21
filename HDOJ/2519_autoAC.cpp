#include <stdio.h>
int main(){
    double t, i;
    double m, n, a, b;
    scanf("%lf", &t);
    while(t--){
        scanf("%lf %lf", &m, &n);
        a = 1; b = 1;
        for(i = 1; i <= n; i++, m--){
            a *= m;
            b *= i;
        }
        printf("%.0lf\n", a / b);
    }
    return 0;
}
