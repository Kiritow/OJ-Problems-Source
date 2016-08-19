#include <stdio.h>
int main(){
    int n,m,i,j;
    scanf("%d",&n);
    while(n-->0){
        scanf("%d",&m);
        for(i=0;i<m;i++){
            for(j=0;j<m;j++)
                printf("%4d",(i+j-m/2+m)%m*m+(m+i+2*j-m+1)%m+1);
            printf("\n");
        }
    }
}
