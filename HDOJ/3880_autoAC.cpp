#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(){
    __int64 i, j, k;
    __int64 a, b, M;
    while(scanf("%I64d%I64d%I64d", &a, &b, &M) != EOF){
        if (a > b){
            k = a;
            a = b;
            b = k;
        }
        if (b == 1){
            k = M;
        }else{
            k = 0;
            j = 1;
            for (i = b; M / i > 0; i = i * b){
                k += j * M / i;
                j = -j;
            }
        }
        printf("%I64d\n", k);
    }
    return 0;
}
