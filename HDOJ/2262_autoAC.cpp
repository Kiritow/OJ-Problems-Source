#include <functional>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <numeric>
#include <cstring>
#include <cassert>
#include <cstdio>
#include <string>
#include <vector>
#include <bitset>
#include <queue>
#include <stack>
#include <cmath>
#include <ctime>
#include <list>
#include <set>
#include <map>
using namespace std;
#define pii pair<int,int>
#define mem(a,b) memset(a,b,sizeof(a))
#define lson l,mid,rt<<1
#define rson mid+1,r,rt<<1|1
#define PI acos(-1.0)
typedef __int64 LL;
typedef unsigned __int64 ULL;
const int N=230;
const int INF=0x3f3f3f3f;
const LL MOD=1000000007,STA=8000010;
const LL LNF=1LL<<55;
const double EPS=1e-9;
const double OO=1e30;
const int dx[4]={-1,0,1,0};
const int dy[4]={0,1,0,-1};
const int day[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
inline int sign(double x){return (x>EPS)-(x<-EPS);}
template<class T> T gcd(T a,T b){return b?gcd(b,a%b):a;}
template<class T> T lcm(T a,T b){return a/gcd(a,b)*b;}
template<class T> inline T lcm(T a,T b,T d){return a/d*b;}
template<class T> inline T Min(T a,T b){return a<b?a:b;}
template<class T> inline T Max(T a,T b){return a>b?a:b;}
template<class T> inline T Min(T a,T b,T c){return min(min(a, b),c);}
template<class T> inline T Max(T a,T b,T c){return max(max(a, b),c);}
template<class T> inline T Min(T a,T b,T c,T d){return min(min(a, b),min(c,d));}
template<class T> inline T Max(T a,T b,T c,T d){return max(max(a, b),max(c,d));}
int vis[20][20],cnt[20][20],e[20][20];
char g[20][20];
int n,m,tot,sx,sy;
double A[N][N];
int gauss(int n)
{
    int i,j,k,r;
    for(i=0;i<n;i++){
        r=i;
        for(j=i+1;j<n;j++)
            if(fabs(A[j][i]) > fabs(A[r][i]))r=j;
        if(r!=i)for(j=0;j<=n;j++)swap(A[r][j],A[i][j]);
        for(j=n;j>=i;j--){   
            for(k=i+1;k<n;k++)
                A[k][j]-=A[k][i]/A[i][i]*A[i][j];
        }
    }
    for(i=0;i<n;i++)if(sign(A[i][i])==0)return 0;
    for(i=n-1;i>=0;i--){
        for(j=i+1;j<n;j++)
            A[i][n]-=A[j][n]*A[i][j];
        A[i][n]/=A[i][i];
    }
    return 1;
}
int bfs()
{
    int i,j,x,y,nx,ny,t;
    queue<int> q;
    q.push(sx*m+sy);
    mem(vis,-1);mem(cnt,0);
    vis[sx][sy]=tot=0;
    tot++;
    while(!q.empty()){
        t=q.front();q.pop();
        x=t/m;y=t%m;
        for(i=0;i<4;i++){
            nx=x+dx[i];
            ny=y+dy[i];
            if(nx>=0&&nx<n && ny>=0&&ny<m && g[nx][ny]!='#'){
                cnt[x][y]++;
                if(vis[nx][ny]!=-1)continue;
                vis[nx][ny]=tot++;
                q.push(nx*m+ny);
            }
        }
    }
    for(i=0;i<n;i++){
        for(j=0;j<m;j++)
            if(vis[i][j]!=-1 && e[i][j])return 1;
    }
    return 0;
}
int main(){
    int i,j,k;
    while(~scanf("%d%d",&n,&m))
    {
        mem(e,0);
        for(i=0;i<n;i++){
            scanf("%s",g[i]);
            for(j=0;j<m;j++){
                if(g[i][j]=='@')sx=i,sy=j;
                else if(g[i][j]=='$')e[i][j]=1;
            }
        }
        if(!bfs()){
            printf("-1\n");
            continue;
        }
        mem(A,0);
        for(i=0;i<n;i++){
            for(j=0;j<m;j++){
                if(vis[i][j]==-1)continue;
                int u=vis[i][j];
                double p=1.0/cnt[i][j];
                if(e[i][j]){
                    A[u][u]=1;
                    A[u][tot]=0;
                    continue;
                }
                A[u][u]=A[u][tot]=1;
                for(k=0;k<4;k++){
                    int x=i+dx[k],y=j+dy[k];
                    if(x>=0&&x<n && y>=0&&y<m && vis[x][y]!=-1){
                        A[u][vis[x][y]]=-p;
                    }
                }
            }
        }
        gauss(tot);
        printf("%.6lf\n",A[vis[sx][sy]][tot]);
    }
    return 0;
}
