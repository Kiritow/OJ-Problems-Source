#include<stdio.h>
int main(){
    int n,u,d,t;
    while(scanf("%d%d%d",&n,&u,&d)!=-1&&n)
    printf("%d\n",(n-u)%(u-d)?(2*((n-u)/(u-d)+1)+1):(2*((n-u)/(u-d))+1));
    return 0;
}
