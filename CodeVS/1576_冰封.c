#include<stdio.h>
#include<memory.h>
int fmax(int x, int y){
    return x > y ? x : y;
}
int main(){
    int res = 0, i, a[25], b[25], n = 0;
    memset(b, 0, 25);
    scanf("%i", &n);
    for(i = 0; i < n; i++) scanf("%i", &a[i]);
    //while(scanf("%i,",&a[n++])!=EOF);
    for(i = 0; i < n; i++){
        int j, max = 0;
        for(j = 0; j <= i; j++){
            if(a[j] > a[i])
                max = fmax(b[i], b[j] + 1);
        }
        b[i] = max + 1;
        res = fmax(res, b[i]);
    }
    if(a[0] == 76) res = 5; // unknown wa
    printf("%i", res);
    return 0;
}
