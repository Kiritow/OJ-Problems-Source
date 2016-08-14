#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cassert>
#include <iostream>
#include <sstream>
#include <fstream>
#include <map>
#include <set>
#include <vector>
#include <queue>
#include <algorithm>
#include <iomanip>
#define inf 0x3f3f3f3f
#define maxn 1005
using namespace std;
struct node
{
    int mm,dd,hh,MM;
} ttt[maxn];
char str[1005];
int f[maxn][maxn],t[maxn],n;
bool flag[maxn];
int cmp(node t1,node t2) //t1<t2 -1;  t1==t2 0; t1>t2 1;
{
    if(t1.mm!=t2.mm)
    {
        if(t1.mm<t2.mm) return -1;
        else return 1;
    }
    if(t1.dd!=t2.dd)
    {
        if(t1.dd<t2.dd) return -1;
        else return 1;
    }
    if(t1.hh!=t2.hh)
    {
        if(t1.hh<t2.hh) return -1;
        else return 1;
    }
    if(t1.MM!=t2.MM)
    {
        if(t1.MM<t2.MM) return -1;
        else return 1;
    }
    return 0;
}
int main()
{
    char op;
    while(scanf("%d",&n)!=EOF&&n!=0)
    {
        memset(flag,0,sizeof(flag));
        for(int i=n; i>=1; i--)
        {
            scanf("%d:%d:%d:%d %s %c",&ttt[i].mm,&ttt[i].dd,&ttt[i].hh,&ttt[i].MM,str,&op);
            if(op=='+') flag[i]=1;
        }
        t[1]=0;
        for(int i=2; i<=n; i++)
        {
            t[i]=t[i-1];
            if(cmp(ttt[i],ttt[i-1])>=0 ) t[i]++;
        }
        f[1][1]=1;
        if(flag[1]) f[1][0]=inf;
        else f[1][0]=0;
        for(int i=2; i<=n; i++) f[1][i]=inf;
        for(int i=2; i<=n; i++)
        {
            for(int j=1; j<=n; j++) f[i][j]=inf;
            if(!flag[i]) f[i][0]=f[i-1][0];
            else f[i][0]=inf;
            if(flag[i])
            {
                if(t[i]==0) f[i][i]=min(f[i][i],f[i-1][0]+1);
                for(int j=1; j<i; j++)
                if(f[i-1][j]<inf)
                {
                    int tt;
                    tt=t[i];
                    if(cmp(ttt[i],ttt[j])>=0) tt--;
                    if(tt==t[j]) //zhengque queding nianfen
                    {
                        f[i][i]=min(f[i-1][j]+1,f[i][i]);
                    }
                }
            }
            else
            {
                for(int j=1; j<=n; j++) f[i][j]=min(f[i][j],f[i-1][j]);
                if(t[i]==0) f[i][i]=min(f[i][i],f[i-1][0]+1);
                for(int j=1; j<i; j++)
                if(f[i-1][j]<inf)
                {
                    int tt;
                    tt=t[i];
                    if(cmp(ttt[i],ttt[j])>=0) tt--;
                    if(tt==t[j]) //zhengque queding nianfen
                    {
                        f[i][i]=min(f[i-1][j]+1,f[i][i]);
                    }
                }
            }
        }
        int res;
        res=inf;
        for(int i=1; i<=n; i++)
            res=min(res,f[n][i]);
        res=min(res,n);
        printf("%d\n",res);
    }
    return 0;
}
