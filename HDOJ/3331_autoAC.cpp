#include<iostream>
#include<cstring>
#include<cstdio>
#include<set>
#define MAXN 150
using namespace std;
int n,m,ids,ide,ans;
int br[MAXN][MAXN],dist[MAXN];
struct Node{
    int g,y,r;
}node[MAXN];
struct L{
    int  x,t;
    bool operator <(L othr)const{
        if(x==othr.x)return t<othr.t;
        else return x<othr.x;
    }
}now;
void SPFA(){
    set<L>Q;
    Q.clear();
    memset(dist,-1,sizeof(dist));
    Q.insert((L){ids,5});
    dist[ids]=5;
    set<L>::iterator  it;
    while(!Q.empty()){
        it=Q.begin();
        now=*it;
        Q.erase(it); 
        for(int i=0;i<n;i++){
            if(br[now.x][i]==-1)continue;
            int add=0,nowtime,tot,res;
            nowtime=br[now.x][i]+dist[now.x];
            tot=node[i].g+node[i].r+node[i].y;
            res=nowtime%tot;
            if(res>=node[i].g+node[i].y)add=5+tot-res;       
            if(i==ide&&(ans==-1||ans>nowtime))ans=nowtime; 
            if(add+nowtime<dist[i]||dist[i]==-1){
                dist[i]=nowtime+add;
                Q.insert((L){i,dist[i]});   
            }
        }
    }
}
int main(){
    while(scanf("%d%d%d%d",&n,&m,&ids,&ide)!=EOF&&(n||m||ids||ide)){
        if(ids==ide){
            printf("0:00\n");
            continue;
        }
        for(int i=0;i<n;i++){
            scanf("%d%d%d",&node[i].g,&node[i].y,&node[i].r);
        }
        memset(br,-1,sizeof(br));
        for(int i=0;i<m;i++){
            int  xx,yy,zz;
            scanf("%d%d%d",&xx,&yy,&zz);
            if(br[xx][yy]==-1||br[xx][yy]>zz)
            br[xx][yy]=br[yy][xx]=zz;
        }
        ans=-1;
        SPFA();
        int second=ans;
        int minute=second/60;
        second=second%60;
        printf("%d:%02d\n",minute,second);
        }
}
