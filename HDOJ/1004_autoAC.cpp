#include <stdio.h>
#include <string.h>
#include <stdlib.h>
char ballons[1000][15];
int sum[1000];
int ballons_idx;
int n;
int InBallons(char* tmp)
{
    int i;
    for (i=0;i<ballons_idx;i++)
    {
        if (strcmp(tmp,ballons[i]) == 0)
        {
            sum[i]++;
            return 1;
        }
    }
    return 0;
}
int FindMax()
{
    int i, max=-1, idx=0;
    for (i=0;i<ballons_idx;i++)
    {
        if (sum[i]>max)
        {
            max = sum[i];
            idx = i;
        }         
    }
    return idx;
}
int main()
{
    int i;
    char tmp[15];
    scanf("%d",&n);
    while(n)
    {
        ballons_idx = 0;
        memset(sum,0,sizeof(int)*1000);
        for (i=0;i<n;i++)
        {
            scanf("%s",tmp);
            if (InBallons(tmp) == 0)
            {
                strcpy(ballons[ballons_idx++],tmp);
            }
        }
        printf("%s\n",ballons[FindMax()]);
        scanf("%d",&n);
    }
    return 0;
}
