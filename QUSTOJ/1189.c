#include <stdio.h>
int main()
{
    int plan[12];
    int month,saved,now;
    for(month=0,saved=0,now=0;month<12;month++)
    {
        scanf("%d",&plan[month]);
    }
    for(month=0;month<12;month++)
    {
        now+=300;
        if(now-plan[month]>=100)
        {
            saved=saved+((now-plan[month])/100)*100;
            now=now-((now-plan[month])/100)*100;
            now=now-plan[month];
            continue;
        }
        else if(now-plan[month]<0)
        {
            printf("%c%d\n",'-',month+1);
            return 0;
        }
        else
        {
            now=now-plan[month];
        }
    }
    printf("%d\n",now+(saved*6)/5);
    return 0;
}
