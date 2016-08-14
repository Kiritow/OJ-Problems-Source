#include <stdio.h>
#include <string.h>
int main()
{
    int a[10004],i,j,t;
    memset(a,0,sizeof(a));
    for (i=1;i<10004/2;i++)
    {
        for (j=i*2;j<=10000;j=j+i)
        {
            a[j]+=i;
        }
    }
    scanf("%d",&t);
    while (t--)
    {
        int num1,num2,count=0;
        scanf("%d%d",&num1,&num2);
        if (num1>num2)
        {
            num1^=num2;
            num2^=num1;
            num1^=num2;
        }
        for (i=num1;i<=num2;i++)
        {
            if (a[i]==i)
            {
                count++;
            }
        }
        printf("%d\n",count);
    }
    return 0;
}
