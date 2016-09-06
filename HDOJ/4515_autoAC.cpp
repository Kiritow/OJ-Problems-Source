#include <stdio.h>
int a[] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
const int Y = 2013,M = 3,D = 24;
int leap(int y)
{
    if(y%400 == 0 || (y%4==0 && y%100!=0))
        return 1;
    return 0;
}
void deal1(int k)
{
    int y = Y,m = M,d = D;
    while(k--)
    {
        if(leap(y))
            a[2] = 29;
        else
            a[2] = 28;
        d--;
        if(d<=0)
        {
            m--;
            if(m<=0)
            {
                m = 12;
                y--;
            }
            d = a[m];
        }
    }
    printf("%04d/%02d/%02d",y,m,d);
}
void deal2(int k)
{
    int y = Y,m = M,d = D;
    while(k--)
    {
        if(leap(y))
            a[2] = 29;
        else
            a[2] = 28;
        d++;
        if(d>a[m])
        {
            m++;
            if(m>12)
            {
                m = 1;
                y++;
            }
            d = 1;
        }
    }
    printf("%04d/%02d/%02d ",y,m,d);
}
int main()
{
    int n,m;
    scanf("%d",&n);
    while(n--)
    {
        scanf("%d",&m);
        deal2(m);
        deal1(m);
        printf("\n");
    }
    return 0;
}
