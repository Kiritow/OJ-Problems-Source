#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
using namespace std;
const int maxn = 505;
const int INF = (1<<30)-1;
int g[maxn][maxn];
int lx[maxn],ly[maxn];
int match[maxn];
bool visx[maxn],visy[maxn];
int slack[maxn];
int a[maxn];
int n,m,rn;
bool dfs(int cur){
     visx[cur] = true;
     for(int y=1;y<=rn;y++){
         if(visy[y])   continue;
         int t=lx[cur]+ly[y]-g[cur][y];
         if(t==0){
            visy[y] = true;
            if(match[y]==-1||dfs(match[y])){
                match[y] = cur;
                return true;
            }
         }
         else if(slack[y]>t){
                 slack[y]=t;
         }
     }
     return false;
}
int KM(){
    memset(match,-1,sizeof(match));
    memset(ly,0,sizeof(ly));
    for(int i=1 ;i<=m;i++){
         lx[i]=-INF;
       for(int j=1;j<=rn;j++)
           if(g[i][j]>lx[i])   lx[i]=g[i][j];
    }
    for(int x=1;x<=m;x++){
        for(int i=1;i<=rn;i++)  slack[i]=INF;
        while(true){
            memset(visx,false,sizeof(visx));
            memset(visy,false,sizeof(visy));
            if(dfs(x))  break;
            int d=INF;
            for(int i=1;i<=rn;i++){
               if(!visy[i]&&d>slack[i])     d=slack[i];
            }
            for(int i=1;i<=m;i++){
               if(visx[i])                  lx[i]-=d;
            }
            for(int i=1;i<=rn;i++){
               if(visy[i])                 ly[i]+=d;
               else                        slack[i]-=d;
            }
        }
   }
    int result = 0;
    for(int i = 1; i <= rn; i++){
      if(match[i]>-1){
        result +=  g[match[i]][i];
      }
    }
    return result;
}
int abs(int x){
    if(x<0)return -x;
    return x;
}
int main(){
    int index[maxn];
    while(scanf("%d",&n)!=EOF){             
        if(n==0) break; 
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        int i,j,k;
        m=0;   rn=0;
        for(int i=1;i<=n;i++)  if(!a[i]){
           index[++rn]=i;
        }
        for(int i=1;i<=n;i++)  for(int j=1;j<=n;j++)
           g[i][j]=0;
        for( i=1;i<=n;i++){
            if(a[i]>1){
                for( k=1;k<a[i];k++){
                    m++;
                   for(j=1;j<=rn;j++)
                       g[m][j]=-min(abs(index[j]-i),n-abs(index[j]-i));
                }
            }
        }
        int ans=-KM();
        printf("%d\n",ans);
    }
    return 0;
}
