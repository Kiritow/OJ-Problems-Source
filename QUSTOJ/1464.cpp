#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

char a[1024];
char b[1024];

int main()
{
    while(gets(a)!=NULL)
    {
        if(strlen(a)<1)
        {
            continue;
        }
        int i=0,j=0;
        while(a[i]!=0)
        {
            if(a[i]!=' ')
            {
                b[j++]=a[i];
            }
            ++i;
        }
        b[j]=0;
        puts(b);
    }
    return 0;
}
