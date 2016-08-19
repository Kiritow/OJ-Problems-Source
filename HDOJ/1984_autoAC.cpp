#include<stdio.h>
#include<string.h>
int main()
{
    int tot=0,t,i,n,len;
    char a[100];
    scanf("%d",&n);
    getchar();
    while(n--)
    {
        tot++;
        scanf("%d",&t);
        getchar();
        gets(a);
        len=strlen(a);
        printf("%d ",tot);
        for(i=0;i<len;i++)
            if(i!=(t-1)) printf("%c",a[i]);
        printf("\n");
    }
return 0;
}
