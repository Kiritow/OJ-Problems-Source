#include <stdio.h>
 
//Written by Coffee. 判断素数
int isPrime(int num)
{
    if (num == 2 || num == 3)
    {
        return 1;
    }
    if (num % 6 != 1 && num % 6 != 5)
    {
        return 0;
    }
    for (int i = 5; i*i <= num; i += 6)
    {
        if (num % i == 0 || num % (i+2) == 0)
        {
            return 0;
        }
    }
    return 1;
}
 
int main()
{
    int a;
    scanf("%d",&a);
    for(int i=2;i<=a/2;i++)
    {
        if(isPrime(i)&&isPrime(a-i))
        {
            printf("%d=%d+%d\n",a,i,a-i);
        }
    }
    return 0;
}
