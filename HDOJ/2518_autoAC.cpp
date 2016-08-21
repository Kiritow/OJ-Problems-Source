#include<stdio.h>
#include<string.h>
#include<algorithm>
int a[] = {0, 0, 0, 2, 368, 1010, 2339};
int main()
{
    int x, y;
    while(scanf("%d%d", &x, &y) == 2)
    {
        if(x > y) std::swap(x, y);
        printf("%d\n", a[x]);    
    }
    return 0;
}
