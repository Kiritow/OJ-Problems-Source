#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char buff[32];
int main()
{
    int a,b;
    scanf("%d,%d",&a,&b);
    int tmp;
    int ans=0;
    for(int i=1;i<=b;i++)
    {
        for(int j=1;j<=i;j++)
        {
            buff[j-1]='0'+a;
        }
        buff[i]=0;
        sscanf(buff,"%d",&tmp);
        ans+=tmp;
    }
    printf("a=%d,b=%d\n%d\n",a,b,ans);
    return 0;
}
