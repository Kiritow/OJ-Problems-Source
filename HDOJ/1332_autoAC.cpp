#include<stdio.h>
int col,s;
void out(int step,int shu)
{
    int i,j;
    if(step==1)
    {
        if(shu==1||shu==4)
        {
            for(i=1;i<=col;i++)
                printf(" ");
        }
        else
        {
            printf(" ");
            for(i=1;i<=col-2;i++)
                printf("-");
            printf(" ");
        }
    }
    else
        if(step==2*s+3)
        {
            if(shu==1||shu==4||shu==7)
            {
               for(i=1;i<=col;i++)
                    printf(" ");
            }
            else
            {
                printf(" ");
               for(i=1;i<=col-2;i++)
                     printf("-");
                     printf(" ");
            }
        }
        else
            if(step==(2*s+4)/2)
            {
                if(shu==1||shu==7||shu==0)
                     for(i=1;i<=col;i++)
                            printf(" ");
                else
                {
                    printf(" ");
                   for(i=1;i<=col-2;i++)
                        printf("-");
                        printf(" ");
                }
            }
            else
                if(step<(2*s+4)/2)
                {
                    if(shu==1||shu==2||shu==7||shu==3)
                    {
                        for(i=1;i<col;i++)
                        printf(" ");
                        printf("|");
                    }
                    else
                        if(shu==5||shu==6)
                        {
                            printf("|");
                            for(i=1;i<col;i++)
                                printf(" ");
                        }
                        else
                        {
                            printf("|");
                            for(i=1;i<col-1;i++)
                                printf(" ");
                            printf("|");
                        }
                }
                else
                {
                    if(shu==1||shu==3||shu==4||shu==5||shu==7||shu==9)
                    {
                        for(i=1;i<col;i++)
                            printf(" ");
                        printf("|");
                    }
                    else
                        if(shu==2)
                        {
                            printf("|");
                            for(i=1;i<col;i++)
                              printf(" ");
                        }
                        else
                        {
                            printf("|");
                            for(i=1;i<col-1;i++)
                            {
                                printf(" ");
                            }
                            printf("|");
                        }
                }
}
int main()
{
    int  n;
    int t[20];
    while(scanf("%d%d",&s,&n)==2&&s&&n)
    {
        int i,j,k,x=0;
        while(n>0)
        {
            t[x++]=n%10;
            n/=10;
        }
        col=2+s;
        for(i=1;i<=2*s+3;i++)
        {
            for(j=x-1;j>=0;j--)
            {
                out(i,t[j]);
                if(j>0)
                    printf(" ");
            }
            printf("\n");
        }
        printf("\n");
    }
    return 0;
}
