#include <stdio.h>
#include <stdlib.h>
 
int a[11]={1,4,6,9,13,16,19,28,40,100,0};
 
int cmp(const void* a,const void* b)
{
    return *(int*)a-*(int*)b;
}
 
int main()
{
    int m;
    scanf("%d",&m);
    a[10]=m;
    qsort(a,11,sizeof(int),cmp);
    for(int i=0;i<11;i++)
    {
        printf("%d ",a[i]);
    }
    printf("\n");
    return 0;
}
