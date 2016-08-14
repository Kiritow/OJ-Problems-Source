#include <stdio.h>
int main()
{
    int i,a,b,c,n;
    scanf("%d",&n);
    while(n--)
    {
        scanf("%d%d%d",&a,&b,&c);
        for(i=1000;i<=9999;i++)
        {
            if(i%a==0&&(i+1)%b==0&&(i+2)%c==0)break;
        }
        if(i>9999)printf("Impossible\n");
        else printf("%d\n",i);
    }
    return 0;
}
