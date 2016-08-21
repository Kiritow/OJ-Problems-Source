#include <stdio.h>
int main()
{
    int n,m,i;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        if(n<=m)
        {
            for(i=n;i<m;i++)
            {
                printf("%d ",i);
            }
            printf("%d\n",i);
        }
        else
        {
            if(n%(m+1))
            {
                printf("%d\n",n%(m+1));
            }
            else
                printf("none\n");
        }
    }
}
