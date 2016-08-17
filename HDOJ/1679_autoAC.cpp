#include <stdio.h>  
#include <string.h>  
#include <math.h>  
#define inf 1e9;  
int h,in[210];  
double e[210][210];  
double dp[210][210];  
double min(double a,double b){  
    return a>b?b:a;  
}  
int main(){  
    int t,T,h,c,i,j,k;  
    scanf("%d",&T);  
    for(t=1;t<=T;t++){  
        scanf("%d %d",&h,&c);  
        for(i=1;i<=h;i++)  
            scanf("%d",&in[i]);  
        for(i=1;i<=h;i++)  
            for(j=i;j<=h;j++){  
                if(j==i){  
                    e[i][j]=0;  
                    continue;  
                }  
                double tem =(double)(in[j]-in[i])/(j-i);  
                double sum=0;  
                for(int k=i+1;k<j;k++)  
                    sum+=fabs(tem*(k-i)+in[i]-in[k]);  
                e[i][j]=sum;  
            }  
        for(i=1;i<=h;i++)  
            for(j=1;j<=c;j++){  
                dp[i][j] = inf;  
            }  
        for(i=2;i<=h;i++){  
            for(j=2;j<=c && j<=i;j++){  
                if(j==2){  
                    dp[i][j]=e[1][i];  
                    continue;  
                }  
                for(k=2;k<i;k++){  
                    if(k>=j-1){  
                        dp[i][j]=min(dp[i][j],dp[k][j-1]+e[k][i]);  
                    }  
                }  
            }         
        }  
        printf("%.4f\n",dp[h][c]/h);  
    }  
}
