#include<stdio.h>
#include<string.h>
#include<iostream>
#include<queue>
using namespace std;
const int maxn = 1005;
const int inf = 1<<29;
struct nd{
    int x,y,d,t,id;
};
int has[maxn][maxn][4];
int ans[maxn][maxn][4];
int vis[maxn][maxn][4];
int dx[] = {0,-1,0,1};
int dy[] = {1,0,-1,0};
char as[maxn][maxn],E[10],dd[128];
int N,M,m,mn,cnt;
int si,sj,di,dj;
bool nok(int x,int y){
    if(x<0||y<0||x==N||y==M||as[x][y]=='*')return true;
    return false;
}
void bfs(int x,int y,int d)
{
    nd k,t;
    int a,b,c,i;
    cnt = 0;
    for(a = 0; a < N; ++ a)
        for(b = 0; b < M; ++ b)
            for(c = 0; c < 4; ++ c)
                has[a][b][c]=inf,ans[a][b][c]=0;
    has[x][y][d]=0; ans[x][y][d]=1;
    if(x==di&&y==dj)return;
    queue<nd>que;
    t.x=x;t.y=y;t.d=d;t.t=0; t.id = cnt; vis[x][y][d]=cnt++;
    que.push(t);
    while(!que.empty()){
        t = que.front(); que.pop();
        if(t.id ^ vis[t.x][t.y][t.d])continue;
        for(i = 0; i < 4; ++ i){
            k = t; k.t++; k.d = i;
            k.x += dx[i]; k.y += dy[i];
            if(nok(k.x,k.y))continue;
            if(i^t.d)k.t++;
            if((i+2)%4==t.d)k.t++;
            if(k.t>has[k.x][k.y][k.d]||k.t>mn)continue;
            if(k.t==has[k.x][k.y][k.d]){
                ans[k.x][k.y][k.d] += ans[t.x][t.y][t.d];
                if(ans[k.x][k.y][k.d]>=m)ans[k.x][k.y][k.d]-=m;
                if((i+2)%4==t.d){
                    ans[k.x][k.y][k.d] += ans[t.x][t.y][t.d];
                    if(ans[k.x][k.y][k.d]>=m)ans[k.x][k.y][k.d]-=m;
                }
            }else{
                ans[k.x][k.y][k.d]=ans[t.x][t.y][t.d];
                if((i+2)%4==t.d)ans[k.x][k.y][k.d] += ans[t.x][t.y][t.d];
                if(ans[k.x][k.y][k.d]>=m)ans[k.x][k.y][k.d]-=m;
            }
            has[k.x][k.y][k.d] = k.t;
            if(k.x==di && k.y==dj){
                if(has[k.x][k.y][k.d]<mn)mn=has[k.x][k.y][k.d];
                continue;
            }
            k.id = cnt; vis[k.x][k.y][k.d] = cnt++;
            que.push(k);
        }
        ans[t.x][t.y][t.d]=0;
    }
}
int main()
{
    int cas=0,i,k;
    dd['E']=0;dd['N']=1;dd['W']=2;dd['S']=3;
    while(scanf("%d %d %d",&N,&M,&m)!=EOF){
        if(!m)break;
        for(i = 0; i < N; ++ i)
            scanf("%s",as[i]);
        scanf("%d %d %d %d %s",&si,&sj,&di,&dj,E);
        mn = inf;
        bfs(si,sj,dd[E[0]]);
        k = 0;
        for(i = 0; i < 4; ++ i){
            if(has[di][dj][i]<mn){
                mn = has[di][dj][i];
                k = ans[di][dj][i];
            }else if(has[di][dj][i]==mn){
                k += ans[di][dj][i];
                if(k >= m)k -= m;
            }
        }
        if(mn==inf)printf("Case %d: %d -1\n",++cas,m);
        else printf("Case %d: %d %d\n",++cas,m,k);
    }
    return 0;
}
