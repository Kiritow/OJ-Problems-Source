#include <stdio.h>
#include <string.h>
const int MAXN = 100;
int main(void)
{
    char str[MAXN];
    int i,j;
    while(scanf("%s",str) != EOF)
    {
        char str1[MAXN];
        memset(str1,0x30,sizeof(str1));
        int index = 0;
        for(i = strlen(str) - 1; i > 1; i--)
        {
            int num = str[i] - '0';
            int temp;
            for(j = 0; j < index || num; j++)
            {
                temp = num * 10 + (j < index ? str1[j] - '0': 0);
                str1[j] = temp/8 + '0';
                num = temp%8;
            }
            index = j;
        }
        str1[j] = '\0';
        printf("%s [8] = 0.%s [10]\n",str,str1);
    }
    return 0;
}
