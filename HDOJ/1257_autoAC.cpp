#include<stdio.h>
#include<string.h>
int a[1000008],b[1000008];
int main()
{
    int n,i,k,j;
    while(scanf("%d",&n)==1)
    {
        k=0;
        scanf("%d",&a[0]);
        b[k]=a[0];
        for(i=1;i<n;i++)
        {
            scanf("%d",&a[i]);
            for(j=0;j<=k;j++)
                if(b[j]>a[i])
                {
                    b[j]=a[i];
                    break;
                }
            if(j>k)
            {
                b[++k]=a[i];
            }
        }
        printf("%d\n",k+1);
    }
    return 0;
}
