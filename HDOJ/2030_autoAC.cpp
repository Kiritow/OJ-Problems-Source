#include <stdio.h>
#include <string.h>
int main(void)
{
    int n;
    int count;
    char c;
    scanf("%d%*c", &n);
    while (n--)
    {
        count = 0;
        while ((c = getchar()) != '\n')
        {
            if (c < 0)
                count++;
        }
        printf("%d\n", count / 2);
    }
    return 0;
}
