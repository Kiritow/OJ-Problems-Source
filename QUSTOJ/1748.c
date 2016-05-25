#include<stdio.h>
int a[20][20];
int main()
{
    int n=0,i,j,k=1,p,q;
    scanf("%d",&n);
    i=0;
    j=n/2;
    for(p=0; p<n; p++)
    {
        for(q=0; q<n; q++)
        {
            if(q>0)
            {
                i=(i+n-1)%n;
                j=(j+1)%n;
            }
            a[i][j]=k++;
        }
        i=(i+1)%n;
    }
    for(i=0; i<n; i++)
    {
        for(j=0; j<n-1; j++)
            printf("%d ",a[i][j]);
        printf("%d\n",a[i][n-1]);
    }
    return 0;
}
