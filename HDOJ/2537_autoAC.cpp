#include<stdio.h>
int main ()
{
    char str[20];
    int r, y, n;
    int i;
    while(~scanf("%d", &n) && n)
    {
        r = 7;
        y = 7;
        getchar();
        gets(str);
        for(i = 0 ; i < n; i++)
            switch(str[i])
        {
            case 'R': r--; break;
            case 'Y': y--; break;
            case 'B': if(r) printf("Yellow\n"); else printf("Red\n");  break;
            case 'L': if(y) printf("Red\n"); else printf("Yellow\n");  break;
            default:break;
        }
    }
    return 0;
}
