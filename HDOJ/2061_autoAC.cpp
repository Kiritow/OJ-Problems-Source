#include <stdio.h>
struct node
{
    double n,score;
    char name[5555];
}
;
node f[5555];
int main()
{
    int t,i,j;
    scanf("%d",&t);
    while(t--)
    {
        int flag=0;
        int m;
        double sum=0,sum1=0;
        scanf("%d",&m);
        for(i=1;i<=m;i++)
            scanf("%s%lf%lf",f[i].name,&f[i].n,&f[i].score);
        for(i=1;i<=m;i++)
        {
            if(f[i].score<60)
                flag=1;
            sum+=f[i].n*f[i].score;
            sum1+=f[i].n;
        }   
        if(flag)
            printf("Sorry!\n");
        else
            printf("%.2lf\n",sum*1.0/sum1);
        if(t)
            printf("\n");
    }
    return 0;
}
