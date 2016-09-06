#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
inline int min(int a,int b) { return a<b? a: b ; }
const int maxn =  4000 +10  ;
const int maxm =  4000000 + 10;
struct  TwoSAT {
    int col[maxn],dfn[maxn],low[maxn],s[maxn],cnt,scnt, stop,n;
    int pre[maxm],ad[maxn],v[maxm], tot ;
    void init()
    {
        tot=0 ;
        memset(ad,0,sizeof(ad));
    }
    void add(int x,int y)
    {
        pre[++tot] = ad[x];
        ad[x] = tot ;
        v[tot] = y; 
    }
    void add_clause(int x, int xval, int y, int yval)
    {
        add(x+xval*n,y+(!yval)*n);
        add(y+yval*n,x+(!xval)*n);
    }
    void dfs(int u) {
        dfn[u]=low[u]=++cnt ;
        s[++stop]=u;
        for (int j=ad[u];j;j=pre[j]){
            if (!dfn[v[j]]){
                dfs(v[j]);
                low[u] = min(low[u],low[v[j]]) ;
            }
            else if (!col[v[j]]) 
                low[u] = min(low[u] , dfn[v[j]]); 
        }
        if(low[u]==dfn[u]){
            ++scnt; 
            while(1){
                int x=s[stop--];
                col[x]=scnt; 
                if(x==u)break; 
            }
        }
    }
    bool slove()
    {
        memset(dfn,0,sizeof(dfn));
        memset(col,0,sizeof(col));
        cnt=scnt=stop= 0 ; 
        for (int i=0; i<2*n; ++i)
            if (!dfn[i])
                dfs(i);
        for(int i=0;i<n;++i)
            if (col[i] ==col[i+n])
                return 0;
        return 1;
    }
};
TwoSAT TSAT; 
int b[600][600]; 
int main()
{
    int n ; 
    while (scanf("%d",&n)!=EOF) {
        for (int i=0; i<n; ++i) 
            for (int j=0; j<n; ++j) 
                scanf("%d",&b[i][j]) ; 
        TSAT.n=n;
        int flag = 1; 
        for (int k=0; k<31; ++k) {
            TSAT.init() ; 
            for (int i=0; i<n; ++i) 
                for (int j=i; j<n; ++j)
                if (i==j)
                    continue; 
                else if (i %2 ==1 && j%2 ==1) {
                    if (b[i][j] & (1<<k)){
                        TSAT.add_clause(i,1,j,1);
                    }
                    else{
                        TSAT.add_clause(i,0,i,0);
                        TSAT.add_clause(j,0,j,0);
                    }
                }
                else if (i%2==0 && j%2==0) {
                    if (b[i][j] & (1<<k)){
                        TSAT.add_clause(i,1,i,1);
                        TSAT.add_clause(j,1,j,1);
                    }
                    else {
                        TSAT.add_clause(i,0,j,0);
                    }
                } 
                else {
                    if (b[i][j] & (1<<k)) {
                        TSAT.add_clause(i,0,j,0);
                        TSAT.add_clause(i,1,j,1);
                    }
                    else {
                        TSAT.add_clause(i,0,j,1);
                        TSAT.add_clause(i,1,j,0);
                    }
                }
                flag = TSAT.slove();
            if (!flag) break ; 
        }
        if (flag) puts("YES"); else puts("NO"); 
    }
}
