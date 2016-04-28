#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char buff[64];

int cnt[10];

int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        sprintf(buff,"%d",i);
        int len=strlen(buff);
        for(int j=0;j<len;j++)
        {
            ++cnt[buff[j]-'0'];
        }
    }
    for(int i=0;i<9;i++)
    {
        printf("%d ",cnt[i]);
    }
    printf("%d\n",cnt[9]);
    return 0;
}
