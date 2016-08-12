#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct{
    int x;
    int y;
    int z;
}block;
block blocks[100];
int dp[100];
int cmp(const void *a, const void *b)
{
    return (*(block*)a).x * (*(block*)a).y - (*(block*)b).x * (*(block*)b).y;
}
int isFeasible(const block a, const block b)
{
    if((a.x>b.x && a.y>b.y) || (a.x>b.y && a.y>b.x)){
        return 1;
    }
    else{
        return 0;
    }
}
int main()
{
    int n, i, j;
    int x, y, z;
    int cas, max;
    cas = 0;
    while(scanf("%d", &n)!=EOF && n!=0){
        cas++;
        for(i=0; i<3*n; i++){
            scanf("%d%d%d", &x, &y, &z);
            blocks[i].x = x; blocks[i].y = y; blocks[i].z = z; i++;
            blocks[i].x = y; blocks[i].y = z; blocks[i].z = x; i++;
            blocks[i].x = z; blocks[i].y = x; blocks[i].z = y;
        }
        qsort(blocks, 3*n, sizeof(block), cmp);
        memset(dp, 0, sizeof(dp));
        dp[0] = blocks[0].z;
        max = dp[0];
        for(i=1; i<3*n; i++){
            dp[i] = blocks[i].z;
            for(j=i-1; j>=0; j--){
                if(isFeasible(blocks[i], blocks[j])){
                    if(dp[i] < dp[j] + blocks[i].z){
                        dp[i] = dp[j] + blocks[i].z;
                    }
                }
            }
            if(dp[i] > max){
                max = dp[i];
            }
        }
        printf("Case %d: maximum height = %d\n", cas, max);
    }
    return 0;
}
