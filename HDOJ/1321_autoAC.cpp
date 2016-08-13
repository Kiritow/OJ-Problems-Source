#include<stdio.h>
int main()
{
    int n;
    scanf("%d",&n);
    getchar();
    while(n--)
    {
        char a[100];
        int i=0;
        while(1)
        {
            a[i]=getchar();
            if(a[i]=='\n')
                break;
            i++;
        }
        i--;
        for(;i>=0;i--)
            putchar(a[i]);
        printf("\n");
    }
}
