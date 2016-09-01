#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<string.h>
using namespace std;
const int MAXD=15;
const int HASH=10007;
const int STATE=1000010;
int N,M;
int maze[MAXD][MAXD];
int score[MAXD][MAXD];
int code[MAXD];
int ch[MAXD];
struct HASHMAP
{
    int head[HASH],state[STATE],next[STATE],size;
    int dp[STATE];
    void init()
    {
        size=0;
        memset(head,-1,sizeof(head));
    }
    void push(int st,int ans)
    {
        int i,h=st%HASH;
        for(i=head[h];i!=-1;i=next[i])
           if(state[i]==st)
           {
               if(dp[i]<ans)dp[i]=ans;
               return;
           }
        state[size]=st;
        dp[size]=ans;
        next[size]=head[h];
        head[h]=size++;
    }
}hm[2];
void decode(int *code,int m,int st)
{
    for(int i=m;i>=0;i--)
    {
        code[i]=st&7;
        st>>=3;
    }
}
int encode(int *code,int m)
{
    int cnt=1;
    memset(ch,-1,sizeof(ch));
    ch[0]=0;
    int st=0;
    for(int i=0;i<=m;i++)
    {
        if(ch[code[i]]==-1)ch[code[i]]=cnt++;
        code[i]=ch[code[i]];
        st<<=3;
        st|=code[i];
    }
    return st;
}
void shift(int *code,int m)
{
    for(int i=m;i>0;i--)code[i]=code[i-1];
    code[0]=0;
}
void dpblank(int i,int j,int cur)
{
    int k,left,up;
    for(k=0;k<hm[cur].size;k++)
    {
        decode(code,M,hm[cur].state[k]);
        left=code[j-1];
        up=code[j];
        if((i==1&&j==1)||(i==N&&j==M))
        {
            if((left&&(!up))||((!left)&&up))
            {
                code[j-1]=code[j]=0;
                if(j==M)shift(code,M);
                hm[cur^1].push(encode(code,M),hm[cur].dp[k]+score[i][j]);
            }
            else if(left==0&&up==0)
            {
                if(maze[i][j+1])
                {
                    code[j-1]=0;
                    code[j]=13;
                    hm[cur^1].push(encode(code,M),hm[cur].dp[k]+score[i][j]);
                }
                if(maze[i][j+1])
                {
                    code[j-1]=13;
                    code[j]=0;
                    if(j==M)shift(code,M);
                    hm[cur^1].push(encode(code,M),hm[cur].dp[k]+score[i][j]);
                }
            }
            continue;
        }
        if(left&&up)
        {
            if(left==up)
            {
            }
            else
            {
                code[j-1]=code[j]=0;
                for(int t=0;t<=M;t++)
                  if(code[t]==up)
                    code[t]=left;
                if(j==M)shift(code,M);
                hm[cur^1].push(encode(code,M),hm[cur].dp[k]+score[i][j]);
            }
        }
        else if((left&&(!up))||((!left)&&up))
        {
            int t;
            if(left)t=left;
            else t=up;
            if(maze[i][j+1])
            {
                code[j-1]=0;
                code[j]=t;
                hm[cur^1].push(encode(code,M),hm[cur].dp[k]+score[i][j]);
            }
            if(maze[i+1][j])
            {
                code[j]=0;
                code[j-1]=t;
                if(j==M)shift(code,M);
                hm[cur^1].push(encode(code,M),hm[cur].dp[k]+score[i][j]);
            }
        }
        else
        {
            if(maze[i][j+1]&&maze[i+1][j])
            {
                code[j]=code[j-1]=13;
                hm[cur^1].push(encode(code,M),hm[cur].dp[k]+score[i][j]);
            }
            code[j-1]=code[j]=0;
            if(j==M)shift(code,M);
            hm[cur^1].push(encode(code,M),hm[cur].dp[k]);
        }
    }
}
void init()
{
    memset(maze,0,sizeof(maze));
    for(int i=1;i<=N;i++)
      for(int j=1;j<=M;j++)
      {
          maze[i][j]=1;
          scanf("%d",&score[i][j]);
      }
}
void solve()
{
    int i,j,cur=0;
    hm[cur].init();
    hm[cur].push(0,0);
    for(int i=1;i<=N;i++)
      for(int j=1;j<=M;j++)
      {
          hm[cur^1].init();
          dpblank(i,j,cur);
          cur^=1;
      }
    int ans=0;
    for(int i=0;i<hm[cur].size;i++)
       ans+=hm[cur].dp[i];
    printf("%d\n",ans);
}
int main()
{
    int iCase=0;
    while(scanf("%d%d",&N,&M)!=EOF)
    {
        iCase++;
        printf("Case %d: ",iCase);
        init();
        if(N==1&&M==1)
        {
            printf("%d\n",score[1][1]);
            continue;
        }
        solve();
    }
    return 0;
}
