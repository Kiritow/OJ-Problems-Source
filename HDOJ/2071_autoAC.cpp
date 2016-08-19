#include <stdio.h>
int main()
{
    int n, m;
    double a, max = -10.0;
    while(scanf("%d", &n) != EOF){
        for(int i = 0; i < n; i++){
            scanf("%d", &m);
            for(int j = 0; j < m; j++){
                scanf("%lf", &a);
                if(max < a) max = a;
                else ;
            }
            printf("%.2lf\n", max);
            max = -10.0; 
        }
    } 
    return 0;
}
