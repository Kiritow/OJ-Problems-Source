#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <queue>
using namespace std;
const int N = 2000009;
int visit[N];
struct node{
    int a[5];
} re[N];
int ans[N];
int map[4][4];
void makemap(int k)
{
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
        {
            map[i][j]=k%5;
            k/=5;
        }
}
struct quenod{
    int s,step;
};
queue<quenod> que;
bool v[5];
bool oor(int x,int y)
{
    if(x<0||x>2) return false;
    if(y<0||y>2) return false;
    return true;
}
int dx[]={0,0,-1,1};
int dy[]={-1,1,0,0};
bool ok(int x,int y,int n)
{
    memset(v,0,sizeof(v));
    int tx,ty;
    for(int i=0;i<4;i++)
    {
        tx = x+dx[i],ty=y+dy[i];
        if(!oor(tx,ty)) continue;
        v[map[tx][ty]]=true;
    }
    for(int i=1;i<n;i++)
    if(!v[i]) return false;
    return true;
}
int cnt = 1;
int zip[]={1,5,25,125,625,3125,15625,78125,390625,1953125};
void init()
{
    while(!que.empty()) que.pop();
    quenod e,t;
    e.s=0;e.step=0;
    que.push(e);
    visit[0] = true;
    while(!que.empty())
    {
        e = que.front();que.pop();
        makemap(e.s);
        for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
        {
            for(int k=map[i][j]+1;k<5;k++)
            if(ok(i,j,k))
            {
                t.s = e.s+zip[i*3+j]*(k-map[i][j]);
                if(visit[t.s])continue;
                visit[t.s] = true;
                memset(re[cnt].a,0,sizeof(re[cnt].a));
                for(int ii=0;ii<3;ii++)
                for(int jj=0;jj<3;jj++)
                if(map[ii][jj]) re[cnt].a[map[ii][jj]]++;
                re[cnt].a[map[i][j]]--;
                re[cnt].a[k]++;
                t.step=e.step+1;
                ans[cnt]=t.step;
                cnt++;
                que.push(t);
            }
        }
    }
}
int main()
{
    init();
    int a[5],w,sum,T=1;
    while(~scanf("%d",&a[1])&&a[1])
    {
        for(int i=2;i<5;i++)scanf("%d",&a[i]);
        scanf("%d",&w);
        bool ou = false;
        for(int i=0;i<cnt;i++)
        {
            sum=0;
            for(int j=1;j<5;j++)
            sum+=re[i].a[j]*a[j];
            if(sum>=w)
            {
                ou  = true;
                printf("Case %d: %d\n",T++,ans[i]);
                break;
            }
        }
        if(!ou)
        {
            printf("Case %d: Impossible\n",T++);
        }
    }
    return 0;
}
