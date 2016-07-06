#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct
{
    char name[1024];
    int id;
    int ENG,MATH;
} _sinfo;
_sinfo sinfo[5];
int cmp(const void* a,const void* b)
{
    int cret;
    if((cret=strcmp(((_sinfo*)a)->name,((_sinfo*)b)->name))==0)
    {
        if(((_sinfo*)a)->ENG==((_sinfo*)b)->ENG)
        {
            return ((_sinfo*)a)->MATH - ((_sinfo*)b)->MATH;
        }
        else return ((_sinfo*)a)->ENG - ((_sinfo*)b)->ENG;
    }
    else return cret;
}
int main()
{
    for(int i=0;i<5;i++)
    {
        scanf("%d %s %d %d",&sinfo[i].id,sinfo[i].name,&sinfo[i].ENG,&sinfo[i].MATH);
    }
    qsort(sinfo,5,sizeof(_sinfo),cmp);
    for(int i=0;i<5;i++)
    {
        printf("%d %s %d %d\n",sinfo[i].id,sinfo[i].name,sinfo[i].ENG,sinfo[i].MATH);
    }
    return 0;
}
