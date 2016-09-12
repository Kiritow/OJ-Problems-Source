#include<cstdio>
#include<cstring>
const int maxn=1100;
int T;
int n,m,r;
int vis[maxn];
int main()
{
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        memset(vis,0,sizeof(vis));
        int ans=0;
        for(int i=0;i<n;i++){
            scanf("%d %d",&r,&m);
            vis[r]+=m;
        }
        for(int i=0;i<=500;i++){
            if(vis[i]>0){
                if(vis[i]%64==0){
                    ans+=vis[i]/64;
                }
                else{
                    ans+=vis[i]/64+1;
                }
            }
        }
        if(!ans%36)
            printf("%d\n",ans/36);
        else
            printf("%d\n",ans/36+1);
    }
    return 0;
}
