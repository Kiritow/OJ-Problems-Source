#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;

char buff[1024];

int main()
{
    gets(buff);
    int l=strlen(buff);
    for(int i=0;i<l;i++)
    {
        if(buff[i]=='a'||buff[i]=='e'||buff[i]=='i'||buff[i]=='o'||buff[i]=='u')
        {
            printf("%c",buff[i]);
        }
    }
    printf("\n");
    return 0;
}
