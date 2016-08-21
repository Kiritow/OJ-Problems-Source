# include<stdio.h>
# include<string.h>
# include<stdlib.h>
# define N 205
char map[N][105];
struct node{
    int from,to,next;
}edge[2*N];
int head[N],tol,visit[N],dp[N][2],dup[N][2];
void add(int a,int b)
{
    edge[tol].from=a;edge[tol].to=b;edge[tol].next=head[a];head[a]=tol++;
}
int max(int a,int b)
{
    return a>b?a:b;
}
void dfs(int root)
{
    int j,u;
    dp[root][0]=0;
    dp[root][1]=1;
    dup[root][0]=1;
    dup[root][1]=1;
    for(j=head[root];j!=-1;j=edge[j].next)
    {
        u=edge[j].to;
        dfs(u);
        dp[root][0]+=max(dp[u][0],dp[u][1]);
        dp[root][1]+=dp[u][0];
        if(dp[u][0]>dp[u][1] && dp[u][0]==0) dup[root][0]=0;
        else if(dp[u][1]>dp[u][0] && dp[u][1]==0) dup[root][0]=0;
        else if(dp[u][0]==dp[u][1]) dup[root][0]=0;
        if(dup[u][0]==0) dup[root][1]=0;
    }
}
int main()
{
    int i,j,n,k,ans1,ans2;
    char str1[105],str2[105];
    while(scanf("%d",&n)!=EOF && n)
    {
        scanf("%s",map[1]);
        k=1;
        memset(head,-1,sizeof(head));
        tol=0;
        for(i=1;i<n;i++)
        {
            scanf("%s%s",str1,str2);
            ans1=ans2=-1;
            for(j=1;j<=k;j++)
            {
                if(strcmp(str1,map[j])==0) ans1=j;
                if(strcmp(str2,map[j])==0) ans2=j;
            }
            if(ans1==-1)
            {
                k++;
                ans1=k;
                strcpy(map[k],str1);
            }
            if(ans2==-1)
            {
                k++;
                ans2=k;
                strcpy(map[k],str2);
            }
            add(ans2,ans1);
        }
        memset(dp,0,sizeof(dp));
        dfs(1);
        if(dp[1][0]>dp[1][1] && dup[1][0]==1) printf("%d Yes\n",dp[1][0]);
        else if(dp[1][1]>dp[1][0] && dup[1][1]==1) printf("%d Yes\n",dp[1][1]);
        else printf("%d No\n",max(dp[1][0],dp[1][1]));
    }
    return 0;
}
