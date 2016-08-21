#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<iostream>
#include<queue>
using namespace std;
struct node{
    int next[26];
    int fail;
    int val;
    void init()
    {
        memset(next,0,sizeof(next));
        fail=0;
        val=0;
    }
}a[1200];
int tot,len;
int dp[55][1200];
char str[55][1200][55];
void chushihua()
{
    memset(dp,-1,sizeof(dp));
    tot=0;
    a[0].init();
}
void insert(char *str,int v)
{
    int index,p=0;
    for(;*str!='\0';str++)
    {
        index=*str-'a';
        if(a[p].next[index]==0)
        {
            a[++tot].init();
            a[p].next[index]=tot;
        }
        p=a[p].next[index];
    }
    a[p].val=v;
}
void build_ac()
{
    queue<int>Q;
    int p,cur,son,i;
    Q.push(0);
    while(!Q.empty())
    {
        p=Q.front();
        Q.pop();
        for(i=0;i<26;i++)
        {
            if(a[p].next[i]!=0)
            {
                son=a[p].next[i];
                cur=a[p].fail;
                if(p==0)
                    a[son].fail=0;
                else
                {
                    while(cur&&a[cur].next[i]==0)
                        cur=a[cur].fail;
                    a[son].fail=a[cur].next[i];
                }
                if(a[a[son].fail].val)
                    a[son].val+=a[a[son].fail].val;
                Q.push(son);
            }
            else
                a[p].next[i]=a[a[p].fail].next[i];
        }
    }
}
void solve()
{
    int i,j,k,son,max=0;
    char shang[55],temp,res[55];
    dp[0][0]=0;
    strcpy(str[0][0],"\0");
    strcpy(res,"\0");
    for(i=1;i<=len;i++)
        for(j=0;j<=tot;j++)
        {
            if(dp[i-1][j]==-1)
                continue;
            strcpy(shang,str[i-1][j]);
            for(k=0;k<26;k++)
            {
                son=a[j].next[k];
                temp=k+'a';
                shang[i-1]=temp;
                shang[i]='\0';
                if(dp[i][son]==-1)
                {
                    dp[i][son]=dp[i-1][j]+a[son].val;
                    strcpy(str[i][son],shang);
                }
                else
                {
                    if(dp[i][son]<dp[i-1][j]+a[son].val)
                    {
                        dp[i][son]=dp[i-1][j]+a[son].val;
                        strcpy(str[i][son],shang);
                    }
                    else if(dp[i][son]==dp[i-1][j]+a[son].val)
                    {
                        if(strcmp(str[i][son],shang)>0)
                             strcpy(str[i][son],shang);
                    }
                }
            }
        }
        for(i=1;i<=len;i++)
            for(j=0;j<=tot;j++)
            {
                if(dp[i][j]>max)
                {
                    max=dp[i][j];
                    strcpy(res,str[i][j]);
                }
                else if(dp[i][j]==max&&strcmp(res,str[i][j])>0&&strlen(res)>=strlen(str[i][j]))
                    strcpy(res,str[i][j]);                 
            }
        printf("%s\n",res);
}
int main()
{
    char keyword[105][15];
    int n,T,val[105],i;
    while(scanf("%d",&T)!=EOF)
    {
        while(T--)
        {
            chushihua();
            scanf("%d%d",&len,&n);
            getchar();
            for(i=0;i<n;i++)
                 scanf("%s",keyword[i]);
            for(i=0;i<n;i++)
                 scanf("%d",&val[i]);
            for(i=0;i<n;i++)
                 insert(keyword[i],val[i]);
            build_ac();
            solve();
        }
    }
    return 0;
}
