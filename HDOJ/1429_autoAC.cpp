#include<cstdio>
#include<cstring>
#include<cctype>
#include<queue>
#define M 21
#define KEY 10
using namespace std;
typedef struct tP{
    int x,y,t,key;
    tP(){}
    tP(int x,int y,int t,int key):x(x),y(y),t(t),key(key){}
}P;
char mat[M][M];
bool mark[1<<KEY][M][M];
int n,m,T;
queue<P>q;
int dir[][2]={{0,1},{0,-1},{1,0},{-1,0}};
int K(char c)
{
    return c-(isupper(c)?'A':'a');
}
int Wall(int x,int y)
{
    if(x<0||x>=n||y<0||y>=m) return true;
    if(mat[x][y]=='*') return true;
    return false;
}
int Bfs(int cx,int cy)
{
    P cur;
    int x,y,t,key,i;
    while(!q.empty()) q.pop();
    memset(mark,false,sizeof(mark));
    mark[0][cx][cy]=true;
    q.push(tP(cx,cy,0,0));
    while(!q.empty()){
        cur=q.front();q.pop();
        if(cur.t>=T) break;//濡娣卞害澶тT锛
        for(i=0;i<4;i++){
            x=cur.x+dir[i][0];
            y=cur.y+dir[i][1];
            t=cur.t+1;key=cur.key;
            if(Wall(x,y)||mark[key][x][y]) continue;
            if(isupper(mat[x][y])&&!(key&(1<<K(mat[x][y])))) continue;
            if(islower(mat[x][y])) key=key|(1<<K(mat[x][y]));
            if(mat[x][y]=='^') return t;
            if(!mark[key][x][y]){
                mark[key][x][y]=true;
                q.push(tP(x,y,t,key));
            }
        }
    }
    return -1;
}
int main()
{
    int i,j,x,y;
    while(scanf("%d%d%d",&n,&m,&T)!=EOF){
        T-=1;
        for(i=0;i<n;i++){
            scanf("%s",mat[i]);
            for(j=0;j<m;j++){
                if(mat[i][j]=='@'){
                    mat[i][j]='.';
                    x=i,y=j;
                }
            }
        }
        printf("%d\n",Bfs(x,y));
    }
    return 0;
}
