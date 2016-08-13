#include <stdio.h>
int leapyear(int Y)
{
    if((Y%4==0 && Y%100!=0) || (Y%400==0))
      return 1;
    else
      return 0;
}
int main()
{
    int Y,N,n,count;
    scanf("%d",&n);
    while(n--)
    {
        count=0;
        scanf("%d%d",&Y,&N);
        while(count<N)
        {
            if(leapyear(Y))
            {
              count++;
              Y++;
            }
            else
            {
                Y++;
            } 
        }
        printf("%d\n",Y-1);
    }
}
