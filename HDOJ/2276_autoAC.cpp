#include <stdio.h>
#include <string.h>
int a[105][105];
int ans[105];
int tag[105];
char str[105];
int tag1[105][105];
int main()
{
    int i,j,m,n,k;
    while(scanf("%d",&m)!=EOF)
    {
        scanf("%s",str);
        n=strlen(str);
        for (i=0;i<n;i++)
        {
            for (j=0;j<n;j++)
            {
                if (j==i || j==(i+n-1)%n) a[i][j]=1;
                else a[i][j]=0;
            }
        }
        for (i=0;i<n;i++)
        {
            ans[i]=str[i]-'0';
        }
        while(m!=0)
        {
            if (m%2==1)
            {
                for (i=0;i<n;i++)
                {
                    tag[i]=0;
                    for (j=0;j<n;j++)
                    {
                        tag[i]=(tag[i]+a[i][j]*ans[j])%2;
                    }
                }
                for (i=0;i<n;i++)
                {
                    ans[i]=tag[i];
                }
            }
            m=m/2;
            for (i=0;i<n;i++)
            {
                for (j=0;j<n;j++)
                {
                    tag1[i][j]=0;
                    for (k=0;k<n;k++)
                    {
                        tag1[i][j]=(tag1[i][j]+a[i][k]*a[k][j])%2;
                    }
                }
            }
            for (i=0;i<n;i++)
            {
                for (j=0;j<n;j++)
                {
                    a[i][j]=tag1[i][j];
                }
            }
        }
        for (i=0;i<n;i++)
        {
            printf("%d",ans[i]);
        }
        printf("\n");
    }
    return 0;
}
