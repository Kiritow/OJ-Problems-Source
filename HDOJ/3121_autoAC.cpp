#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define MIN(x,y) (x<y?x:y)
int g,b,p;
int G,B,P;
int gdeg[22];
int grank[22];
int gb[22],gp[22],bp[22];
bool in(){
    char c=getchar();
    while(c<=32) c=getchar();
    return (c=='1');
}
int vis;
int mat[22];
inline bool find0(int u){
    for(int i=0;i<b;i++){
        if(B&(1<<i)) continue;
        if(!(gb[u]&(1<<i))) continue;
        if(vis&(1<<i)) continue;
        vis|=(1<<i);
        if(mat[i]==-1||find0(mat[i])){
            mat[i]=u;
            return true;
        }
    }
    return false;
}
inline bool find1(int u){
    for(int i=0;i<p;i++){
        if(P&(1<<i)) continue;
        if(!(gp[u]&(1<<i))) continue;
        if(vis&(1<<i)) continue;
        vis|=(1<<i);
        if(mat[i]==-1||find1(mat[i])){
            mat[i]=u;
            return true;
        }
    }
    return false;
}
inline bool find2(int u){
    for(int i=0;i<p;i++){
        if(P&(1<<i)) continue;
        if(!(bp[u]&(1<<i))) continue;
        if(vis&(1<<i)) continue;
        vis|=(1<<i);
        if(mat[i]==-1||find2(mat[i])){
            mat[i]=u;
            return true;
        }
    }
    return false;
}
int dep;
inline bool h(int d,int tg){
    int cnt=0;
    memset(mat,-1,sizeof(mat));
    for(int i=tg;i<g;i++){
        vis=0;
        if(find0(grank[i])) cnt++;
        if(cnt>dep-d) break;
    }
    if(cnt+d<dep) return false;
    cnt=0;
    memset(mat,-1,sizeof(mat));
    for(int i=tg;i<g;i++){
        vis=0;
        if(find1(grank[i])) cnt++;
        if(cnt>dep-d) break;
    }
    if(cnt+d<dep) return false;
    cnt=0;
    memset(mat,-1,sizeof(mat));
    for(int i=0;i<b;i++){
        if(B&(1<<i)) continue;
        vis=0;
        if(find2(i)) cnt++;
        if(cnt>dep-d) break;
    }
    if(cnt+d<dep) return false;
    return true;
}
bool dfs(int d,int tg){
    if(d==dep) return true;
    if(!h(d,tg)) return false;
    for(int ii=tg;ii<g;ii++){
        int i=grank[ii];
        G|=(1<<i);
        for(int j=0;j<b;j++){
            if(B&(1<<j)) continue;
            if(!(gb[i]&(1<<j))) continue;
            B|=(1<<j);
            for(int k=0;k<p;k++){
                if(P&(1<<k)) continue;
                if(gp[i]&bp[j]&(1<<k)){
                    P|=(1<<k);
                    if(dfs(d+1,ii+1)) return true;
                    P^=(1<<k);
                }
            }
            B^=(1<<j);
        }
        G^=(1<<i);
    }
    return false;
}
bool gcmp(const int& a,const int& b){
    return gdeg[a]<gdeg[b];
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d%d",&g,&b,&p);
        memset(gb,0,sizeof(gb));
        memset(gp,0,sizeof(gp));
        memset(bp,0,sizeof(bp));
        memset(gdeg,0,sizeof(gdeg));
        for(int i=0;i<g;i++){
            for(int j=0;j<b;j++){
                gb[i]|=(in()<<j);
            }
        }
        for(int i=0;i<g;i++){
            for(int j=0;j<p;j++){
                gp[i]|=(in()<<j);
            }
        }
        for(int i=0;i<b;i++){
            for(int j=0;j<p;j++){
                bp[i]|=(in()<<j);
            }
        }
        for(int i=0;i<g;i++){
            grank[i]=i;
            for(int j=0;j<b;j++){
                if(!(gp[i]&bp[j])) gb[i]&=~(1<<j);
                if(gb[i]&(1<<j)) gdeg[i]++;
            }
        }
        sort(grank,grank+g,gcmp);     
        G=B=P=0;
        dep=MIN(MIN(g,b),p);
        while(true){
            if(dfs(0,0)) break;
            dep--;
        }
        printf("%d\n",dep);
    }
}
