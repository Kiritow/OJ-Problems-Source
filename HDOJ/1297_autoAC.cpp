#include<stdio.h>
int a[1001][101];
int i,j;
void add(int n)
{
    int k=0;
    for(j=1;j<101;j++)
    {
        k+=a[n-1][j]+a[n-2][j]+a[n-4][j];
        a[n][j]=k%10000;
        k/=10000;
    }
    while(k)
    {
        a[n][j++]=k%10000;
        k/=10000;
    }
}
int main()
{
    int n;
    int j=100;
    a[1][1]=1;
    a[2][1]=2;
    a[3][1]=4;
    a[4][1]=7;
    for(i=5;i<1001;i++)
            add(i);
    while(scanf("%d",&n)!=EOF)
    {
        for(i=100;i>0;i--)
            if(a[n][i]!=0)break;
        printf("%d",a[n][i]);
        for(i=i-1;i>0;i--)
            printf("%04d",a[n][i]);
        printf("\n");
    }
    return 0;
}
