#include<iostream>
#include<string>
#include<string.h>
using namespace std;
int main()
{    
    int n, p=1;
    scanf("%d", &n);
    while(n--)
    {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        if(a > b)
            swap(a, b);
        if(b > c)
            swap(b, c);
        if(a > b)
            swap(a, b);
        printf("Case #%d: ", p++);
        if(a+b <= c)
            printf("invalid!\n");
        else if(a==b && b==c)
            printf("equilateral\n");
        else if(a==b || b==c)
            printf("isosceles\n");
        else
            printf("scalene\n");
    }
    return 0;
}
