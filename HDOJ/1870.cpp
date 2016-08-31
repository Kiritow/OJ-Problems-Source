#include <cstdlib>
#include <cstdio>
#include <cstring>
using namespace std;

char buffer[1024];
int main()
{
    while(scanf("%s",buffer)==1)
    {
        int idt=strstr(buffer,"B")-buffer;
        int cnt=0;
        for(int i=idt-1;i>=0;i--)
        {
            if(buffer[i]=='(') cnt++;
            else cnt--;
        }
        printf("%d\n",cnt);
    }
    return 0;
}
