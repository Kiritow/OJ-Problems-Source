#include<iostream>
using namespace std;
int main()
{
    int n;
    scanf("%d", &n);
    while(n--)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        if(a % 2 == 1|| b > a / 2)
            printf("NO\n");
        else
            printf("YES\n");
    }
    return 0;
}
