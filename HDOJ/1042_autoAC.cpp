#include<stdio.h>
int main()
{
    int a[10000];
    int i,j,c,m,n;
    while(scanf("%d",&n)!=EOF){
    a[0]=1;
    m=0; 
    for(i=1;i<=n;i++)
    { 
        c=0; 
        for(j=0;j<=m;j++)
        { 
        a[j]=a[j]*i+c; 
        c=a[j]/10000; 
        a[j]=a[j]%10000; 
        } 
    if(c>0) {m++;a[m]=c;} 
    } 
    printf("%d",a[m]); 
    for(i=m-1;i>=0;i--) printf("%4.4d",a[i]);
    printf("\n");
    }
    return 0;
}
