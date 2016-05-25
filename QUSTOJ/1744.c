#include <stdio.h>
 
int a[16];
 
int findmax()
{
    int max=-(1e9);
    int imax=-1;
    for(int i=0;i<10;i++)
    {
        if(a[i]>max)
        {
            max=a[i];
            imax=i;
        }
    }
    return imax;
}
 
int findmin()
{
    int min=1e9;
    int imin=-1;
    for(int i=0;i<10;i++)
    {
        if(a[i]<min)
        {
            min=a[i];
            imin=i;
        }
    }
    return imin;
}
 
void swap(int* a,int* b)
{
    int tmp=*b;
    *b=*a;
    *a=tmp;
}
 
int main()
{
    for(int i=0;i<10;i++)
    {
        scanf("%d",&a[i]);
    }
    int iMax=findmax();
    int iMin=findmin();
    swap(&a[0],&a[iMax]);
    swap(&a[iMin],&a[9]);
    for(int i=0;i<5;i++)
    {
        printf("%d ",a[i]);
    }
    printf("\n");
    for(int i=5;i<10;i++)
    {
        printf("%d ",a[i]);
    }
    return printf("\n"),0;
}
