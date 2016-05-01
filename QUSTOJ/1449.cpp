#include <stdio.h>
int func(int n)
{
    switch(n)
    {
    case 1:
        return 0;
    case 2:
        return 1;
    case 3:
        return 2;
    case 4:
        return 9;
    case 5:
        return 44;
    default:
        return (n-1)*(func(n-1)*func(n-2));
    }
}
int main()
{
    int inc;
    while(scanf("%d",&inc)==1)
    {
        printf("%d\n",func(inc));
    }
    return 0;
}
