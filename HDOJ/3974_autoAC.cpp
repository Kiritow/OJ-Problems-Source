#include <stdio.h>
#include <iostream>
using namespace std;
const int MAX = 50010;
struct NODE
{
    int task,count;
};
NODE p[MAX];
int parent[MAX];
void init()
{
    memset(parent,-1,sizeof(parent));
}
int main()
{
    int ncases,n,u,v,m,x,task;
    char s[5];    
    scanf("%d",&ncases);    
    int ind=1;
    while(ncases--)
    {
        scanf("%d",&n);
        init();
        int i;
        for(i=0;i<n-1;i++)
        {
            scanf("%d%d",&u,&v);
            parent[u]=v;
        }
        for(i=1;i<=n;i++)
        {
            p[i].task=-1;
            p[i].count=-1;
        }        
        scanf("%d",&m);        
        printf("Case #%d:\n",ind++);
        int count=0;
        while(m--)
        {
            scanf("%s",s);
            if(s[0]=='T')
            {
                scanf("%d%d",&x,&task);
                p[x].task=task;
                p[x].count=++count;
            }
            else
            {
                scanf("%d",&x);
                task=p[x].task;
                int count=p[x].count;
                while(x!=-1)
                {
                    if(p[x].count>count)
                    {
                        task=p[x].task;
                        count=p[x].count;
                    }
                    x=parent[x];
                }
                printf("%d\n",task);
            }
        }
    }
return 0;
}
