#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct node
{
    int jb[10];
    int num;
}ui[1005];
int main()
{
    int M,N,n;
    int i;
    int u,b,a[100010];
    char ch;
    while(scanf("%d%d",&M,&N)!=EOF)
    {
        memset(a,-1,sizeof(a));
        memset(ui,0,sizeof(ui));
        scanf("%d",&n);    
        while(n--)
        {
            getchar();
            scanf("%c",&ch);        
            if(ch=='B')
            {
                scanf("%d %d",&u,&b);
                if(a[b]!=-1)
                {
                    printf("The book is not in the library now\n");
                }
                else
                {
                    if(ui[u].num==9)
                    {
                        printf("You are not allowed to borrow any more\n");
                    }
                    else
                    {
                        printf("Borrow success\n");
                        ui[u].jb[ui[u].num]=b;
                        ui[u].num++;
                        a[b]=u;
                    }
                }
            }
            else if(ch=='R')
            {
                int j;
                scanf("%d",&b);
                if(a[b]==-1)
                {
                    printf("The book is already in the library\n");
                }
                else
                {
                    int temp;
                    int num;
                    num=ui[a[b]].num;
                    for(j=0;j<num;j++)
                    {
                        if(ui[a[b]].jb[j]==b)
                        {
                            temp=j;
                        }
                    }
                    for(j=temp;j<num;j++)
                    {
                        ui[a[b]].jb[j]=ui[a[b]].jb[j+1];
                    }
                    ui[a[b]].num--;
                    a[b]=-1;
                    printf("Return success\n");
                }
            }
            else if(ch=='Q')
            {
                scanf("%d",&u);
                if(ui[u].num == 0)
                {
                    printf("Empty\n");
                } 
                else 
                {
                    int num=ui[u].num;
                    for(int i=0;i<num;++i)
                    {
                        for(int j=num-1;j>i;--j)
                        {
                            if(ui[u].jb[i] > ui[u].jb[j])
                            {
                                int t = ui[u].jb[i];
                                ui[u].jb[i]=ui[u].jb[j];
                                ui[u].jb[j] = t; 
                            }
                        }
                    }
                    for(i=0;i<num;i++)
                    {
                        if( i!=0)
                            printf(" ");
                        printf("%d",ui[u].jb[i]);
                    }
                    printf("\n");
                }
            }
        }    
        printf("\n");
    }
    return 0;
}
