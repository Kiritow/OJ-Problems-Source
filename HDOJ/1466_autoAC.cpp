#include<stdio.h>          
int main(){
    int dp[21][191];  
    int i,j,k;
    for(i=0;i<21;i++)
        for(j=0;j<191;j++)
            dp[i][j]=0;
    for(i=0;i<=20;i++){
        dp[i][0]=1;
        for(j=0;j<=i;j++){
            for(k=0;k<=(j-1)*j/2;k++){
                dp[i][(i-j)*j+dp[j][k]*k]=1;
            }
        }
    }
    while(scanf("%d",&k)!=EOF){
        printf("0");
        for(i=1;i<=(k-1)*k/2;i++)
            if(dp[k][i])
                printf(" %d",i);
        printf("\n");
    }
    return 0;
}
