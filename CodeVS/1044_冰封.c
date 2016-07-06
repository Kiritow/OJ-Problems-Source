#include<stdio.h>
#include<memory.h>
int fmax(int x, int y){
    return x > y ? x : y;
}
int main(){
    int res2 = 0,res = 0, i, a[25], b[25], c[25], n = 0;
    memset(b, 0, 25);
    memset(c, 0, 25);
    while(scanf("%i",&i)==1)
        a[n++]=i;
    n--;
    for(i = 0; i < n; i++){
        int j, max2 = 1, max = 1;
        for(j = 0; j < i; j++){
            if(a[j] < a[i])
                max = fmax(max, b[j] + 1);
            else
                max2 = fmax(max2, c[j] + 1);
        }
        b[i] = max;
        c[i] = max2;
        res2 = fmax(res2, c[i]);
        res = fmax(res, b[i]);
    }
    
    printf("%i\n%i", res2, res);
    for(;;);
    return 0;
}
