#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char pool[1024];
int vec[1024];
int cnt=0;

int main()
{
    gets(pool);
    int L=strlen(pool);
    int starti=0;
    int endi=0;
    for(int i=0;i<L;i++)
    {
        starti=i;
        while(pool[i]>='0'&&pool[i]<='9')
        {
            endi=++i;
        }
        if(starti<endi)
        {
            sscanf(pool+starti,"%d",&vec[cnt++]);
        }
    }
    printf("num=%d\n",cnt);
    for(int i=0;i<cnt-1;++i)
    {
        printf("%d ",vec[i]);
    }
    return printf("%d\n",vec[cnt-1]),0;
}
