#include<stdio.h>
int main()
{
    int n,a,b,c;
    scanf("%d",&n);
    while(n--)
    {
        scanf("%d%d%d",&a,&b,&c);
        if(a*a==b*b+c*c||b*b==a*a+c*c||c*c==a*a+b*b)
        printf("good\n");
        else if(a==b||a==c||b==c)
        printf("perfect\n");
             else
               printf("just a triangle\n");
    }
    return 0;
}
