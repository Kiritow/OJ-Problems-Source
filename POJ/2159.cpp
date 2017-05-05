#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

char linea[1024];
char lineb[1024];

int bina[26];
int binb[26];

int main()
{
    gets(linea);
    gets(lineb);

    int len=strlen(lineb);
    for(int i=0;i<len;i++)
    {
        bina[linea[i]-'A']++;
        binb[lineb[i]-'A']++;
    }

    sort(bina,bina+26);
    sort(binb,binb+26);

    bool isok=true;
    for(int i=0;i<26;i++)
    {
        if(bina[i]!=binb[i])
        {
            isok=false;
            break;
        }
    }
    if(isok)
    {
        printf("YES\n");
    }
    else
    {
        printf("NO\n");
    }
    return 0;
}
