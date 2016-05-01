#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;
int is_prime[10005];
 
int answer[10005];
 
char cmdline[10240];
char buff[16];
 
int strlenx(const char* inc)
{
    int i=0;
    while(inc[i]!='\0')
        i++;
    return i;
}
int main()
{
    //Form a list
    int i,j,k;
    is_prime[2]=1;
    for(i=3; i<10000; i++)
    {
        for(j=2; j<i; j++)
        {
            if(i%j==0) break;
        }
        if(j==i) is_prime[i]=1;
    }
    //With this list, we can do something
    int times,inc;
    scanf("%d",&times);
    for(; times>0; times--)
    {
        scanf("%d",&inc);
        memset(answer,0,sizeof(int)*10005);
        //Now we still have to deal it...
        int k_copy;
        for(k=2; k<=inc; k++)
        {
            k_copy=k;
            int current_prime=2;
            while(k_copy>1)
            {
                if(k_copy%current_prime==0)
                {
                    answer[current_prime]++;
                    k_copy=k_copy/current_prime;
                    continue;
                }
                //Find next prime
                for(current_prime=current_prime+1; current_prime<10000; current_prime++)
                {
                    if(is_prime[current_prime]) break;
                }
            }
        }
        memset(cmdline,0,10240);
        for(i=1; i<10000; i++)
        {
            if(answer[i])
            {
                sprintf(buff,"%d ",answer[i]);
                strcat(cmdline,buff);
            }
        }
        cmdline[strlenx(cmdline)-1]='\0';
        printf("%s\n",cmdline);
    }
    return 0;
}
 
