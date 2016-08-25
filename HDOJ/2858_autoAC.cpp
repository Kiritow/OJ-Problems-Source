#include<iostream>
#include<queue>
#include<string.h>
#include<stdio.h>
using namespace std;
struct node
{
    int k,l,r,ans,nl,nr,level;
    node(){};
    node(int kk,int ll,int rr,int anss,int nll,int nrr,int le)
    {
        k=kk;l=ll;r=rr;ans=anss;level=le;nl=nll;nr=nrr;
    }
    friend bool operator<(const node &A,const node &B)
    {
        if(A.level==B.level)
        {
            return A.ans<B.ans;
        }
        return A.level>B.level;
    }
}s,e;
bool has[230][15][15][15][15][2];
priority_queue<node>q;
int map[20][20],b[20][20][20];
int n,m,k,ans;
int x,y,now;
void solve()
{
    if(e.k<0||e.k>(n-e.level-1)*(e.nr-e.nl+1))
        return;
    if(has[e.k][e.l][e.r][e.nl][e.nr][1-now]==true)
        return;
    q.push(e);
    has[e.k][e.l][e.r][e.nl][e.nr][1-now]=true;
}
void bfs(int l)
{
    int i,j;
    memset(has,0,sizeof(has));
    q.push(node(0,0,0,0,0,0,-1));
    while(!q.empty())
    {
        s=q.top();
        q.pop();
        if(s.k==0&&s.ans>ans)
            ans=s.ans;
        if(s.level==n-1)
            continue;
        if(s.level!=l)
        {
            now=1-now;
            l=s.level;
            for(i=0;i<m;i++)
            {
                for(j=i;j<m;j++)
                {
                    e=s;
                    e.level++;
                    e.l=i;
                    e.r=j;
                    e.nl=0;
                    e.nr=m-1;
                    e.k=k-(j-i+1);
                    e.ans=b[e.level][i][j];
                    solve();
                }
            }
        }
        has[s.k][s.l][s.r][s.nl][s.nr][now]=false;
        if(s.level==-1)
            continue;
        if(s.k>(n-s.level-1)*(s.nr-s.nl+1))
            continue;
        for(i=s.nl;i<=s.nr;i++)
        {
            for(j=i;j<=s.nr;j++)
            {
                if(i<s.nl||j>s.nr||j<s.l||i>s.r)
                    continue;
                e=s;
                e.level++;
                e.l=i;
                e.r=j;
                e.k-=(j-i+1);
                if(i>s.l&&j<s.r)
                {
                    e.nl=i;
                    e.nr=j;
                    e.ans+=b[e.level][i][j];
                }
                else if(i>s.l)
                {
                    e.nl=i;
                    e.nr=s.nr;
                    e.ans+=b[e.level][i][j];
                }
                else if(j<s.r)
                {
                    e.nl=s.nl;
                    e.nr=j;
                    e.ans+=b[e.level][i][j];
                }
                else
                {
                    e.nl=s.nl;
                    e.nr=s.nr;
                    e.ans+=b[e.level][i][j];
                }
                solve();
            }
        }
    }
}
int main()
{
    int i,j;
    while(scanf("%d%d%d",&n,&m,&k)==3)
    {
        ans=0;
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                scanf("%d",&map[i][j]);
                ans+=map[i][j];
            }
        }
        for(i=0;i<n;i++)
        {
            for(x=0;x<m;x++)
            {
                for(y=x;y<m;y++)
                {
                    if(y==x)
                        b[i][x][y]=map[i][x];
                    else
                        b[i][x][y]=b[i][x][y-1]+map[i][y];
                }
            }
        }
        ans=0;
        now=0;
        bfs(-2);
        printf("Oil : %d\n",ans);
    }
    return 0;
}
