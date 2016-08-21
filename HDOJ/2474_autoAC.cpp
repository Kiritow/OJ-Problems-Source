#include<stdio.h>
#include<stdlib.h>
#include<memory.h>
struct node 
{
    int need;
    int id;
};
struct node que[4][51000];
int hash[51000],head[4],own[4];
int now[4][51000];
void chu()
{
    memset(hash,0,sizeof(hash));
}
int cmp(const void *a,const void *b)
{
    return (*(struct node*)a).need-(*(struct node*)b).need;
}
int main()
{
    int flag,sum,n,m,i,f;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        chu();
        for(f=1;f<=m;f++)
        {
            head[f]=1;
            for(i=1;i<=n;i++)
            {
                que[f][i].id=i;
                scanf("%d",&now[f][i]);
            }
        }
        for(f=1;f<=m;f++)
        {
            for(i=1;i<=n;i++)
            {
                scanf("%d",&que[f][i].need);
            }
        }
        for(i=1;i<=m;i++)
        {
            scanf("%d",&own[i]);
            qsort(&que[i][1],n,sizeof(que[0][0]),cmp);
        }
        sum=0;
        flag=1;
        while(1 == flag)
        {
            flag=0;
            for(i=1;i<=m;i++)
            {
                for(;head[i]<=n;head[i]++)
                {
                    if(own[i] < que[i][head[i]].need)
                    {
                        break;
                    }
                    flag=1;
                    hash[que[i][head[i]].id]++;
                    if(m == hash[que[i][head[i]].id])
                    {
                        sum++;
                        for(f=1;f<=m;f++)
                        {
                            own[f]+=now[f][que[i][head[i]].id];
                        }
                    }
                }    
            }
        }
        if(n == sum)
        {
            printf("Yes\n");
        }
        else
        {
            printf("No\n");
        }
    }
    return 0;
}
