#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<string.h>
using namespace std;
const int MAXD=15;
const int STATE=1000010;
const int HASH=300007;
const int MOD=1000000007;
int N,M,K;
int maze[MAXD][MAXD];
int code[MAXD];
int ch[MAXD];
int num;
struct HASHMAP
{
    int head[HASH],next[STATE],size;
    long long state[STATE];
    int f[STATE];
    void init()
    {
        size=0;
        memset(head,-1,sizeof(head));
    }
    void push(long long st,int ans)
    {
        int i;
        int h=st%HASH;
        for(i=head[h];i!=-1;i=next[i])
          if(state[i]==st)
          {
              f[i]+=ans;
              f[i]%=MOD;
              return;
          }
        state[size]=st;
        f[size]=ans;
        next[size]=head[h];
        head[h]=size++;
    }
}hm[2];
void decode(int *code,int m,long long  st)
{
    num=st&63;
    st>>=6;
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
    st<<=6;
    st|=num;
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
                if(num>=K)continue;
                int t=0;
                for(int p=0;p<j-1;p++)
                  if(code[p])t++;
                if(t&1)continue;
                if(num<K)
                {
                    num++;
                    code[j-1]=code[j]=0;
                    hm[cur^1].push(encode(code,j==M?M-1:M),hm[cur].f[k]);
                }
            }
            else
            {
                code[j-1]=code[j]=0;
                for(int t=0;t<=M;t++)
                  if(code[t]==up)
                    code[t]=left;
                hm[cur^1].push(encode(code,j==M?M-1:M),hm[cur].f[k]);
            }
        }
        else if(left||up)
        {
            int t;
            if(left)t=left;
            else t=up;
            if(maze[i][j+1])
            {
                code[j-1]=0;
                code[j]=t;
                hm[cur^1].push(encode(code,M),hm[cur].f[k]);
            }
            if(maze[i+1][j])
            {
                code[j]=0;
                code[j-1]=t;
                hm[cur^1].push(encode(code,j==M?M-1:M),hm[cur].f[k]);
            }
        }
        else
        {
            if(maze[i][j+1]&&maze[i+1][j])
            {
                code[j-1]=code[j]=13;
                hm[cur^1].push(encode(code,j==M?M-1:M),hm[cur].f[k]);
            }
        }
    }
}
void dpblock(int i,int j,int cur)
{
    int k;
    for(k=0;k<hm[cur].size;k++)
    {
        decode(code,M,hm[cur].state[k]);
        code[j-1]=code[j]=0;
        hm[cur^1].push(encode(code,j==M?M-1:M),hm[cur].f[k]);
    }
}
char str[20];
void init()
{
    scanf("%d%d%d",&N,&M,&K);
    memset(maze,0,sizeof(maze));
    for(int i=1;i<=N;i++)
    {
        scanf("%s",&str);
        for(int j=1;j<=M;j++)
          if(str[j-1]=='.')
            maze[i][j]=1;
    }
}
void solve()
{
    int i,j,cur=0;
    hm[cur].init();
    hm[cur].push(0,1);
    for(i=1;i<=N;i++)
      for(j=1;j<=M;j++)
      {
          hm[cur^1].init();
          if(maze[i][j])dpblank(i,j,cur);
          else dpblock(i,j,cur);
          cur^=1;
      }
    int ans=0;
    for(i=0;i<hm[cur].size;i++)
      if(hm[cur].state[i]==K)
      {
          ans+=hm[cur].f[i];
          ans%=MOD;
      }
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
