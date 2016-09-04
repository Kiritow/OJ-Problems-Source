#include <iostream>  
#include <cstring>  
#include <string>  
#include <algorithm>  
#include <vector>
#include <cstdio>
using namespace std;  
#define maxn MAXN
const int MAXN = 508;  
int G[MAXN][MAXN];
int mx[maxn],my[maxn];
int used[MAXN];
int ansX[maxn],ansY[maxn];
int delX,delY;
struct per
{
    int dislike[maxn];
    int like;
    int dp;
};
per person[maxn];
int X[maxn],Y[maxn];
int nx,ny;
int shuchu[maxn];
int shuchu2[maxn];
#define clr(x) memset(x,0,sizeof(int)*MAXN)
#define _clr(x) memset(x,0xff,sizeof(int)*MAXN)
int hungray(int m,int n,int mat[][maxn],int *match1,int *match2)
{
    int s[maxn],t[maxn],p,q,ret=0,i,j,k;
    for(_clr(match1),_clr(match2),i=0;i<m;ret+=(match1[i++]>=0))
        for(_clr(t),s[p=q=0]=i;p<=q&&match1[i]<0;p++)
            for(k=s[p],j=0;j<n&&match1[i]<0;j++)
                if(mat[k][j]&&t[j]<0)
                {
                    s[++q]=match2[j],t[j]=k;
                    if(s[q]<0)
                        for(p=j;p>=0;j=p)
                            match2[j]=k=t[j],p=match1[k],match1[k]=j;
                }
    return ret;
}
bool Find(int v)
{ 
    for(int u=0;u<ny;u++)
    {
        if(!used[u]&&G[v][u])
        { 
            used[u]=1;
                if(my[u]==-1||Find(my[u]))
                {
                    mx[v]=u;my[u]=v; return 1;
                }
        }
    }
    return 0;
}
bool FindY(int v)
{ 
    for(int u=0;u<ny;u++)
    {
        if(u!=delY&&!used[u]&&G[v][u])
        {
            used[u]=1;
                if(my[u]==-1||FindY(my[u]))
                {
                    return 1;
                } 
        }
    }
    return 0;
}
bool FindX(int u)
{
    for(int v=0;v<nx;v++)
    { if(v!=delX&&!used[v]&&G[v][u])
        {
            used[v]=1;
                if(mx[v]==-1||FindX(mx[v]))
                    return 1;
        }
    }
    return 0;
}
int MMG()
{
    for(int i=0;i<nx;i++)mx[i]=-1;
        for(int j=0;j<ny;j++)my[j]=-1;
            int sum=0;
                for(int i=0;i<nx;i++)
                {
                    clr(used);
                        if(Find(i))
                            sum++;
                }
    return sum;
} 
void Work()
{
        printf("%d\n",nx+ny-MMG());
        clr(ansX);
        clr(ansY);
        for(int i=0;i<nx;i++)
        { if(mx[i]==-1)
            {
                ansX[i]=1;
            }
            else
            {
                delY=mx[i];
                    clr(used);
                    if(FindY(i))ansY[delY]=1;
            }
        }
    for(int j=0;j<ny;j++)
    {
        if(my[j]==-1)
            ansY[j]=1;
        else
        {
            delX=my[j];
                clr(used);
                if(FindX(j))ansX[delX]=1;
        } 
    } 
} 
int main()  
{ 
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int a,b,p;
        scanf("%d%d%d",&a,&b,&p);
        memset(G,0,sizeof(G));
        memset(person,0,sizeof(person));
        clr(shuchu2);
        clr(shuchu);
        int like,num;
        nx=0,ny=0;
        for(int i=0;i<p;i++)
        {
            scanf("%d",&like);
            if(like>a)
            {
                X[nx++]=i;
            }
            else 
            {
                Y[ny++]=i;
            }
            person[i].like=like;
            scanf("%d",&person[i].dp);
            for(int j=0;j<person[i].dp;j++)
                scanf("%d",&person[i].dislike[j]);
        }
        for(int i=0;i<nx;i++)
        {
            for(int j=0;j<ny;j++)
            {
                for(int t=0;t<person[Y[j]].dp;t++)
                {
                    if(person[X[i]].like==person[Y[j]].dislike[t])
                    {
                        G[i][j]=1;break;
                    }
                }
                if(G[i][j]==0)
                for(int t=0;t<person[X[i]].dp;t++)
                {
                    if(person[Y[j]].like==person[X[i]].dislike[t])
                    {
                        G[i][j]=1;break;
                    }
                }
            }
        }
        Work();
        int ipsc=0;
        for(int t=0;t<nx;t++)
        {
            if(ansX[t]==1)
            {
                shuchu[ipsc++]=person[X[t]].like;
            }
        }
        for(int t=0;t<ny;t++)
        {
            if(ansY[t]==1)
            {
                shuchu[ipsc++]=person[Y[t]].like;
            }
        }
        sort(shuchu,shuchu+ipsc);
        int ipsc2=0;
        if(ipsc>0)
        {
            shuchu2[ipsc2++]=shuchu[0];
        }
        for(int t=1;t<ipsc;t++)
        {
            if(shuchu[t]!=shuchu[t-1])
            {
                shuchu2[ipsc2++]=shuchu[t];
            }
        }
        printf("%d",ipsc2);
        for(int t=0;t<ipsc2;t++)
        {
                printf(" %d",shuchu2[t]);
        }
        printf("\n");
    }
    return 0;  
}
