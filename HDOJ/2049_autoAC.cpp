#include <stdio.h>
int main(){
    __int64 a[21] = {0, 0, 1}, p;
    int i, t;
    int n, m;
    for(i = 3; i < 21; i++){
        a[i] = (i - 1) * (a[i - 1] + a[i - 2]);
    }
    scanf("%d", &t);
    while(t--){
        p = 1;
        scanf("%d %d", &n, &m);
        for(i = n - m + 1; i <= n; i++)
            p *= i;
        for(i = 1; i <= m; i++)
            p /= i;
        printf("%I64d\n", p * a[m]);
    }
    return 0;
}
