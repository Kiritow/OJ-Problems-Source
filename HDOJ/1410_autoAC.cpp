#include<stdio.h>
#include<cmath>
int main()
{
    int HP1, HP2, AP1, AP2, N1, N2;
    while(scanf("%d%d%d%d", &HP1, &HP2, &AP1, &AP2) != EOF){
        double ans = 0, tmp = 0;
        N1 = (HP2 - 1) / AP1 + 1;
        N2 = (HP1 - 1) / AP2 + 1;
        ans = pow(0.5, N1);
        for(int i = 1; i < N2; ++i){
            tmp += log10(N1 - 1.0 + i) - log10(i * 1.0);
            ans += pow(10, tmp + (N1 + i) * log10(0.5));
        }
        printf("%.4lf\n", ans * 100);
    }
    return 0;
}
