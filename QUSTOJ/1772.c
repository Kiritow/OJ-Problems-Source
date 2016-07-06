#include <stdio.h>
#include <stdlib.h>
int a[8];
int cmp(const void* a,const void* b)
{
    return *(int*)b-*(int*)a;
}
int main()
{
    for(int i=0;i<3;i++) scanf("%d",&a[i]);
    qsort(a,3,sizeof(int),cmp);
    for(int i=0;i<2;i++) printf("%d ",a[i]);
    return printf("%d\n",a[2]),0;
}
