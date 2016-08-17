#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;
typedef struct
{
    int timecheck[8][12];
    char name[30];
}student;
typedef struct
{
    char Lname[30];
}Lstudent;
student book[201];
Lstudent buf[201];
bool c(Lstudent a,Lstudent b)
{
    return (strcmp(a.Lname,b.Lname)<0);
}
int main()
{
    int n,i,b,t,k,l,x,b1,e1,count;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        memset(book, 0, sizeof(book));
        memset(buf, 0, sizeof(buf));
        scanf("%d",&t);
        for(b=0;b<t;b++)
        {
            scanf("%s",book[b].name);
            scanf("%d",&k);
            for(l=0;l<k;l++)
            {
                scanf("%d%d%d",&x,&b1,&e1);
                for(int o=b1;o<=e1;o++)
                {
                    book[b].timecheck[x][o]=1;
                }
            }
        }
        scanf("%d",&k);
        for(l=0;l<k;l++)
        {
            int first=1;
            count=0;
            scanf("%d%d%d",&x,&b1,&e1);
            for(b=0;b<t;b++)
            {
                for(int o=b1;o<=e1;o++)
                {
                    if(book[b].timecheck[x][o]==1)
                    {
                        strcpy(buf[count].Lname,book[b].name);
                        count++;
                        break;
                    }
                }
            }
            if(count==0)
            {
                printf("None\n");
            }
            else
            {
                sort(buf,buf+count,c);
                for(int y=0;y<count;y++)
                {
                    if(first)
                        first=0;
                    else
                        printf(" ");
                    printf("%s",buf[y].Lname);
                }
                printf("\n");
            }
        }
    }
}
