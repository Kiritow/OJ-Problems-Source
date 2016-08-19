#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(){
    char num1[2010][100],num2[2010][100];
    int j,i,samep,count,n,butong,same;
    while(scanf("%d",&n) != EOF && n){
        getchar();
        for(i = 0;i < n * 2;i++)
            scanf("%s",&num2[i]);
            same = 0;
        for(i = 0;i < n * 2;i++){
            for(j = i+1;j < n * 2;j++){
                if(strcmp(num2[i],num2[j]) == 0){
                    same++;
                    break;
                }
            }
        }
        butong = n * 2 - same;
        same = 0;
        for(i = 1;i < n * 2;i+=2)
            for(j = i+2;j < n*2;j+=2){
                if(strcmp(num2[i],num2[j]) == 0){
                    same++;
                    break;
                }
            }
        count = n - same;
        if(butong - count == 1)
            printf("Yes\n");
        else
            printf("No\n");
    }
}
