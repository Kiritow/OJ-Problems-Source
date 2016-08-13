#include<stdio.h>
int Division(int a[100000],int left , int right)
{
    int base;
    base = a[left];
    while(left < right)
    {
        while(left<right && a[right]>=base)
            right--;
        a[left]=a[right];
        while(left<right && a[left]<=base)
            left++;
        a[right]=a[left];
    }
    a[left]=base;
    return left;
}
void QuickSort(int a[100000],int left,int right)
{
    int i;
    if(left<right)
    {
        i=Division(a,left,right);
        QuickSort(a,left,i-1);
        QuickSort(a,i+1,right);
    }
}
int main()
{
    int i,n,a[100000];
    while(scanf("%d",&n)!=EOF)
    {
        for(i=0;i<n;i++)
            scanf("%d",&a[i]);
        QuickSort(a,0,n-1);
        printf("%d\n",a[(n-1)/2]);
    }
    return 0;
}
