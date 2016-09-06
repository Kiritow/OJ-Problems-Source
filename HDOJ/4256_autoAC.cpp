#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
int main()
{
    char str[20][10] = {"#","I","II","III","IV","V","VI","VII","VIII","IX","X","XI","XII"};
    char s[10];
    int i,cas = 1;
    while(~scanf("%s",s))
    {
        for(i = 1;i<=12;i++)
        {
            if(strcmp(s,str[i])==0)
            {
                printf("Case %d: %d\n",cas++,i);
            }
        }
    }
    return 0;
}
