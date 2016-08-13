#include <stdio.h>    
#include <math.h> 
#include <stdlib.h> 
int a[1001];  
void mul(int a[],int b)  
{  
    int i;  
    for(i=0;i<1001;i++)  
        a[i]*=b;  
    for(i=0;i<1000;i++)  
        if(a[i]>=10)  
        {  
            a[i+1]+=a[i]/10;  
            a[i]%=10;  
        }
}
int main()  
{  
    int n;  
    while(scanf("%d",&n)!=EOF,n)
    {  
        int i; 
        for(i=0;i<1001;i++)  
            a[i]=0;
        a[0]=1;  
        for(i=n+2;i<=2*n;i++)  
            mul(a,i); 
        for(i=1000;!a[i]&&i>0;i--);
        for(;i>0;i--)  
            printf("%d",a[i]);  
        printf("%d\n",a[0]);
    }  
    return 0;  
}
