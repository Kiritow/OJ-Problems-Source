#include<stdio.h>
#include<set>
#include<string>
#include<cstring>
using namespace std;
char strb[1010][100];
struct In
{
    char name[100];
    int flag;
}stra[1010];
char strc[1010][100];
int main()
{
    int a,b,c;
    int i,j,k;
    int mark;
    while(scanf("%d%d%d",&a,&b,&c)!=EOF)
    {
        mark=0;
        memset(stra,0,sizeof(stra));
        for(i=0;i<a;i++)
        {
            scanf("%s",stra[i].name);
        }
        for(i=0;i<b;i++)
        {
            scanf("%s",strb[i]);
            for(j=0;j<a;j++)
            {
                if(strcmp(stra[j].name,strb[i])==0)
                {
                    stra[j].flag=1;
                    break;
                }
            }
        }
        for(i=0;i<c;i++)
        {
            scanf("%s",strc[i]);
            for(j=0;j<a;j++)
            {
                if(strcmp(stra[j].name,strc[i])==0)
                {
                    stra[j].flag=0;
                    break;
                }
            }
        }
        int count=0;
        for(i=0;i<a;i++)
        {
            if(stra[i].flag==1)
            {
                if(count)
                    printf(" ");
                count++;
                printf("%s",stra[i].name);
            }
        }
        if(count==0)
            printf("No enemy spy");
        printf("\n");
    }
    return 0;
}
