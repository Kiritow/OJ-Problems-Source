#include <iostream>
#include <string>
using namespace std;
const int LEN = 210;
char engChars[30] = {"ABCDEFGHIJKLMNOPQRSTUVWXYZ"};
char aLine[LEN];
void decipher()
{
    for (int i = 0;i < strlen(aLine);i ++)
    {
        if (isalpha(aLine[i]))
        {
            int offset = (aLine[i] - 'A' + 26 - 5) % 26;
            aLine[i] = engChars[offset];
        }
    }
}
int main ()
{
    while (gets(aLine))
    {
        if (strcmp(aLine,"ENDOFINPUT") == 0)
            break;
        while (1)
        {
            gets(aLine);
            if (strcmp(aLine,"END") == 0)
                break;
            decipher();
            printf("%s\n",aLine);        
        }
    }
    return 0;
}
