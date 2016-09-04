#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <iostream>
#include <queue>
#include <map>
#include <vector>
using namespace std;
#define LL __int64
const int maxn=4e5+10;
const int INF=1e8;
int ha[9]={1,1,2,6,24,120,720,5040,40320};
int dir[4][2]={{1,0},{0,-1},{0,1},{-1,0}};
char d[10]={"dlru"};
LL dd[2][4]={{0,1,2,3},{3,2,1,0}};
int vis[2][maxn],t,Min_ans;
char ans[maxn],get[maxn];
LL c[2][maxn];
LL mm[30];  
struct node{
    int f[3][3];
    int x,y;
    int g;
    int flag;
    LL path;
    int hash_num;
};
int get_hash(node e)
{
    int a[9],i,j,ii,jj,k=0,ans=0;
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
            a[k++]=e.f[i][j];
    }
    for(i=0;i<9;i++)
    {
        k=0;
        for(j=0;j<i;j++)
            if(a[j]>a[i])k++;
        ans+=ha[i]*k;
    }
    return ans;
}
string get_str(LL c,int flag,int kk)
{
    int str[100];
    int i,j,k=0;
    for(i=0;i<vis[flag][kk];i++)
    {
        str[k++]=c%4;
        c=c/4;
    }
    string s="";
    for(i=k-1;i>=0;i--)
    s+=d[str[i]];
    return s;
}
void bfs(node e,node ee)
{
    memset(vis,-1,sizeof(vis));
    int i,j,k,xx,yy,dis[2];
    dis[0]=dis[1]=0;
    node a,b;
    e.hash_num=get_hash(e);
    e.g=0,e.flag=0;
    e.path=0;
    ee.hash_num=get_hash(ee);
    ee.g=0,ee.flag=1;
    ee.path=0;
    vis[0][e.hash_num]=0;
    vis[1][ee.hash_num]=0;
    if(e.hash_num==ee.hash_num){printf("0\n\n");return;}
    queue<node>q;
    q.push(e);
    q.push(ee);
    Min_ans=INF;
    LL str;
    string res;
    while(!q.empty())
    {
        e=q.front();
        q.pop();
        for(i=0;i<4;i++)
        {
            a=e;
            a.x=e.x+dir[i][0];
            a.y=e.y+dir[i][1];
            if(a.x<0||a.y<0||a.x>=3||a.y>=3)continue;
            swap(a.f[e.x][e.y],a.f[a.x][a.y]);
            k=get_hash(a);
            if(vis[e.flag][k]!=-1)
            {
                if(e.g+1>vis[e.flag][k])continue;
                else
                {
                    if(e.flag)str=dd[e.flag][i]*mm[e.g]+e.path;
                    else str=e.path*4+dd[e.flag][i];
                    if(c[e.flag][k]>str)
                        c[e.flag][k]=str;
                }
            }
            else
            {
                vis[e.flag][k]=e.g+1;
                if(e.flag)c[e.flag][k]=dd[e.flag][i]*mm[e.g]+e.path;
                else c[e.flag][k]=e.path*4+dd[e.flag][i];
            }
            a.hash_num=k;
            a.g++;
            a.path=c[e.flag][k];
            if(vis[e.flag^1][k]!=-1)
            {
                string s=get_str(c[0][k],0,k)+get_str(c[1][k],1,k);
                t=s.length();
                if(t>Min_ans)
                {
                    cout<<Min_ans<<endl;
                    cout<<res<<endl;
                    return;
                }
                if(t<Min_ans)
                {
                    Min_ans=t;
                    res=s;
                }
                else
                {
                    if(res.compare(s)>0)res=s;
                }
            }
            q.push(a);
        }
    }
}
void init()
{
    int i,j,k;
    mm[0]=1;
    for(i=1;i<=30;i++)
        mm[i]=mm[i-1]*4;
}
int main()
{
    init();
    char a[30],b[30];
    int T,tt=0;
    scanf("%d",&T);
    while(T--)
    {
        int i,j,k,n;
        node e,pp;
        scanf("%s",a);
        scanf("%s",b);
        n=strlen(a);
        for(i=0;i<n;i++)
        {
            if(a[i]=='X'){e.f[i/3][i%3]=0;e.x=i/3;e.y=i%3;}
            else e.f[i/3][i%3]=a[i]-'0';
            if(b[i]=='X'){pp.f[i/3][i%3]=0;pp.x=i/3;pp.y=i%3;}
            else pp.f[i/3][i%3]=b[i]-'0';
        }
        printf("Case %d: ",++tt);
        bfs(e,pp);
    }
    return 0;
}
