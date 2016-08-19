#include<stdio.h>
#include<stdio.h>
int main()
{
    char c[81][81],a,b,w=0;
    int m,i,j,k,n;
    while(scanf("%d %c %c",&n,&a,&b)!=EOF)
    {
        if(w++)
        printf("\n");
            m=n/2;
            int q=0;
            for(q=0;q<a;q++)
            {
                for(i=q;i<n-q;i++)
                {
                    for(j=q;j<n-q;j++)
                    {
                        if(q%2==0&&(m%2==0))
                        c[i][j]=a;
                        else if(q%2!=0&&(m%2==0))
                        c[i][j]=b;
                        else if(q%2==0&&(m%2!=0))
                        c[i][j]=b;
                        else
                        c[i][j]=a;
                    }
                }
            }
            c[0][0]=c[0][n-1]=c[n-1][0]=c[n-1][n-1]=' ';
            if(n==1)
            {
                printf("%c\n",a);
            }
            else
            {
            for(i=0;i<n;i++)
            {
                for(j=0;j<n;j++)
                {
                    printf("%c",c[i][j]);
                }
                printf("\n");
            }
            }
    }
    return 0;
}
