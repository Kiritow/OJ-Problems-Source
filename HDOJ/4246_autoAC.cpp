#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
char str[100];
int cas = 1;
int main()
{
    while(gets(str))
    {
        printf("Case %d: ",cas++);
        int i,j,len;
        len = strlen(str);
        if(str[1] == ' ')
            printf("UNIQUE\n");
        else
        {
            if(str[1] == '#')
            {
                if(str[0] == 'G')
                    printf("Ab");
                else
                    printf("%cb",str[0]+1);
            }
            else if(str[1] == 'b')
            {
                if(str[0] == 'A')
                printf("G#");
                else
                printf("%c#",str[0]-1);
            }
            for(i = 2;i<len;i++)
            printf("%c",str[i]);
            printf("\n");
        }
    }
    return 0;
}
