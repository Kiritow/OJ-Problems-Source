#include <stdio.h>
#include <string.h>
int main(void)
{
    char number[61];
    int value[60];
    int result[60];
    int i,j,k,l;
    int flag;
    while(gets(number))
    {
        int n = strlen(number);
        for(i = 0; i < n; i++)
            value[i] = number[i] - '0';
        for(i = 1; i <= n; i++)
        {
            flag  = 0;
            int r  = 0;
            for(j = n - 1; j >= 0; j--)
            {
                r += value[j] * i;
                result[j]  = r % 10;
                r /= 10;
            }
            for(j = 0; j < n; j++)
            {
                if(result[j] == value[0])
                {
                    k = j;
                    for(l = 0; l < n; l++)
                    {
                        if(result[k] != value[l])
                            break;
                        k == n - 1 ? k = 0:k++;
                    }
                    if(l == n)
                    {
                        flag = 1;
                        break;
                    }
                }
            }
            if(flag  == 0)
                break;
        }
        printf("%s is %scyclic\n",number,flag == 0? "not ":"");
    }
    return 0;
}
