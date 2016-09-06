#include <iostream>
#include <stdio.h>
#include <cstring>
using namespace std;
char str[100050];
int num[100050];
int main()
{
    int t,i;
    while(~scanf("%d",&t))
    {
        while(t--)
        {
            scanf("%s",str);
            int n;
            n = strlen(str);
            for(i = 0;i < n;i++)
            num[i] = str[i]-'0';
            int rest;
            rest  = 0;
            for(i = 0;i < n;i++)
            rest += num[i];
            rest = 10-rest%10;
            num[n-1] += rest;
            int bit;
            bit = 0;
            if(num[n-1] > 9)
            {
                for(i = n-2;i >= 0;i--)
                {
                    bit++;
                    num[i]++;
                    num[i] %= 10;
                    if(num[i])
                    break;
                }
                if(i<0)
                {
                    printf("1");
                    for(i = n-1;i > 0;i--)
                    printf("0");
                    puts("9");
                }
                else
                {
                    num[n-1] = (num[n-1]+1000000-bit)%10;
                    for(i = 0;i < n;i++)
                    printf("%d",num[i]);
                    puts("");
                }
            }
            else
            {
                for(i = 0;i < n;i++)
                printf("%d",num[i]);
                puts("");
            }
        }
    }
    return 0;
}
