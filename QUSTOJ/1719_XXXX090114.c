#include<stdio.h>

int main()
{
    int x,i,j,k;
    scanf("%d",&x);
    for(i=1;i<=x;++i)
    {
        for(j=i;j<=x;++j)
            for(k=j;k<=x;++k)
            {
                if(i*i+j*j==k*k)
                    printf("%d %d %d\n",i ,j ,k);
            }
    }

    return 0;
}

