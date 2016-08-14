#include<stdio.h>
#include<cstring>
typedef struct to
{
    int num;
    int go[1005];
}E;
E e[1005];
int sg[1005];
int getsg(int n)  
{
    int visit[1005];
    int i,j;
    memset(visit,0,sizeof(visit));
    if(e[n].num==0){sg[n]=0;return sg[n];}
    if(sg[n]!=-1)return sg[n];
    for(i=0;i<e[n].num;i++)
    {
        visit[getsg(e[n].go[i])]=1;
    }
    for(i=0;i<=1000;i++)
    {
        if(!visit[i])
        {
            return i;
        }
    }
    return -1;
}
int main()
{
    int n,m,i,j,ans;
    while(scanf("%d",&n)!=EOF)
    {
        memset(e,0,sizeof(e));
        memset(sg,-1,sizeof(sg));
        for(i=0;i<n;i++)
        {
            scanf("%d",&e[i].num);
            for(j=0;j<e[i].num;j++)scanf("%d",&e[i].go[j]);
        }
        for(i=0;i<n;i++)sg[i]=getsg(i);
        while(scanf("%d",&m)&&m)
        {
            ans=0;
            while(m--)
            {
                scanf("%d",&i);
                ans^=sg[i];
            }
            if(ans)printf("WIN\n");
            else printf("LOSE\n");
        }
    }
    return 0;
}
