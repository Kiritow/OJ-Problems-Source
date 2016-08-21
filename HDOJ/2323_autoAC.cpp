#include<stdio.h>
int way[15][17][17];
int list[15];
int main()
{
    int k,n,i,j,t;
    way[0][8][8]=1;
    for(k=1;k<=14;k++)
    {
        for(i=0;i<17;i++)
            for(j=1;j<17;j++)
                way[k][i][j]=way[k-1][i-1][j]+way[k-1][i][j+1]
                            +way[k-1][i+1][j]+way[k-1][i+1][j+1]
                            +way[k-1][i][j-1]+way[k-1][i-1][j-1];
        list[k]=way[k][8][8];
    }
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        printf("%d\n",list[n]);
    }
    return 0;
}
