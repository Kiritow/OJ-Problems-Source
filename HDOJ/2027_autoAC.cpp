#include <ctype.h>
#include <stdio.h>
int main(void)
{
    int n;
    int y[5];
    char c;
    scanf("%d%*c", &n);
    while (n--)
    {
        y[0] = y[1] = y[2] = y[3] = y[4] = 0;
        while ((c = getchar()) != '\n')
        {
            switch (tolower(c))
            {
                case 'a':
                    y[0]++;
                    break;
                case 'e':
                    y[1]++;
                    break;
                case 'i':
                    y[2]++;
                    break;
                case 'o':
                    y[3]++;
                    break;
                case 'u':
                    y[4]++;
                    break;
                default :
                    break;
            }
        }
        printf("a:%d\n", y[0]);
        printf("e:%d\n", y[1]);
        printf("i:%d\n", y[2]);
        printf("o:%d\n", y[3]);
        printf("u:%d\n", y[4]);
        if (n) putchar('\n');
    }
    return 0;
}
