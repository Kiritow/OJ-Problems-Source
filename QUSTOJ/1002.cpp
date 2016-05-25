#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    long total=0;
    char maxname[32];
    long maxtotal=0;
    int n=0;
    char buff[32];
    char west,leader;
    int test,mark;
    int paper;
    long tmp=0;
    scanf("%d",&n);
    for(;n>0;n--)
    {
        scanf("%s %d %d %c %c %d",buff,&test,&mark,&leader,&west,&paper);
        tmp=0;
        if(test>80&&paper>0) 
        {
            tmp+=8000;
        }
        if(test>85&&mark>80)
        {
            tmp+=4000;
        }
        if(test>90)
        {
            tmp+=2000;
        }
        if(test>85&&west=='Y')
        {
            tmp+=1000;
        }
        if(mark>80&&leader=='Y')
        {
            tmp+=850;
        }
        if(tmp>maxtotal)
        {
            strncpy(maxname,buff,32);
            maxtotal=tmp;
        }
        total+=tmp;
    }
    printf("%s\n%d\n%d\n",maxname,maxtotal,total);
    return 0;
}
