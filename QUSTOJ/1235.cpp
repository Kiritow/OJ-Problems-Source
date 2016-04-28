#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;
int data[1005];
char cmdline[10240];
char buff[32];
int main()
{
    int inc,times,count;
    while(scanf("%d",&times)==1)
    {
        memset(data,0,sizeof(int)*1005);
        memset(cmdline,0,10240);
        count=0;
        for(int i=0;i<times;i++)
        {
            scanf("%d",&inc);
            data[inc]++;
        }
        for(int i=0;i<1005;i++)
        {
            if(data[i])
            {
                count++;
                sprintf(buff,"%d ",i);
                strcat(cmdline,buff);
            }
        }
        cmdline[strlen(cmdline)-1]='\0';
        printf("%d\n%s\n",count,cmdline);
    }
    return 0;
}
