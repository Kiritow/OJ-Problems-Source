#include <stdio.h>
int main()
{
    int num,d,t;
    int a[10]={0,1,2,2,4,4,6,6,10,10};
    scanf("%d",&t);
    while(t--)
    {
        d=0;
        scanf("%d",&num);
        while(num)
        {
            d=num%10;
            num/=10;
        }
        printf("%d\n",a[d]);
    }
    return 0;
}
