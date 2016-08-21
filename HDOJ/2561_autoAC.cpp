#include<stdio.h>
int main ()
{
    int min, temp;
    int t, n, a;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d", &n);
        scanf("%d", &min);
        scanf("%d", &temp);
        if(min > temp)
        {
            min += temp;
            temp = min - temp;
            min = min -temp;
        }
        for(n -= 2; n; n--)
        {
            scanf("%d",&a);
            if(a <= min)
            {
                temp = min;
                min = a;
            }
            else if(a < temp) 
                temp = a;
        }
        printf("%d\n", temp);
    }
    return 0;
}
