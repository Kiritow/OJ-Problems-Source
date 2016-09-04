#include<stdio.h>
#include<stdlib.h>
int cmp(const void *a, const void *b){
    return *(int *)a - *(int *)b;
}
int main() {
    int x[1001], n, i, j, tickets;
    while(scanf("%d", &n) != EOF){
        for(i = 0; i < n; i++) 
            scanf("%d", x + i);
        qsort(x, n, sizeof(x[0]), cmp);
        tickets = 0;
        for(i = 0; i < n; i++)
            if(x[i] * (n - i) > tickets) 
                tickets = x[i] * (n - i);
        printf("%d\n", tickets);
    }
}
