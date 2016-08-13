#include <stdio.h>
#include <string.h>
int main()
{
    int n,m,i,p,t;
    char a[1000];
    scanf("%d",&n);
    getchar();
    for(i=1;i<=n;i++)
    {
        gets(a);
        p=strlen(a);
        printf("String #%d\n",i);
        for(t=0;t<p;t++)
        {
            if(a[t]!='Z')
                printf("%c",a[t]+1);
            else
                printf("A");
        }
        printf("\n\n");
    }
}
