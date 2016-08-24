#include <stdio.h>
int main()
{
    int n,k,i,num;
    scanf("%d",&n);
    while(n--)
    {
        num=0;
        scanf("%d",&k);
        for(i=1;i<=k;i++)
        {
            if(i*i<=k)
                num++;
            else
                break;
        }
        for(i=1;i<=k;i++)
        {
            if(2*i*i<=k)
                num++;
            else
                break;
        }
        printf("%d\n",num%2);        
    }
    return 0;
}
