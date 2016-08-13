#include <cmath>
#include <cstdio>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#define debug 0
#define sca scanf
#define pri printf
#define LL long long
#define fou(i,a,b) for(i = a; i < b; i ++)
#define fod(i,a,b) for(i = a; i >= b; i --)
#define clean(a) memset(a,0,sizeof(a))
using namespace std;
int Compare(int a,int b,bool flag)
{if(flag)return a>b?a:b; else return a<b?a:b;}
int ABS(int a,int b)
{return (a)>(b)?(a-b):(b-a);}
int Map[30][30];
int channel[30];
int mark[30][30];
int n,ans,key,res;
void dfs(int x)
{
    if(debug)pri("%d\n",x);
    int i,j,u,v;
    if(key)
    {
        return ;
    }
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            if(Map[x][j]&&mark[j][i])
            {
                break;
            }
        }
        if(j==n+1)
        {
            mark[x][i]=1;
            channel[i]=1;
            if(debug)
            {
                pri("X:%d  I:%d  J:%d\n",x,i,j);
                pri("mark-----------\n");
                fou(i,1,n + 1)
                {
                    pri("%d ",mark[x][i]);
                }
                pri("\nchannel:\n");
                fou(i,1,n + 1)
                {
                    pri("%d ",channel[i]);
                }
                pri("\n");
            }
            if(x == n)
            {
                for(u=1;u<=n;u++)
                {
                    if(channel[u])
                    {
                        res++;
                    }
                }
                key=1;
                return ;
            }else
            {
                dfs(x+1);
            }
            mark[x][i]=0;
            channel[i]=0;
        }
    }
}
int main()
{
    int i,j,k,len;
    char tmp[100];
    while(~sca("%d",&n) && n)
    {
        clean(mark);
        clean(channel);
        clean(Map);
        fou(i,1,n + 1)
        {
            sca("%s",tmp);
            len = strlen(tmp);
            fou(j,2,len)
            {
                Map[i][tmp[j] - 'A' + 1] = 1;
                Map[tmp[j] - 'A' + 1][i] = 1;
            }
        }
        res = 0; key = 0;
        dfs(1);
        if(res ==1 )
            pri("%d channel needed.\n",res);
        else
            pri("%d channels needed.\n",res);
        if(debug)
        {
            fou(i,1,n + 1)
                pri("%d ",channel[i]);
            pri("\n");
            fou(i,1,n + 1)
                pri("%d ",mark[i]);
            pri("\n");
            fou(i,1,n + 1)
            {
                fou(j,1,n + 1)
                {
                    pri("%d ",Map[i][j]);
                }
                pri("\n");
            }
        }
    }
    return 0;
}
