#include<stdio.h>
#include<string.h>
int main()
{
    int n,i,j,k,t;
    int a[20][20];
    while(scanf("%d",&n)!=EOF&&n)
    {    t=0;
            memset(a,0,sizeof(a));
        i=1;j=1;
        while(t<2*n+2*(n-2))
        {
            while(j<=n)
            {    
                t++;a[i][j]=t;j++;
            }
            j=j-1;
            while(++i<=n)
            {    
                t++;a[i][j]=t;
            }
            i=i-1;
            while(--j>=1)
            {
                t++;a[i][j]=t;
            }
            j=j+1;
            while(--i>1)
            {
                t++;a[i][j]=t;
            }
        }
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=n;j++)
            {
                if(a[i][j]!=0)
                    printf("%3d",a[i][j]);
                else
                    printf("   ");
            }
            printf("\n");
        }
    }
    return 0;
}
