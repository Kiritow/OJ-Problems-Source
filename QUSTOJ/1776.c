#include <stdio.h>
#include <stdlib.h>

char str[128];
int main()
{
    int t;
    scanf("%d",&t);
    int sc=0;
    int tmp;
    while(t--)
    {
        scanf("%d",&tmp);
        if(tmp>sc) scanf("%s",str),sc=tmp;
        else scanf("%*s");
    }
    return printf("%d %s\n",sc,str),0;
}
