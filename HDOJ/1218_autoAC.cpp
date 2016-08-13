#include<stdio.h>
#include<string.h>
int main()
{
    int i,j,R,C;
    int a[10][10],b[10][10];
    char c,str[10];
    for(i=0;i<10;i++)
    {
        for(j=0;j<10;j++)
        {
            a[i][j]=0;
            b[i][j]=0;
        }
    }
    while(1)
    {
        scanf("%s",str);
        if(strcmp(str,"ENDOFINPUT")==0)
         break;
         if(strcmp(str,"START")==0)
        {
            scanf("%d%d",&R,&C);
            getchar();
            for(i=0;i<R;i++)
            {
                for(j=0;j<C;j++)
                {
                    scanf("%c",&c);
                    a[i][j]=c-'0';
                }
                getchar();
            }
            for(i=0;i<R-1;i++)
            {
                for(j=0;j<C-1;j++)
                {
                     b[i][j]=(a[i][j]+a[i+1][j]+a[i][j+1]+a[i+1][j+1])/4;
                }
            }
            for(i=0;i<R-1;i++)
            {
                for(j=0;j<C-1;j++)
                {
                    printf("%d",b[i][j]);
                }
                printf("\n");
            }
        }
        if(strcmp(str,"END")==0) continue;
    }
        return 0;
}
