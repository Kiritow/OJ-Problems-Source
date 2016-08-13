#include<stdio.h>
#include<string.h>
struct node
{
    char id[100];
    char qd[100];
    char ql[100];
};
struct node s[1000];
int main()
{
    int n,i,j,k,m,x1,x2;
    char c[100];
    while(scanf("%d",&n)!=EOF&&n)
    {    
        while(n--)
        {    x1=0;x2=0;
            scanf("%d",&m);
            getchar();
                for(i=0;i<m;i++)
                {
                    scanf("%s%s%s",s[i].id,s[i].qd,s[i].ql);
                }
                if(m==1)
                {
                    printf("%s %s\n",s[0].id,s[0].id);
                }
                if(m>1)
                {    strcpy(c,s[0].qd);
                    for(i=1;i<m;i++)
                    {
                        if(strcmp(c,s[i].qd)>0)
                        {
                            strcpy(c,s[i].qd);x1=i;
                        }
                    }
                    strcpy(c,s[0].ql);
                    for(i=1;i<m;i++)
                    {
                        if(strcmp(c,s[i].ql)<0)
                        {
                            strcpy(c,s[i].ql);x2=i;
                        }
                    }
                    printf("%s %s\n",s[x1].id,s[x2].id);
                }
            }
    }
    return 0;
}
