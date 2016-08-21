#include<stdio.h>
#include<string.h>
int dp[105][729],pow[10],stac1[10],stac2[10];
int n,m,ans;
int max(int a,int b)
{
    return a>b?a:b;
}
void work()
{
    pow[0]=1;
    for(int i=1;i<10;i++)
    pow[i]=3*pow[i-1];
}
int ctod(int three[10]){
    int state=0;
    for(int i=0;i<m;i++)
        state+=three[i]*pow[i];
    return state;
}
void dtoc(int state,int three[10]){
    for(int i=0;i<m;i++,state/=3)
        three[i]=state%3;
}
void init()
{
    memset(dp,-1,sizeof(dp));
    for(int i=0;i<m;i++)
     {
         stac1[i]=1;
         stac2[i]=0;
     }
     dp[0][ctod(stac1)]=0;
}
void dfs(int i,int idx,int num){
    if(idx>=m){
        int j=ctod(stac1);
      dp[i][j]=max(dp[i][j],num);
        return ;
    }
    if(idx+1<m&&stac1[idx]==0&&stac1[idx+1]==0&&stac2[idx+1]==0){
        stac1[idx+1]=2;stac1[idx]=1;
        dfs(i,idx+2,num+4);
        stac1[idx+1]=stac1[idx]=0;
    }
    if(idx+2<m&&stac1[idx]==0&&stac1[idx+1]==0&&stac1[idx+2]==0&&stac2[idx+1]==0){
        stac1[idx]=stac1[idx+2]=1;stac1[idx+1]=2;
        dfs(i,idx+2,num+5);
        stac1[idx]=stac1[idx+2]=stac1[idx+1]=0;
    }
    if(idx+2<m&&stac1[idx]==0&&stac1[idx+1]==0&&stac1[idx+2]==0){
        stac1[idx]=stac1[idx+2]=1;stac1[idx+1]=2;
        dfs(i,idx+2,num+4);
        stac1[idx]=stac1[idx+2]=stac1[idx+1]=0;
    }
    if(idx+2<m&&stac1[idx]==0&&stac1[idx+1]==0&&stac1[idx+2]==0){
        stac1[idx]=stac1[idx+1]=1;stac1[idx+2]=2;
        dfs(i,idx+2,num+4);
        stac1[idx]=stac1[idx+2]=stac1[idx+1]=0;
    }
    if(idx+1<m&&stac1[idx+1]==0&&stac2[idx]==0&&stac2[idx+1]==0){
        stac1[idx+1]=2;
        dfs(i,idx+2,num+4);
        stac1[idx+1]=0;
    }
    dfs(i,idx+1,num);
}
int main()
{
    int i,t,k,j;
    work();
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        if(m>n)
        {
            t=m;
            m=n;
            n=t;
        }
        init();
        ans=0;
        for(i=1;i<=n-1;i++)
          for(j=0;j<pow[m];j++)
              if(dp[i-1][j]!=-1)
            {
                dtoc(j,stac2);
                for(k=0;k<m;k++)
                stac1[k]=max(0,stac2[k]-1);
                dfs(i,0,dp[i-1][j]);
            }
            ans=0;
            for(i=0;i<pow[m];i++)
            ans=max(ans,dp[n-1][i]);
          printf("%d\n",ans);
    }
    return 0;
}
