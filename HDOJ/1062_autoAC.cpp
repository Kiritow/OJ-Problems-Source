#include<iostream>
#include<string.h>
#include<stdio.h>
using namespace std;
const int Max = 1000 + 10;
char str[Max];
char w[Max];
int main()
{
    int cases;
    cin >> cases;
    char c = getchar();
    while(cases--)
    {
        gets(str);
        int pos = 0;
        int len = strlen(str);
        for(int i=0; i<=len; i++)
        {
            if(str[i] == ' ')
            {
                w[pos++] = '\0';
                strrev(w);
                printf("%s ", w);
                pos = 0;
            }
            else if(str[i] == '\0')
            {
                w[pos++] = '\0';
                strrev(w);
                printf("%s", w);
                pos = 0;
            }
            else
            {
                w[pos++] = str[i];
            }
        }
        printf("\n");
    }
    return 0;
}
