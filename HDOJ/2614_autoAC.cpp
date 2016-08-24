#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
int flag[16];
int map[16][16],sum,n;
int max(int a,int b)
{
    return a>b?a:b;
}
void dfs(int th,int num,int time)
{
    for(int i=0;i<n;i++)
    {
        if(flag[i] || map[th][i]<time) continue;
        flag[i]=1;
        dfs(i,num+1,map[th][i]);
        flag[i]=0;
    }
    sum=max(sum,num);
}
int main()
{
    while(scanf("%d",&n)!=EOF)
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                scanf("%d",&map[i][j]);
            }
        }
        memset(flag,0,sizeof(flag));
        sum=0;
        flag[0]=1;
        dfs(0,1,0);
        printf("%d\n",sum);
    }
return 0;
}
