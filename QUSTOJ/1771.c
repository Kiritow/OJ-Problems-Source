#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int Y,M,D;
        scanf("%d %d %d",&Y,&M,&D);
        struct tm k;
        memset(&k,0,sizeof(k));
        k.tm_year=Y-1900;
        k.tm_mon=M-1;
        k.tm_mday=D;
        k.tm_hour=0;
        k.tm_min=0;
        k.tm_sec=0;
        struct tm s;
        memset(&s,0,sizeof(s));
        s.tm_year=1990-1900;
        s.tm_mon=1-1;
        s.tm_mday=1;
        s.tm_hour=0;
        s.tm_min=0;
        s.tm_sec=0;
        time_t a=mktime(&k);
        time_t b=mktime(&s);
        int day=(a-b)/(3600*24);
        if(day%5<3)
        {
            printf("1\n");
        }
        else
        {
            printf("0\n");
        }
    }
    return 0;
}
