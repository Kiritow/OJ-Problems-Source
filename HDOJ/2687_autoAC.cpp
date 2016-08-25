#include<stdio.h>
int main()
{
    int n,i,k,j,a[11][11],b[11][11];
    while(scanf("%d",&n)!=EOF){
        for(i=1;i<=n;i++)
            for(j=1;j<=n;j++)
                scanf("%d",&a[i][j]);
        scanf("%d",&k);
        for(i=1;i<=n;i++)
            for(j=1;j<=n;j++) 
                b[i][j]=(a[i][j]+a[j][n+1-i]+a[n+1-i][n+1-j]+a[n+1-j][i])*(k/4);
        if(k%4==0)
            for(i=1;i<=n;i++)
                for(j=1;j<=n;j++)
                    b[i][j]+=a[i][j];
        else if(k%4==1)
            for(i=1;i<=n;i++)
                for(j=1;j<=n;j++)
                    b[i][j]+=a[i][j]+a[n+1-j][i];
        else if(k%4==2)
            for(i=1;i<=n;i++)
                for(j=1;j<=n;j++)
                    b[i][j]+=a[i][j]+a[n+1-j][i]+a[n+1-i][n+1-j];
        else
            for(i=1;i<=n;i++)
                for(j=1;j<=n;j++)
                    b[i][j]+=a[i][j]+a[n+1-j][i]+a[n+1-i][n+1-j]+a[j][n+1-i];
        for(i=1;i<=n;i++){
            for(j=1;j<=n;j++){
                printf("%d",b[i][j]);
                if(j<n)
                printf(" ");}
            printf("\n");
        }
    }
}
