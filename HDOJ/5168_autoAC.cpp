#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <vector>
#define LL __int64
using namespace std;
const LL INF=(LL)0x3f3f3f3f*0x3f3f3f3f;
const int N=100010;
const int M=200020;
struct TEdge{
    int u,v,w;
    bool operator<(const TEdge& a)const {
        if(w<a.w) return true;
        return false;
    }
}Cedge[M];
int tot;
struct Point{
    int lw;
    LL alw;
    Point(int c,LL e){lw=c; alw=e;}
};
vector<Point>point[N];
int n,m,k;
void addedge(int u,int v,int w){
    Cedge[tot].u=u;
    Cedge[tot].v=v;
    Cedge[tot].w=w;
    tot++;
}
void Push_into(int p,Point t){
    point[p].push_back(t);
}
bool cmp(Point a,Point b){
    if(a.lw==b.lw) return a.alw>b.alw;
    return a.lw<b.lw;
}
int main(){
    int T,u,v,w,sz;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d%d",&n,&m,&k);
        tot=0;
        for(int i=1;i<=n;i++){
            point[i].clear();
        }
        for(int i=1;i<=m;i++){
            scanf("%d%d%d",&u,&v,&w);
            addedge(u,v,w);
        }
        sort(Cedge,Cedge+tot);
        for(int i=0;i<tot;i++){
            u=Cedge[i].u;
            v=Cedge[i].v;
            if(u==1){
                if(point[v].empty()){
                    Push_into(v,Point(Cedge[i].w,Cedge[i].w));
                }
                else{
                    if(point[v][point[v].size()-1].alw>Cedge[i].w){
                        Push_into(v,Point(Cedge[i].w,Cedge[i].w));
                    }
                }
                continue;
            }
            if(point[u].empty()) continue;
            else {
                int p=upper_bound(point[u].begin(),point[u].end(),Point(Cedge[i].w-k,-INF),cmp)-point[u].begin();
                if(p==0) continue;
                else if(p>0 && p<point[u].size()) --p;
                else if(point[u][point[u].size()-1].lw<=Cedge[i].w-k) p=point[u].size()-1;
                else continue;
                if(point[v].empty())
                    Push_into(v,Point(Cedge[i].w,point[u][p].alw+(LL)Cedge[i].w));
                else if(point[v][point[v].size()-1].alw>point[u][p].alw+(LL)Cedge[i].w)
                    Push_into(v,Point(Cedge[i].w,point[u][p].alw+(LL)Cedge[i].w));
            }
        }
        if(point[n].empty())
        printf("-1\n");
        else printf("%I64d\n",point[n][point[n].size()-1].alw);
    }
    return 0;
}
