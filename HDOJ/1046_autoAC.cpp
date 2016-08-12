#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cmath>
using namespace std;
int main(void)
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i < n + 1; ++i)
    {
        printf("Scenario #%d:\n", i);
        int s, t;
        scanf("%d%d",&s,&t);
        double sum;
        sum = s*t;
        if ((s*t)%2)
            printf("%.2f\n", sum+sqrt(2)-1);
        else printf("%.2f\n", (double)sum);
        printf("\n");
    }
    return 0;
}
