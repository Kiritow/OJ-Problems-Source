#include<stdio.h>
#include<string.h>
int main()
{
    int a,b,j,m;
    char c[210],d[210];
    while(fgets(c,210,stdin))
    {
        int e[210]={0};
        m=0;
        a=strlen(c);
        for(j=0;j<a-1;j++)
            if(c[j]!=' ')
                d[m++]=c[j];
            d[m]='\0';
            b=strlen(d);
            for(j=2;j<b;)
            {
                printf("%c",d[j]);
                e[j]=1;
                j=j+3;
            }
            for(j=1;j<b;j=j+2)
            {
                if(e[j]==1)
                    continue;
                else
                {
                    printf("%c",d[j]);
                    e[j]=1;
                }
            }
            for(j=0;j<b;j++)
                if(e[j]!=1)
                    printf("%c",d[j]);
                printf("\n");
    }
return 0;
}
