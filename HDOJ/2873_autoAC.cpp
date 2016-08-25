#include<iostream>
#include<cstdlib>
#include<stdio.h>
#include<memory.h>
using namespace std;
int sg[60][60];
char str[60][60];
int num[600];
int dfs(int x,int y)
{
    memset(num,-1,sizeof(num));
    for(int i=0;i<x;i++)
    for(int j=0;j<y;j++)
    {
        num[sg[i][y]^sg[x][j]]=1;
    }
    for(int i=0;;i++)
    if(num[i]==-1) return i;
}
int main()
{
    for(int i=0;i<=50;i++)
    sg[0][i]=sg[i][0]=i;
    for(int i=1;i<=50;i++)
    for(int j=1;j<=50;j++)
    sg[i][j]=dfs(i,j);
    int n,m;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        if(n==0&&m==0) break;
        int ans=0;
        for(int i=0;i<n;i++)
        {
            scanf("%s",str[i]);
            for(int j=0;j<m;j++)
            {
                if(str[i][j]=='#')
                {
                    ans^=sg[i][j];
                }
            }
        }
        if(ans) puts("John");
        else puts("Jack");
    }
}
