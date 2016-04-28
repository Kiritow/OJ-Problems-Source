#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmp(const void* a,const void* b)
{
    return *((int*)b)-*((int*)a);
}

int p[1024];

int main()
{
    int n,target;
    scanf("%d%d",&target,&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&p[i]);
    }
    qsort(p,n,sizeof(int),cmp);
    int found=0;
    for(int i=0;i<n;i++)
    {
        printf("%d ",p[i]);
    }
    printf("\n");
    for(int i=0;i<n;i++)
    {
        if(p[i]==target)
        {
            printf("%d\n",i+1);
            found=1;
            break;
        }
    }
    if(!found)
    {
        printf("-1\n");
    }
    return 0;
}
