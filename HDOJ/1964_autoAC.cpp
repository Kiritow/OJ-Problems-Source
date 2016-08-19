#include<stdio.h>
#include<iostream>
#include<string.h>
#include<algorithm>
using namespace std;
const int MAXD=15;
const int HASH=10007;
const int STATE=1000010;
struct Node
{
    int down,right;
}node[MAXD][MAXD];
int N,M;
int maze[MAXD][MAXD];
int code[MAXD];
int ch[MAXD];
int ex,ey;
struct HASHMAP
{
    int head[HASH],next[STATE],size;
    int dp[STATE];
    long long state[STATE];
    void init()
    {
        size=0;
        memset(head,-1,sizeof(head));
    }
    void push(long long st,int ans)
    {
        int i,h=st%HASH;
        for(i=head[h];i!=-1;i=next[i])
           if(state[i]==st)
           {
               if(dp[i]>ans)dp[i]=ans;
               return;
           }
        dp[size]=ans;
        state[size]=st;
        next[size]=head[h];
        head[h]=size++;
    }
}hm[2];
void decode(int *code,int m,long long st)
{
    for(int i=m;i>=0;i--)
    {
        code[i]=st&7;
        st>>=3;
    }
}
long long encode(int *code,int m)
{
    int cnt=1;
    memset(ch,-1,sizeof(ch));
    ch[0]=0;
    long long st=0;
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
        if(left&&up)
        {
            if(left==up)
            {
                if(i==ex&&j==ey)
                {
                    code[j-1]=code[j]=0;
                    if(j==M)shift(code,M);
                    hm[cur^1].push(encode(code,M),hm[cur].dp[k]);
                }
            }
            else
            {
                code[j-1]=code[j]=0;
                for(int t=0;t<=M;t++)
                    if(code[t]==left)
                         code[t]=up;
                if(j==M)shift(code,M);
                hm[cur^1].push(encode(code,M),hm[cur].dp[k]);
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
                hm[cur^1].push(encode(code,M),hm[cur].dp[k]+node[i][j].right);
            }
            if(maze[i+1][j])
            {
                code[j-1]=t;
                code[j]=0;
                if(j==M)shift(code,M);
                hm[cur^1].push(encode(code,M),hm[cur].dp[k]+node[i][j].down);
            }
        }
        else
        {
            if(maze[i][j+1]&&maze[i+1][j])
            {
                code[j-1]=code[j]=13;
                hm[cur^1].push(encode(code,M),hm[cur].dp[k]+node[i][j].down+node[i][j].right);
            }
        }
    }
}
char str[30];
void init()
{
    scanf("%d%d%*c",&N,&M);
    memset(maze,0,sizeof(maze));
    for(int i=1;i<=N;i++)
      for(int j=1;j<=M;j++)
          maze[i][j]=1;
    gets(str);
    for(int i=1;i<N;i++)
    {
        gets(str);
        for(int j=1;j<M;j++)
          node[i][j].right=str[2*j]-'0';
        gets(str);
        for(int j=1;j<=M;j++)
          node[i][j].down=str[2*j-1]-'0';
    }
    gets(str);
    for(int j=1;j<M;j++)
        node[N][j].right=str[2*j]-'0';
    gets(str);
    ex=N;
    ey=M;
}
void solve()
{
    int i,j,cur=0;
    int ans=0;
    hm[cur].init();
    hm[cur].push(0,0);
    for(i=1;i<=N;i++)
      for(j=1;j<=M;j++)
      {
          hm[cur^1].init();
          dpblank(i,j,cur);
          cur^=1;
      }
    for(i=0;i<hm[cur].size;i++)
        ans+=hm[cur].dp[i];
    printf("%d\n",ans);
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        init();
        solve();
    }
    return 0;
}
