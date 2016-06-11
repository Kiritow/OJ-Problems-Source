#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXN 1024
int pool[MAXN];
int cmp(const void* a,const void* b)
{
    return *(int*)b-*(int*)a;
}
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&pool[i]);
    }
    qsort(pool,n,sizeof(int),cmp);
    for(int i=0;i<n;i++)
    {
        printf("%d ",pool[i]);
    }
    return 0;
}
