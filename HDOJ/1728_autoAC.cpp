#include <iostream>
#include <queue>
#include <cstring>
#define MAXN 100 + 10
using namespace std;
typedef struct{
    int x,y,turn;
}coordinate;
int m,n,k;
queue<coordinate>Q;
coordinate start,goal;
char maze[MAXN][MAXN];
bool vis[MAXN][MAXN];
const int dx[4]={0,0,1,-1},dy[4]={1,-1,0,0};  
void Init(){        
    memset(maze,0,sizeof(maze));
    memset(vis,false,sizeof(vis));
}
bool Judge(int x,int y){        
    if(x<=0||x>m||y<=0||y>n||maze[x][y]=='*')
        return false;
    return true;
}
bool BFS(){
    coordinate now,next;
    while(!Q.empty())      
        Q.pop();
    if(start.x==goal.x&&start.y==goal.y)
        return true;
    Q.push(start);      
    vis[start.x][start.y]=true;
    while(!Q.empty()){
        now = Q.front();
        Q.pop();
        for(int i=0;i<4;i++){
            next.x = now.x + dx[i];
            next.y = now.y + dy[i];         
            while(Judge(next.x,next.y)){    
                if(!vis[next.x][next.y]){
                    next.turn = now.turn + 1;
                    vis[next.x][next.y] = true;
                    Q.push(next);
                    if(next.x==goal.x&&next.y==goal.y&&next.turn<=k)
                        return true;
                }
                next.x += dx[i];
                next.y += dy[i];
            }
        }
    }
    return false;
}
int main(){
    int T;
    cin>>T;
    while(T--){
        cin>>m>>n;
        Init();
        for(int i=1;i<=m;i++)
            for(int j=1;j<=n;j++)
                cin>>maze[i][j];
        cin>>k>>start.y>>start.x>>goal.y>>goal.x;
        start.turn=-1;      
        if(BFS())
            cout<<"yes"<<endl;
        else
            cout<<"no"<<endl;
    }
    return 0;
}
