#include <stdio.h>
#define sample scanf("%d", &b);
#define hahaha printf("/\\ /\\\n  _");
#define outspace printf(" ");
#define bigchange printf("\n");

int main()
{
    int a;
    scanf("%d", &a);
    for(int i = 0, b; i < a; i++)
    {
        sample
        if(b == 1)
        {
            hahaha
        }
        else
        {
            printf("\n");
            for(int j = 0; j < b; j++)
            {
                for(int k = 0; k < b-j-1; k++)
                {
                    outspace
                }
                printf("/");
                for(int k = 0; k < j*2; k++)
                {
                    outspace
                }
                printf("\\");
                for(int k = 0; k < b*3-(j+1)*2; k++)
                {
                    outspace
                }
                printf("/");
                for(int k = 0; k < j*2; k++)
                {
                    outspace
                }
                printf("\\");
                bigchange
            }
            for(int j = 0; j < b-1; j++)
            {
                bigchange
            }
            for(int j = 0; j < b*2; j++)
            {
                outspace
            }
            for(int j = 0; j < b; j++)
            {
                printf("_");
            }
        }
        bigchange
    }
    return 0;
}
