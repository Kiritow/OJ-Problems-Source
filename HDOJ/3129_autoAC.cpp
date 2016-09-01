#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;
int main()
{
    char s[1017];
    int tt = 0;
    while(gets(s))
    {
        tt++;
        int len = strlen(s);
        for(int i = 0; i < len; i++)
        {
            if(i == 0 && tt > 1)
            {
                while(s[i]==' ' || s[i]=='(' || s[i]==')')
                {
                    i++;
                    if(i >= len)
                        break;
                }
                s[i] = toupper(s[i]);
            }
            else if(s[i]=='.' || s[i]=='!' || s[i]=='?')
            {
                i++;
                while(s[i]==' ' || s[i]=='(' || s[i]==')')
                {
                    i++;
                    if(i >= len)
                        break;
                }
                s[i] = toupper(s[i]);
            }
            else
            {
                s[i] = tolower(s[i]);
            }
        }
        printf("%s\n",s);
    }
    return 0;
}
