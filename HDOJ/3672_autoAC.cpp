#include<iostream>
#include<cstdio>
#include<cmath>
#include<string.h>
using namespace std;
#define MAXN 600
#define INF 0x3f3f3f3f
struct Node{
    int v,e;
    Node *next;
}*edge[MAXN],space[MAXN<<1];
int f[MAXN][MAXN][2],C,son[MAXN];
void addedge(int x,int y,int z){
    Node *p=&space[C++];
    p->v=x; p->e=z; p->next=edge[y];
    edge[y]=p;
}
void dfs(int x,int fa){
    f[x][1][0]=0; f[x][1][1]=0;
    son[x]=1;
    for (Node *p=edge[x]; p; p=p->next){
        if (p->v!=fa){
            int y=p->v;
            dfs(y,x);
            son[x]+=son[y];
            for (int i=son[x];i>1;i--)
                for (int j=1;j<=son[y];j++){
                    f[x][i][0]=min(f[x][i][0],f[x][i-j][0]+f[y][j][0]+(p->e)*2);
                    f[x][i][1]=min(f[x][i][1],f[x][i-j][0]+f[y][j][1]+p->e);
                    f[x][i][1]=min(f[x][i][1],f[x][i-j][1]+f[y][j][0]+(p->e)*2);
                }
        }
    }
}
int main(){
    int caseT=0,x,y,z,n,Q,t;
    while (scanf("%d",&n),n){
        C=0;
        for (int i=0;i<=n;i++) edge[i]=NULL;
        for (int i=1;i<n;i++){
            scanf("%d%d%d",&x,&y,&z);
            addedge(x+1,y+1,z); addedge(y+1,x+1,z);
        }
        memset(son,0,sizeof(son));
        for (int i=0;i<=n;i++)
            for (int j=0;j<=n;j++) f[i][j][0]=f[i][j][1]=INF;
        dfs(1,0);
        scanf("%d",&Q);
        printf("Case %d:\n",++caseT);
        for (int i=1;i<=Q;i++){
            scanf("%d",&t);
            int ans=1;
            for (int i=n;i>=1;i--){
                if (f[1][i][0]<=t||f[1][i][1]<=t){
                    ans=i; break;
                }
            }
            printf("%d\n",ans);
        }
    }
    return 0;
}
