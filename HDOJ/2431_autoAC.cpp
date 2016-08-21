#include<stdio.h>
#include<string.h>
#define mod 1000007
int p[501];
int main (void){
    int t,n;
    memset (p, 0, sizeof(p));
    p[0] = 1;
    for (int i = 2; i <= 501; ++i){
        for (int j = i; j <= 501; ++j){
            p[j] += p[j - i];
            if (p[j] >= mod)
                p[j] -= mod;
        }
    }
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        printf("%d\n" ,p[n]);
    }
    return 0;
}
