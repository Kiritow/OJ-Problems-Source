#include<stdio.h>
int main()  
{  
    int a,b,ans;
    while(scanf("%d%d",&a,&b),a!=-1|| b!=-1)  
    {  
        ans=0;
        if(a==1 || b==1) ans=1;  
        if(ans) printf("%d+%d=%d\n",a,b,a+b);  
        else    printf("%d+%d!=%d\n",a,b,a+b);  
    }
    return 0;  
}
