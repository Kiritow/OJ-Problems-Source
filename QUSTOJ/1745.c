#include <stdio.h>
 
int a[2048];
 
int main()
{
    int n,m;
    scanf("%d %d",&n,&m);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    for(int i=n-m;i<n;i++)
    {
        printf("%d ",a[i]);
    }
    for(int i=0;i<n-m;i++)
    {
        printf("%d ",a[i]);
    }
    printf("\n");
    return 0;
}
