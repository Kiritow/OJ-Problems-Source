#include<cstring>
#include<cstdio>
#include<cstdlib>
using namespace std;
int const maxn=122;
int n,m;
bool mat[maxn][maxn];
bool vis[maxn];
int mac[maxn];
bool match(int x)
{
    for(int i=1;i<=m;i++)
    {
        if(mat[x][i]&&!vis[i]){
            vis[i]=1;
            if(!mac[i]||match(mac[i])){
                mac[i]=x;
                return 1;
            }
        }
    }
    return 0;
}
int main(){
    int a,b;
    int test;
    scanf("%d",&test);
    while(test--){
         scanf("%d%d",&m,&n);
         memset(mat,0,sizeof(mat));
         memset(mac,0,sizeof(mac));
       for(int i=0;i<n;i++){
         scanf("%d%d",&a,&b);
         mat[a][b]=1;
       }
       int ans=0;
     for(int i=1;i<=m;i++){
         memset(vis,0,sizeof(vis));
         if(match(i))ans++;
     }
      printf("%d\n",m-ans);
    }
  return 0;
}
