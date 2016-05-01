#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;
//WTF!!! I still have to use this function!
int strlenx(const char* inc)
{
    int i=0;
    while(inc[i]!='\0') i++;
    return i;
}
const char* keyboard="`1234567890-=~!@#$%^&*()_+QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./M<>?L:\"P{}|";
char change(char inc)
{
    int i;
    int len=strlenx(keyboard);
    for(i=0;i<len;i++)
    {
        if(inc==keyboard[i])
        {
            return keyboard[i-1];
        }
    }
    return inc;
}
char cmdline[1024];
int main()
{
    gets(cmdline);
    int len=strlenx(cmdline);
    int i;
    for(i=0;i<len;i++)
    {
        cmdline[i]=change(cmdline[i]);
    }
    puts(cmdline);
    return 0;
}
