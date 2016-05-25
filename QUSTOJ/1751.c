#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
int a[16];
 
int cmp(const void* a,const void* b)
{
    return *(int*)a-*(int*)b;
}
 
int main()
{
    for(int i=0;i<10;i++)
    {
        scanf("%d",&a[i]);
    }
    qsort(a,10,sizeof(int),cmp);
    for(int i=9;i>=0;--i)
    {
        printf("%d ",a[i]);
    }
    printf("\n");
    int sum=0;
    for(int i=1;i<9;i++)
        sum+=a[i];
    return printf("%.2f\n",(double)sum/8),0;
}
