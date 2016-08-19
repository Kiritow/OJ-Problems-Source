#include<stdio.h>
int main()
{
    int T;
    int num,a,b;
    while(~scanf("%d",&T))
    {
        while(T--)
        {
            scanf("%d %d %d",&num,&a,&b);
            if(num >= 6)
            {
                a+= num * 8 - 21;
            }
            else
            {
                a+= (15-num)*num/2; 
            }
            a>=b?puts("Yes"):puts("No");
        }
    }
    return 0;
}
