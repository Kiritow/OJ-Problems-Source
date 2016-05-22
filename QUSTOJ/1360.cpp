#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

int a,b,c,d;
char buff[2048];
int main()
{
    gets(buff);
    int L=strlen(buff);
    for(int i=0;i<L;i++)
    {
        if((buff[i]>='a'&&buff[i]<='z')||(buff[i]>='A'&&buff[i]<='Z'))
        {
            a++;
        }
        else if(buff[i]>='0'&&buff[i]<='9')
        {
            b++;
        }
        else if(buff[i]==' ')
        {
            c++;
        }
        else
        {
            d++;
        }
    }
    printf("%d %d %d %d \n",a,b,c,d);
    return 0;
}
