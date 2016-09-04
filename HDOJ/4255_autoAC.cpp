#include<iostream>
#include<cstring>
#include<cstdio>
#include<queue>
#define N 40400
#define MAX 210
#define CNT 4000
using namespace std;
bool isprime[N];
int prime[CNT],cnt;
int map[MAX][MAX];
bool visited[MAX][MAX];
struct point{int x,y,step;};
void find_prime()
{
    int i,j;
    cnt=0;
    memset(isprime,true,sizeof(isprime));
    isprime[1]=false;
    for(i=2;i<N;i++)
    {
        if(isprime[i])
        {
            prime[cnt++]=i;
            for(j=2*i;j<N;j=j+i) isprime[j]=false;
        }
    }
}
void build_map(int p,int q,int s,int c)
{
    if(s==0) return ;
    int i;
    for(i=q;i<q+c;i++)   map[p][i]=s--;
    for(i=p+1;i<p+c;i++) map[i][q+c-1]=s--;
    for(i=q+c-2;i>q;i--) map[p+c-1][i]=s--;
    for(i=p+c-1;i>p;i--) map[i][q]=s--;
    build_map(p+1,q+1,s,c-2);
}
int t_i,t_j;
void find(int u)
{
    int i,j;
    for(i=1;i<=200;i++)
    {
        for(j=1;j<=200;j++)
        {
            if(u==map[i][j])
            {
                t_i=i;t_j=j;
                return ;
            }
        }
    }
}
int BFS(int u,int v)
{
    find(u);
    point t,tt;
    t.x=t_i;t.y=t_j;t.step=0;
    queue<point>Q;
    while(!Q.empty()) Q.pop();
    Q.push(t);
    visited[t.x][t.y]=true;
    while(!Q.empty())
    {
        t=Q.front();Q.pop();
        if(map[t.x][t.y]==v) return t.step;
        if(t.x-1>=1&&!visited[t.x-1][t.y]&&!isprime[map[t.x-1][t.y]])
        {
            tt.x=t.x-1;tt.y=t.y;tt.step=t.step+1;
            Q.push(tt);
            visited[tt.x][tt.y]=true;
        }
        if(t.x+1<=200&&!visited[t.x+1][t.y]&&!isprime[map[t.x+1][t.y]])
        {
            tt.x=t.x+1;tt.y=t.y;tt.step=t.step+1;
            Q.push(tt);
            visited[tt.x][tt.y]=true;
        }
        if(t.y-1>=1&&!visited[t.x][t.y-1]&&!isprime[map[t.x][t.y-1]])
        {
            tt.x=t.x;tt.y=t.y-1;tt.step=t.step+1;
            Q.push(tt);
            visited[tt.x][tt.y]=true;
        }
        if(t.y+1<=200&&!visited[t.x][t.y+1]&&!isprime[map[t.x][t.y+1]])
        {
            tt.x=t.x;tt.y=t.y+1;tt.step=t.step+1;
            Q.push(tt);
            visited[tt.x][tt.y]=true;
        }
    }
    return 0;
}
int main()
{
    int u,v,k=1;
    memset(map,0,sizeof(map));
    find_prime();
    build_map(1,1,40000,200);
    while(scanf("%d%d",&u,&v)!=EOF)
    {
        memset(visited,false,sizeof(visited));
        int ans;
        ans=BFS(u,v);
        if(ans) printf("Case %d: %d\n",k++,ans);
        else printf("Case %d: impossible\n",k++);
    }
    return 0;
}
