#include <stdio.h>
#include <string.h>
int main()
{
    int n;
    int s[20],i,len;
    char str[20];
    scanf("%d%*c",&n);
    while(n--)
    {
        gets(str);
        len = strlen(str);
        for(i = 0;i<len;i++)
        {
            s[i+1] = str[i]-48;
        }
        printf("He/She is from ");
        if(s[1] == 3 && s[2] == 3)
        printf("Zhejiang");
        else if(s[1] == 1 && s[2] == 1)
        printf("Beijing");
        else if(s[1] == 7 && s[2] == 1)
        printf("Taiwan");
        else if(s[1] == 8 && s[2] == 1)
        printf("Hong Kong");
        else if(s[1] == 8 && s[2] == 2)
        printf("Macao");
        else if(s[1] == 2 && s[2] == 1)
        printf("Liaoning");
        else if(s[1] == 5 && s[2] == 4)
        printf("Tibet");
        else if(s[1] == 3 && s[2] == 1)
        printf("Shanghai");
        printf(",and his/her birthday is on %d%d,%d%d,%d%d%d%d based on the table.\n",s[11],s[12],s[13],s[14],s[7],s[8],s[9],s[10]);
    }
}
