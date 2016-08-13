#include<stdio.h>
#include<string.h>
#define max 100+10
double map[max][max];
int curr,t=1;
void floyd()
{
    int k,i,j;
    int exist=0;
    for(k=1;k<=curr;k++)
    {
        for(i=1;i<=curr;i++)
        {
            for(j=1;j<=curr;j++)
            {
                if(map[i][j]<map[i][k]*map[k][j])
                map[i][j]=map[i][k]*map[k][j];
            }
        }
    }
    for(i=1;i<=curr;i++)
    {
        if(map[i][i]>1)
        {
            exist=1;
            break;
        }
    }
    if(exist)
    printf("Case %d: Yes\n",t++);
    else
    printf("Case %d: No\n",t++);
}
int main()
{
    int m,i,j,x,y;
    double rate;
    char a[110],b[110],s[110][110];
    while(scanf("%d",&curr)&&(curr!=0))
    {
        for(i=1;i<=curr;i++)
        {
            for(j=1;j<=curr;j++)
            {
                map[i][j]=0;
            }
        }
        for(i=1;i<=curr;i++)
        {
            scanf("%s",s[i]);
        }
        scanf("%d",&m);
        while(m--)
        {
            scanf("%s %lf %s",a,&rate,b);
            for(i=1;i<=curr;i++)
            {
                if(strcmp(s[i],a)==0)
                {
                    x=i;
                    break;
                }
            }
            for(i=1;i<=curr;i++)
            {
                if(strcmp(s[i],b)==0)
                {
                    y=i;
                    break;
                }
            }
            map[x][y]=rate;
        }
        floyd(); 
    }
    return 0;
}
