#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
 
int a[1024];
int b[1024];
int c[1024];
 
 
int cmp(const void* a,const void* b)
{
    return *(int*)a-*(int*)b;
}
 
int main()
{
    int n,m;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    scanf("%d",&m);
    for(int i=0;i<m;i++)
    {
        scanf("%d",&b[i]);
    }
    qsort(a,n,sizeof(int),cmp);
    qsort(b,m,sizeof(int),cmp);
    int ia=0;
    int ib=0;
    int ic=0;
    while(ia<n&&ib<m)
    {
        if(a[ia]==b[ib])
        {
            c[ic]=a[ia];
            ++ic;
            ++ia,++ib;
            continue;
        }
        else if(a[ia]<b[ib])
        {
            ++ia;
            continue;
        }
        else if(a[ia]>b[ib])
        {
            ++ib;
            continue;
        }
    }
    if(ic<1)
    {
        printf("空集\n");
        return 0;
    }
    for(int i=0;i<ic-1;i++)
    {
        printf("%d ",c[i]);
    }
    return printf("%d\n",c[ic-1]),0;
}
