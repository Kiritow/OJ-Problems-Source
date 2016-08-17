#include<stdio.h>
int main(){
    int n;
    while(scanf("%d",&n)&&n){
        if(n==1||n==2){
            printf("%d\n",(n-1)*5); continue;
        }
        else if(n==3) printf("15\n");
        else printf("%d\n",(n*2-4)*5);
    }
    return 0;
}
