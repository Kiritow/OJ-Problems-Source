#include<stdio.h>
#include<string.h>
#include<iostream>
#include<queue> 
using namespace std;
#define MIN(a,b) (a)>(b)?(b):(a) 
const int INF = 0x3f3f3f3f ;
int T ,N ,M , K ,Sr,Sc,Er,Ec;
char maze[55][55] ;
unsigned int MA ;
int dr[4] = {-1, 1, 0, 0} ;
int dc[4] = {0,0,-1,1} ;
int key[51][51] ;
queue<int> que ;
bool in[55][55][1<<5] ;
int dis[55][55][1<<5] ;
bool relax(int r,int c ,int s ,int nr,int nc , int ns, int d){
    if(dis[nr][nc][ns] > dis[r][c][s] + d){
        dis[nr][nc][ns] = dis[r][c][s] + d ;
        return true;
    }
    return false ;
}
void spfa(){
    MA = (1 << K) - 1 ;
    while(!que.empty()) que.pop() ;    
    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++){
            for(int k=0;k<=MA;k++){
                in[i][j][k] = 0 ;
                dis[i][j][k] = INF ;
            }
        }
    }    
    dis[Sr][Sc][0] = 0 ;
    in[Sr][Sc][0] = 1 ;
    que.push(Sr);    que.push(Sc); que.push(0);
    while(!que.empty()){
        int r = que.front() ; que.pop() ;
        int c = que.front() ; que.pop() ;
        int s = que.front() ; que.pop() ;
        in[r][c][s] = 0 ;
        for(int i=0;i<4;i++){
            int nr = r + dr[i] ;
            int nc = c + dc[i] ,ns;
            if(nr<1||nc<1||nr>N||nc>M||maze[nr][nc]=='#')    continue ;
            ns = (s | key[nr][nc]) ;
            if(maze[nr][nc]=='.'){
                if(relax(r,c,s, nr,nc,ns,0) && !in[nr][nc][ns]){
                    in[nr][nc][ns] = 1 ;
                    que.push(nr) ; que.push(nc) ;que.push(ns) ;
                }    
            }
            else if(maze[nr][nc]>='1' && maze[nr][nc]<='9'){
                if(relax(r,c,s, nr,nc,ns , maze[nr][nc]-'0') && !in[nr][nc][ns]){
                    in[nr][nc][ns] = 1 ;
                    que.push(nr) ; que.push(nc) ;que.push(ns) ;
                }
            }
            else{
                int a = maze[nr][nc] - 'A' ;
                if((s&(1<<a)) != 0){            
                    if(relax(r,c,s, nr,nc,ns ,0) && !in[nr][nc][ns]){
                        in[nr][nc][ns] = 1 ;
                        que.push(nr) ; que.push(nc) ;que.push(ns) ;
                    }
                }
            }    
        }
    }
    int ans = INF ;
    for(int i=0;i<=MA;i++){
        if(ans > dis[Er][Ec][i]){
            ans = dis[Er][Ec][i] ;
        }
    }
    if(ans == INF){
        ans = -1 ;
    }
    printf("%d\n",ans);
}
int main(){
    scanf("%d",&T);
    while(T--){
        scanf("%d%d%d",&N,&M,&K);
        for(int i=1;i<=N;i++){
            scanf("%s",maze[i]+1);        
            for(int j=1;j<=M;j++){
                if(maze[i][j]=='S'){
                    Sr = i ; Sc = j ;
                    maze[i][j] = '.' ;
                }
                if(maze[i][j] == 'T'){
                    Er = i ; Ec = j ;
                    maze[i][j] = '.' ;    
                }
            }
        }
        memset(key , 0 ,sizeof(key));
        for(int i=0;i<K;i++){
            int a ,b ;
            scanf("%d %d",&a , &b);
            key[a][b] = (key[a][b] | (1<<i)) ;        
        }
        spfa() ;
    }    
    return 0 ;
}
