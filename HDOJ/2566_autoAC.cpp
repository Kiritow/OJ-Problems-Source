#include<stdio.h>
int main()
{
    int m,n,x,s,c,i,j;
    scanf("%d",&x);
    while(x--)
    {
        c=0;
        scanf("%d%d",&n,&m);
        s=5*n-m;
        for(i=0;i<=n;i++)
        {
            for(j=0;j<=n;j++)
            {
                if(4*i+3*j==s && n-i-j>=0)
                    c++;
            }
        }
        printf("%d\n",c);
    }
    return 0;
}
