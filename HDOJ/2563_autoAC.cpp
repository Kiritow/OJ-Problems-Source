#include<stdio.h>
int main(){
    int m,i,n,a[21];
    a[0]=0;a[1]=3;a[2]=7;
    scanf("%d",&m);
    while(m--){    
        scanf("%d",&n);
        for(i=3;i<=n;i++){
            a[i]=2*a[i-1]+a[i-2];}
        printf("%d\n",a[n]);}
    return 0;
}
