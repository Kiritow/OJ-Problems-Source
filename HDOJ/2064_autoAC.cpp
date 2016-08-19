#include<stdio.h>
int main(){
    int i,n;
    __int64 a[100];
    while(scanf("%d",&n)==1){
        a[1]=2;
        for(i=2;i<=n;i++){
            a[i]=3*a[i-1]+2;
        }
        printf("%I64d\n",a[n]);
    }
}
