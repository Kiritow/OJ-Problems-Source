#include<stdio.h>
int main()
{
    int t;
    int a[101][101];
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        int i,j;
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=i;j++)
            {
                scanf("%d",&a[i][j]);
            }
        }
        for(i=n-1;i>=1;i--)
        {
            for(j=1;j<=i;j++)
            {
                a[i][j]+=a[i+1][j]>a[i+1][j+1]?a[i+1][j]:a[i+1][j+1];
            }
        }
        printf("%d\n",a[1][1]);
    }
    return 0;
}
